#include "render.h"
#include <iostream>
#include <vector>
enum Color : unsigned int{
    gray,
    lightred,
    lightgreen,
    yellow,
    blue,
    pink,
    lightblue,
    white,
    lightgray

};
void renderFrame(std::vector<std::vector<Color>> frame){
    std::cout << "\033[2J\033[1;1H";
    for(auto row : frame){
        for(auto character : row){
            std::cout << "\033[3" << character << "m■";
        }
        std::cout << std::endl;
    }
}
int main(){
renderFrame(std::vector<std::vector<Color>>{std::vector<Color>{Color::lightred, Color::lightred},std::vector<Color>{Color::lightred, Color::lightblue}});
};