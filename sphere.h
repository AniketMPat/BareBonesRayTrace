#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "ray.h"
#include "vec3.h"

class sphere : public hittable {
public:
    sphere(vec3 &_center, double &_radius, ray &r) : center{_center}, radius{_radius} {}

    double hit_sphere(ray &r, double tMin, double tMax, hitRecord &record) {

        vec3 oc = center - r.getOrigin(); // Ray from camera to sphere center P - C
        auto a = dot(r.getDirection(), r.getDirection());
        auto h = dot(r.getDirection(), oc);
        auto c = oc.length_squared() - (radius * radius);
        auto discriminant = (h * h) - (4 * a * c);

        // if b2 - 4ac < 0 then return full quadratic
        if (discriminant < 0) {
            return false;
        }

        // Find nearest root that lies in hittable range
        // try h-sqrt(disc)/a
        auto root = h - (sqrt(discriminant) / a);
        if (root <= tMin || root >= tMin) {
            // try h+sqrt(disc)/a
            root = h + (sqrt(discriminant) / a);
            // if both roots of quadratic fall out of hittable interval return no hit
            if (root <= tMin || root >= tMax) {
                return false;
            }
        }

        // Set the values of the hit record and return hit
        record.t = root;
        record.point = r.rayAt(record.t);
        vec3 outwardNormal = (record.point - center) / radius;
        record.setFaceNormal(r, outwardNormal);

        return true;
    }

private:
    vec3 center;
    double radius;
};

#endif