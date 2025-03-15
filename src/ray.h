#ifndef RAY_H
#define RAY_H

#include "rtweekend.h"
#include "vec3.h"

class Ray {
public:
    // Constructors
    Ray() {}
    Ray(const Vec3 &_origin, Vec3 &_direction) : origin(_origin), direction(_direction) {}

    // Member funcitons
    Vec3 &getOrigin() { return origin; }
    Vec3 &getDirection() { return direction; }

    Vec3 rayAt(const double &_t) {
        return origin + (_t * direction);
    }

private:
    // Private members
    Vec3 origin;
    Vec3 direction;
    double t;
};

#endif