#pragma once
#include <vector>
#include "render.h"
#include "shape.h"
class Camera
{
public:
    std::vector<Shape*> world;
    void lookAt(double x, double y, double z);
    void lookAt(double deg1, double deg2);
    std::vector<std::vector<Color>> getRender();
    Camera(std::vector<double> coordinates);
    void setAngle(double degrees);
private:
    std::vector<double> coordinates;
    std::vector<double> target;
    std::vector<double> matrixBasisVector;
    std::vector<double> matrixStart;
    
    double viewRange = 100;
    double viewAngle = 30;
    double raySpeed = 1;
    double resolution = 100;
    double matrixWidth;
    double pixelSize;
    void calculateMatrix();
};