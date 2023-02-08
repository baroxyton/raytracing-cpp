#include "camera.h"
#include "render.h"
#include "shape.h"
#include <vector>
int main(){
    Rectangle* testShape = new Rectangle{std::vector<double>{10,5,5}, 5, 5, 5};
    Camera testCamera{std::vector<double>{0,0,0}};
    testCamera.world.push_back(testShape);
    while(true){
        testShape->center[0] -= 0.1;
        renderFrame(testCamera.getRender());
    }
}