//
// Created by masterofblocks on 25.03.18.
//

#ifndef NCURSES_AQUARIUM_AQUARIUM_H
#define NCURSES_AQUARIUM_AQUARIUM_H

#include <ncurses.h>
#include <stdio.h>
#include <iostream>
#include <thread>
#include <list>
#include <mutex>
#include <time.h>
#include "screen.h"
#include "fish.h"



class Aquarium {
private:
    int height;
    int width;
    int fishCount;
    int randomValue;

public:
    std::list<std::thread> threadList;
    Aquarium();
    Aquarium(int fishCount);
    ~Aquarium();
    void start();
    void generateFishes();
    static std::mutex m;
    static Screen screen1;
};

#endif //NCURSES_AQUARIUM_AQUARIUM_H
