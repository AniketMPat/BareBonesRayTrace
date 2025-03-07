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
    ray(const vec3 &_origin, const vec3 &_direction) : orig(_origin), dir(_direction) {}

    // Getters
    const vec3 &origin() const;
    const vec3 &direction() const;

    // Return the value of a ray
    vec3 at(double t);

private:
    vec3 orig;
    vec3 dir;
};
#endif