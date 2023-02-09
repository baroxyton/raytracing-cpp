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
void renderFrame3D(std::vector<std::vector<Color>> eye1, std::vector<std::vector<Color>> eye2){
    std::cout << "\033[2J\033[1;1H";
    for(int i = 0; i < eye1.size(); i++){
        for(auto character : eye1[i]){
            std::cout << "\033[4" << character << "m   ";
        }
        for(auto character : eye2[i]){
            std::cout << "\033[4" << character << "m   ";
        }
        std::cout << "\033[40m" << std::endl;
    }
}