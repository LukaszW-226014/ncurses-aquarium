//
// Created by masterofblocks on 26.04.18.
//
#include "screen.h"

Screen::Screen():
        ready_(false),
        maxx_(0),
        maxy_(0)
{
}

void Screen::init()
{
    initscr();
    noecho();
    curs_set(FALSE);
    getmaxyx(stdscr, maxy_, maxx_);
    //mutex
    ready_ = true;
}

void Screen::clean()
{
    clear();
}

void Screen::reload()
{
    refresh();
}

void Screen::draw(int x, int y)
{
    //mutex
    //if (ready_)
    mvprintw(y, x, "o");
}

void Screen::end()
{
    endwin();
}

int Screen::get_maxx()
{
    //mutex
    //if (ready_)
    return maxx_;
}

int Screen::get_maxy()
{
    //mutex
    //if (ready_)
    return maxy_;
}
