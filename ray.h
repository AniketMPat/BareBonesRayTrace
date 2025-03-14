#ifndef RAY_H
#define RAY_H

class ray {
public:
    ray() {}
    ray(vec3 &_origin, vec3 &_direction) : origin(_origin), direction(_direction) {}

    vec3 getOrigin();
    vec3 getDirection();
    vec3 rayAt(double t);

private:
    vec3 origin, direction;
};

#endif