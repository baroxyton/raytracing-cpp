#include "camera.h"
#include "render.h"
#include <vector>
int main(){
    Camera testCamera{std::vector<double>{0,0,0}};
    renderFrame(testCamera.getRender());
}