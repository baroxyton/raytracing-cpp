#include "camera.h"
#include <math.h>
#include <vector>
void Camera::setAngle(double angle)
{
    viewAngle = angle;
    // we need to get the 2d matrix through which we will be shooting rays through
    /*

                Hypothenouse
                                / |
                            /      |
                        /          | Opposite
                    /   Angle θ= 48 |
    our position   < - - - - - - - -
                    \   adjacent=5|
                        \           |
                            \       |
                                \   |

        We can use half of the angle and then apply sohcahtoa. Our field here would be 2 tan(totalAngle/2). This project only works with <180 degrees
    */
    matrixWidth = 2 * tan(viewAngle / 2 * M_PI / 180);
}
Camera::Camera(std::vector<double> coordinates)
{
    this->coordinates = coordinates;
    target = std::vector<double>{0, 0, 0};
}
