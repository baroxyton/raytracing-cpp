#pragma once
#include <vector>
#include "render.h"
#include "shape.h"
class Camera
{
public:
    std::vector<Shape*> world;
    void lookAt(std::vector<double> target);
    void lookAt(double deg1, double deg2);
    void moveTo(std::vector<double> coords);
    void setResolution(double resolution);
    void setRaySpeed(double speed);
    std::vector<std::vector<Color>> getRender();
    Camera(std::vector<double> coordinates);
    void setAngle(double degrees);
private:
    std::vector<double> coordinates{0,0,0};
    std::vector<double> target{0,0,0};
    std::vector<double> matrixBasisVector{};
    std::vector<double> matrixStart{};
    
    double viewRange = 100;
    double viewAngle = 30;
    double raySpeed = 1;
    double resolution = 150;
    double matrixWidth;
    double pixelSize;
    void calculateMatrix();
};
