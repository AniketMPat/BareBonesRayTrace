#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
public:
    // Constructors
    ray() {
        orig = {0, 0, 0};
        dir = {0, 0, 0};
    }
    ray(const point3 &_origin, const vec3 &_direction) : orig(_origin), dir(_direction) {}

    // Getters
    const point3 &origin() const { return orig; }
    const vec3 &direction() const { return dir; }

    // Return the value of a ray
    point3 at(double t) const {
        return orig + (dir * t);
    }

private:
    point3 orig;
    vec3 dir;
};

#endif