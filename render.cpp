#include "render.h"
#include <iostream>
#include <vector>
void renderFrame(std::vector<std::vector<Color>> frame){
    std::cout << "\033[2J\033[1;1H";
    for(auto row : frame){
        for(auto character : row){
            std::cout << "\033[4" << character << "m   ";
        }
        std::cout << "\033[40m" << std::endl;
    }
};