#include "ray.h"

vec3 ray::getOrigin() {
    return this->origin;
}
vec3 ray::getDirection() {
    return this->direction;
}

vec3 ray::rayAt(double t) {
    return this->origin + (this->direction * t);
}