#pragma once
#include <vector>
#include "render.h"
class Ray
{
public:
    Ray(double reach, std::vector<double> coords, std::vector<double> moveVector, double speed);
    Color getOutput();
    Color output;

private:
    double reach = 1;
    double speed = 1;
    std::vector<double> moveVector;
    std::vector<double> coords;
};