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
void renderFrame(std::vector<std::vector<Color>>);