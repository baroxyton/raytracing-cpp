#include "camera.h"
#include <math.h>
#include <vector>
#include "vectorOps.h"
#include "ray.h"
#include "shape.h"
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
void Camera::calculateMatrix()
{
    // Find the basis vector that points to the centre of our matrix. It is found using vector subtraction followed by normalization

    std::vector<double> toMatrixCentre = vectorOps::getUnitVector(vectorOps::vectorSubtraction(coordinates, target));

    // Next we need to find the vector that is perpendicular to our toMatrixCentre vector, and paralel to the xz-plane
    // https://gamedev.https://f47792e3-004c-46df.gradio.live/file=/tmp/Big%20sistere2723125327d809a5111952e993054736e589233.jsonstackexchange.com/questions/70075/how-can-i-find-the-perpendicular-to-a-2d-vector
    /*
                x=5,z=0
            -------------
            |
            |
            |
            | x=0, z=5
    */
    matrixBasisVector = vectorOps::getUnitVector(std::vector<double>{-toMatrixCentre[2], 0, toMatrixCentre[0]});
    std::vector<double> matrixCentreCoords = vectorOps::vectorAddition(coordinates, toMatrixCentre);

    // Subtract half the matrix width
    matrixStart = vectorOps::vectorSubtraction(matrixCentreCoords, vectorOps::scalarMultiplication(matrixBasisVector, matrixWidth / 2));
    // Subtract half the matrix height
    matrixStart = vectorOps::vectorSubtraction(matrixStart, std::vector<double>{0, matrixWidth / 2, 0});

    pixelSize = matrixWidth / resolution;
    // std::cout << matrixBasisVector[0] << " " << matrixBasisVector[2] << std::endl;
}
std::vector<std::vector<Color>> Camera::getRender()
{
    std::vector<std::vector<Color>> output;
    for (int j = 0; j < resolution; j++)
    {
        std::vector<Color> row;
        for (int i = 0; i < resolution; i++)
        {
            std::vector<double> xzpixelOffset = vectorOps::scalarMultiplication(matrixBasisVector, pixelSize * i);
            std::vector<double> pixelOffset{xzpixelOffset[0] + pixelSize / 2, pixelSize * j + pixelSize / 2, xzpixelOffset[2] + pixelSize / 2};
            std::vector<double> pixelPos = vectorOps::vectorAddition(matrixStart, pixelOffset);

            std::vector<double> rayUnitVector = vectorOps::getUnitVector(vectorOps::vectorSubtraction(coordinates, pixelPos));
            Ray pixelRay{20, coordinates, rayUnitVector, &world, raySpeed};
            row.push_back(pixelRay.output);
        }
        output.push_back(row);
    }
    return output;
}
void Camera::setRaySpeed(double raySpeed)
{
    this->raySpeed = raySpeed;
}
void Camera::setResolution(double resolution)
{
    this->resolution = resolution;
    calculateMatrix();
}
void Camera::lookAt(std::vector<double> target)
{
    this->target = target;
    calculateMatrix();
}
void Camera::lookAt(double deg1, double deg2)
{
    /*
    Spherical (r,θ,ϕ) → Cartesian (x,y,z)
    x=r sin ϕ cos θ
    y=r sin ϕ sin θ
    z=r cos ϕ

    r=1
    theta = deg1
    phi = deg2
    */

    double theta = deg2 * M_PI / 180;
    double phi = deg1 * M_PI / 180;
    double x = sin(theta) * cos(phi);
    double y = sin(theta) * sin(phi);
    double z = cos(theta);
    // For we use coordinates typical for video games, we switch the z and y coordinates
    lookAt(std::vector<double>{x, z, y});
}
void Camera::moveTo(std::vector<double> coordinates)
{
    this->coordinates = coordinates;
    calculateMatrix();
}
Camera::Camera(std::vector<double> coordinates)
{
    setAngle(90);
    moveTo(coordinates);
    lookAt(0, 90);
    calculateMatrix();
}
