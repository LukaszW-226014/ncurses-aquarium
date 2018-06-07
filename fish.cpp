//
// Created by masterofblocks on 25.03.18.
//

#include "fish.h"

short Fish::global = 0;

Fish::Fish(short color, short sx, short sy, short dx, short dy) {
    global++;
    this->number = global;
    this->color = color;
    this->sx = sx;
    this->sy = sy;
    this->dx = dx;
    this->dy = dy;
}

Fish::~Fish() {

}

void Fish::way(Screen &s, int sx, int sy, int dx, int dy)
{
    int x = sx, y = sy;
    int next_x = 0;
    int next_y = 0;
    int direction_x = dx;
    int direction_y = dy;

    int max_x = s.get_maxx();
    int max_y = s.get_maxy();
    int counter = 0;

    Aquarium::m.lock();
    attron(A_BOLD);
    if (has_colors() == TRUE) {
        start_color();
        init_pair(getNumber(), getColor(), COLOR_BLACK);
        attron(COLOR_PAIR(getNumber()));
        printw("Fish %d\n", getNumber());
        attroff(COLOR_PAIR(getNumber()));
    }
    attroff(A_BOLD);
    Aquarium::m.unlock();

    while(counter<100) {
        Aquarium::m.lock();
        attron(COLOR_PAIR(getNumber()));
        s.draw(x, y);
        attroff(COLOR_PAIR(getNumber()));

        std::this_thread::sleep_for(std::chrono::milliseconds(200));

        next_x = x + direction_x;
        next_y = y + direction_y;

        if (next_x >= max_x || next_x < 0) {
            direction_x*= -1;
        } else {
            x+= direction_x;
        }
        if (next_y >= max_y || next_y < 0) {
            direction_y*= -1;
        } else {
            y+= direction_y;
        }
        counter++;
        s.reload();
        Aquarium::m.unlock();
    }

}

void Fish::operator()() {
    //std::this_thread::sleep_for(std::chrono::seconds(2));

    way(Aquarium::screen1, sx, sy, dx, dy);

    //Aquarium::m.unlock();
}

short Fish::getNumber() const {
    return number;
}

short Fish::getColor() const {
    return color;
}
