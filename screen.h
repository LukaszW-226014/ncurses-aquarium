//
// Created by masterofblocks on 26.04.18.
//

#ifndef NCURSES_AQUARIUM_SCREEN_H
#define NCURSES_AQUARIUM_SCREEN_H

#include <ncurses.h>
#include <stdio.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

class Screen {
private:
    bool ready_;
    int maxx_;
    int maxy_;
    std::mutex m_;
public:
    Screen();
    void init();
    void clean();
    void reload();
    void draw(int x, int y);
    void end();
    int get_maxx();
    int get_maxy();
    void clearPath(int x, int y);
};

#endif //NCURSES_AQUARIUM_SCREEN_H
