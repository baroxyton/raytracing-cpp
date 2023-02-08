#include "shape.h"
#include <vector>
#include <cmath>
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
bool Sphere::doesIntersect(std::vector<double> coords){
    double x0 = coords[0];
    double y0 = coords[1];
    double z0 = coords[2];
    double xc = center[0];
    double yc = center[1];
    double zc = center[2];
    double dx = x0 - xc;
    double dy = y0 - yc;
    double dz = z0 - zc;
    double distance = std::sqrt(dx*dx + dy*dy + dz*dz);
    return distance < radius;
}