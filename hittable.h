#ifndef HITTABLE_H
#define HITTABLE_H

#include "vec3.h"
#include "ray.h"
#include "interval.h"

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

class hittable {
public:
    // using a virtual destructor for a base class that will be derived
    // more explained here: https://stackoverflow.com/questions/461203/when-to-use-virtual-destructors
    virtual ~hittable() = default;

    virtual bool hit(ray &r, interval ray_t, hitRecord &rec) const = 0;
};

#endif