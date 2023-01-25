#include "vectorOps.h"
#include <math.h>
double vectorOps::dotProduct(std::vector<double> vector1, std::vector<double> vector2)
{
    double result;
    for (int i = 0; i < vector1.size(); i++)
    {
    }
}
std::vector<double> vectorOps::crossProduct(std::vector<double> vector1, std::vector<double> vector2)
{
    double i = (vector1[1] * vector2[2]) - (vector1[2] * vector2[1]);
    double j = (vector1[2] * vector2[0]) - (vector1[0] * vector2[2]);
    double k = (vector1[0] * vector2[1]) - (vector1[1] * vector2[0]);
    return std::vector<double>{i, j, k};
}
std::vector<double> vectorOps::getUnitVector(std::vector<double> inputVector)
{
    // \frac{(a, b, c)}{a^2 + b^2 + c^2}
    double magnitude = sqrt(pow(inputVector[0], 2) + pow(inputVector[1], 2) + pow(inputVector[2], 2));

    return std::vector<double>{inputVector[0] / magnitude, inputVector[1] / magnitude, inputVector[2] / magnitude};
}