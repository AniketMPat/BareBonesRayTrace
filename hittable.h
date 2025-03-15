#ifndef HITTABLE_H
#define HITTABLE_H

#include "vec3.h"
#include "ray.h"
#include "interval.h"

/*
Class to record vector values of where ray hits an object
point: vector where ray has collided with object
pointNormal: The normal vector for hit object and incoming ray
t: parameterized t for ray eqn, point = rayOrigin + t*rayDirection
frontFace: weather we want normal vector to face outwards form object or inwards
*/
class hitRecord {
public:
    vec3 point;
    vec3 pointNormal;
    double t;
    bool frontFace;

    void setFaceNormal(ray &r, vec3 &outwardNormal) {
        // Sets the hit record normal vector.
        // NOTE: the parameter `outward_normal` is assumed to have unit length.

        frontFace = dot(r.getDirection(), outwardNormal) < 0;
        pointNormal = frontFace ? outwardNormal : -outwardNormal;
    }
};

/*
Class to classify an object that can be hit by rays
*/
class hittable {
public:
    // using a virtual destructor for a base class that will be derived
    // more explained here: https://stackoverflow.com/questions/461203/when-to-use-virtual-destructors
    virtual ~hittable() = default;

    virtual bool hit(ray &r, interval ray_t, hitRecord &rec) const = 0;
};

#endif