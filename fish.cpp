//
// Created by masterofblocks on 25.03.18.
//

#include "aquarium.h"
#include "fish.h"

short Fish::global = 0;

 std::list<Fish> Fish::fishList;

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



void Fish::way(Screen &s, short sx, short sy, short dx, short dy)
{
    currentX = sx;
    currentY = sy;
    next_x = 0;
    next_y = 0;
    previous_x = 0;
    previous_y = 0;

    currentDX = dx;
    currentDY = dy;

    int max_x = s.get_maxx();
    int max_y = s.get_maxy();
    int counter = 0;

    Aquarium::m.lock();
    attron(A_BOLD);
    if (has_colors() == TRUE) {
        //start_color();
        init_pair(getNumber(), getColor(), COLOR_BLUE);
        attron(COLOR_PAIR(getNumber()));
        printw("Fish %d\n", getNumber());
        attroff(COLOR_PAIR(getNumber()));
    }
    attroff(A_BOLD);
    Aquarium::m.unlock();

    while(true) {
        Aquarium::m.lock();
        attron(COLOR_PAIR(getNumber()));
        s.draw(currentX, currentY);
        s.clearPath(previous_x, previous_y);
        attroff(COLOR_PAIR(getNumber()));

        next_x = currentX + currentDX;
        next_y = currentY + currentDY;
        previous_x = currentX;
        previous_y = currentY;

        if (next_x >= max_x || next_x < 0) {
            currentDX*= -1;
        } else {
            currentX+= currentDX;
        }
        if (next_y >= max_y || next_y < 0) {
            currentDY*= -1;
        } else {
            currentY+= currentDY;
        }
        for (auto& f: fishList){
            if ((next_x == f.currentX) && (next_y == f.currentY) && (getNumber() != f.getNumber())){
                std::cerr << "(" << getNumber() << ", " << f.getNumber() << ")\n";
                currentDX*= -1;
                currentDY*= -1;
                currentX+=currentDX;
                currentY+=currentDY;
            }
        }
        //printw("(%d %d)\n", currentX, currentY);
        counter++;
        s.reload();
        Aquarium::m.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
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

void Fish::checkCollision(const Fish &F) {

}
