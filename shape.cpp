#include "shape.h"
#include <vector>
bool Rectangle::doesIntersect(std::vector<double> coords)
    {
        double xMin = center[0] - width / 2;
        double xMax = center[0] + width / 2;
        double yMin = center[1] - height / 2;
        double yMax = center[1] + height / 2;
        double zMin = center[2] - length / 2;
        double zMax = center[2] + length / 2;

        return coords[0] >= xMin && coords[0] <= xMax &&
               coords[1] >= yMin && coords[1] <= yMax &&
               coords[2] >= zMin && coords[2] <= zMax;
    }