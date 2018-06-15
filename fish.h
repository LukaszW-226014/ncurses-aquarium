//
// Created by masterofblocks on 25.03.18.
//

#ifndef NCURSES_AQUARIUM_FISH_H
#define NCURSES_AQUARIUM_FISH_H

#include <ncurses.h>
#include <stdio.h>
#include "stdlib.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include "screen.h"

class Fish {
private:
    int height;
    int width;
    short number;
    short color;
    short sx;
    short sy;
    short dx;
    short dy;
    short currentX;
    short currentY;
    short currentDX;
    short currentDY;
    int next_x;
    int next_y;
    int previous_x;
    int previous_y;
    //std::mutex mtx;
public:
    static std::list<Fish> fishList;
    short getColor() const;
    short getNumber() const;
    static short global;
    Fish(short color, short sx, short sy, short dx, short dy);
    ~Fish();
    void operator()();
    void way(Screen &s, short sx, short sy, short dx, short dy);
    void checkCollision(const Fish& F);
};

#endif //NCURSES_AQUARIUM_FISH_H
