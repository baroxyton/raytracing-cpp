#include "camera.h"
#include "render.h"
#include "shape.h"
#include <vector>
int main(){
    Rectangle* testShape = new Rectangle{std::vector<double>{10,5,0}, 5, 5, 5};
    Sphere* testSphere = new Sphere{std::vector<double>{10, 2, 0}, 2};
    Camera testCamera{std::vector<double>{0,10,0}};
    testCamera.world.push_back(testShape);
    testCamera.world.push_back(testSphere);
    double speedLeft = 0.05;
    int i = 0;
    while(true){
        testSphere->center[0] -= 0.01;
        i++;
        testSphere->center[2] += speedLeft;
        testSphere->center[1] += speedLeft * 0.1;
        if(i==100){
            i=0;
            speedLeft *= -1;
        }
        renderFrame(testCamera.getRender());
    }
}