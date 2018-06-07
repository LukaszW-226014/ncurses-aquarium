//
// Created by masterofblocks on 25.03.18.
//

#ifndef NCURSES_AQUARIUM_AQUARIUM_H
#define NCURSES_AQUARIUM_AQUARIUM_H

#include <ncurses.h>
#include <stdio.h>
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include "fish.h"
#include "screen.h"

class Aquarium {
private:
    int height;
    int width;
    //std::vector <Fish> fishList;
public:
    Aquarium();
    ~Aquarium();
    void start();
    void generateFishes();
    static std::mutex m;
    static Screen screen1;
};

#endif //NCURSES_AQUARIUM_AQUARIUM_H
