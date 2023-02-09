#pragma once
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
void renderFrame(std::vector<std::vector<Color>> frame);
void renderFrame3D(std::vector<std::vector<Color>> eye1, std::vector<std::vector<Color>> eye2);