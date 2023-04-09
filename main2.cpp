#include "camera.h"
#include "render.h"
#include "shape.h"
#include <vector>
// Example with rotating camera and a sphere moving towards the camera and a cube
int main(){
    Rectangle* testShape = new Rectangle{std::vector<double>{10,5,0}, 5, 5, 5};
    Sphere* testSphere = new Sphere{std::vector<double>{10, 2, 0}, 2};
    Camera testCamera{std::vector<double>{0,0,0}};
    testCamera.world.push_back(testShape);
    testCamera.world.push_back(testSphere);
    double speedLeft = 0.05;
    int i = 0;
    double angleLeft = 0;
    while(true){
        angleLeft += 3;
	testCamera.lookAt(angleLeft, 90);
        testSphere->center[0] -= 0.05;
        i++;
        testSphere->center[2] += speedLeft * 2;
        testSphere->center[1] += speedLeft * 0.5;
        if(i==100){
            i=0;
            speedLeft *= -1;
        }
        renderFrame(testCamera.getRender());
    }
    
}
