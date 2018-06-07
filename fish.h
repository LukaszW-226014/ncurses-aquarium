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
#include "aquarium.h"
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
    //std::mutex mtx;
public:
    short getColor() const;
    short getNumber() const;
    static short global;
    Fish(short color, short sx, short sy, short dx, short dy);
    ~Fish();
    void operator()();
    void way(Screen &s, int sx, int sy, int dx, int dy);
};

#endif //NCURSES_AQUARIUM_FISH_H
