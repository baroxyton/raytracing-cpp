#include "ray.h"
#include "render.h"
#include "vectorOps.h"

Ray::Ray(double reach, std::vector<double> coords, std::vector<double> moveVector, double speed=1){
    this->reach = reach;
    this->coords = coords;
    this->moveVector = moveVector;
    this->speed=speed;

    getOutput();
}
Color Ray::getOutput(){
    for(int dist = 0; dist < reach; dist += speed){
        coords = vectorOps::vectorAddition(coords, vectorOps::scalarMultiplication(moveVector, speed));
        //std::cout << moveVector[0] << " " << moveVector[1] << " " << moveVector[2] << std::endl;
        if(coords[1] < 0){
            output = Color::blue;
             return Color::blue;
        }
    }
    output = Color::white;
    return Color::white;
}