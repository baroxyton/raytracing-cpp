#include "ray.h"
#include "render.h"
#include "vectorOps.h"
#include "shape.h"

Ray::Ray(double reach, std::vector<double> coords, std::vector<double> moveVector, std::vector<Shape*>* world, double speed=1){
    this->reach = reach;
    this->coords = coords;
    this->moveVector = moveVector;
    this->speed=speed;
    this->world = world;

    getOutput();
}
Color Ray::getOutput(){
    for(double dist = 0; dist < reach; dist += speed){
        coords = vectorOps::vectorAddition(coords, vectorOps::scalarMultiplication(moveVector, speed));
        //std::cout << moveVector[0] << " " << moveVector[1] << " " << moveVector[2] << std::endl;
        if(coords[1] < 0){
            output = Color::blue;
             return Color::blue;
        }
        for(int i = 0; i < world->size(); i++){
            if((*world)[i]->doesIntersect(coords)){
                output = Color::lightgreen;
                return Color::lightgreen;
            }
        }
    }
    output = Color::white;
    return Color::white;
}