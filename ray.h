#pragma once
#include <vector>
#include "render.h"
#include "shape.h"
class Ray
{
public:
    Ray(double reach, std::vector<double> coords, std::vector<double> moveVector, std::vector<Shape*>* world, double speed);
    Color getOutput();
    Color output;

private:
    std::vector<Shape*>* world;
    double reach = 1;
    double speed = 1;
    std::vector<double> moveVector;
    std::vector<double> coords;
};