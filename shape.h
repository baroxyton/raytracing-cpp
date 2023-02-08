#pragma once
#include <vector>
#include "render.h"
class Shape
{
public:
    virtual bool doesIntersect(std::vector<double> coords) = 0;
    // virtual Color getColor(std::vector<double> coords) = 0;

private:
};
class Rectangle : public Shape
{
public:
    bool doesIntersect(std::vector<double> coords);
    Rectangle(std::vector<double> center, double width, double height, double length)
        : center(center), width(width), height(height), length(length){};
    std::vector<double> center;
    double width;
    double height;
    double length;
};
class Sphere : public Shape
{
    public:
    bool doesIntersect(std::vector<double> coords);
    Sphere(std::vector<double> center, double radius): center(center), radius(radius){};
    std::vector<double> center;
    double radius;
};