//
// Created by masterofblocks on 25.03.18.
//

#include "aquarium.h"
#include "screen.h"

std::mutex Aquarium::m;

Screen Aquarium::screen1;

Aquarium::Aquarium() {
    start();
}

Aquarium::~Aquarium() {

}

void Aquarium::start() {
    screen1.init();

    screen1.reload();
    generateFishes();

    screen1.reload();
    getch();
    screen1.end();
}

void Aquarium::generateFishes() {

//    Fish fish1(COLOR_YELLOW, 5, 6, 1, -1);
//    //fishList.emplace_back(COLOR_GREEN);
//    std::thread fish1Thread(fish1);
//
//    Fish fish2(COLOR_RED, 10, 15, -1, 1);
//    //fishList.push_back(fish2);
//    std::thread fish2Thread(fish2);
//
//    Fish fish3(COLOR_CYAN, 20, 20, 1, -1);
//    //fishList.push_back(fish3);
//    std::thread fish3Thread(fish3);
//
//    Fish fish4(COLOR_WHITE, 15, 5, -1, 1);
//    std::thread fish4Thread(fish4);
//
//    fish1Thread.join();
//    fish2Thread.join();
//    fish3Thread.join();
//    fish4Thread.join();



    Fish::fishList.emplace_back(COLOR_YELLOW, 5, 6, 1, -1);

    Fish::fishList.emplace_back(COLOR_RED, 10, 15, -1, 1);

    Fish::fishList.emplace_back(COLOR_CYAN, 20, 20, 1, -1);

    Fish::fishList.emplace_back(COLOR_WHITE, 15, 5, -1, 1);

    Fish::fishList.emplace_back(COLOR_MAGENTA, 17, 7, -1, 1);

    Fish::fishList.emplace_back(COLOR_BLACK, 4, 8, -1, 1);

    for (auto& f: Fish::fishList){
        threadList.emplace_back(std::ref(f));
    }

    for (auto& t: threadList){
        t.join();
    }
}

