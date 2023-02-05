#include "render.h"
#include <iostream>
#include <vector>
void renderFrame(std::vector<std::vector<Color>> frame){
    std::cout << "\033[2J\033[1;1H";
    for(auto row : frame){
        for(auto character : row){
            std::cout << "\033[3" << character << "m■";
        }
        std::cout << std::endl;
    }
};