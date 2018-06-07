cmake_minimum_required(VERSION 3.9)
project(ncurses_aquarium)

set(CMAKE_CXX_STANDARD 17)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(ncurses_aquarium main.cpp aquarium.h aquarium.cpp fish.h fish.cpp screen.h screen.cpp)
target_link_libraries(ncurses_aquarium Threads::Threads)
target_link_libraries(ncurses_aquarium ${CURSES_LIBRARIES})

