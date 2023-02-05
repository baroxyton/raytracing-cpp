#include "ray.h"
#include "render.h"
Ray::Ray(double reach, std::vector<double> coords, std::vector<double> moveVector, double speed=1){
    this->reach = reach;
    this->coords = coords;
    this->moveVector = moveVector;
    this->speed=speed;

    getOutput();
}
Color Ray::getOutput(){
    output = Color::blue;
    return Color::blue;
}