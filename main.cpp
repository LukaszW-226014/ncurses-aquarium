#include "aquarium.h"


int main()
{
    int fishCount;
    std::cout << "Podaj liczbe ryb: ";
    std::cin >> fishCount;
    new Aquarium(fishCount);
}