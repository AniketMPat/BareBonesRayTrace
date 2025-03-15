#ifndef SPHERE_H
#define SPHERE_H

#include "vec3.h"
#include "ray.h"
#include "hittable.h"

class sphere : public hittable {
public:
    sphere(const vec3 &center, double radius) : center(center), radius(std::fmax(0, radius)) {}

    bool hit(ray &r, double ray_tmin, double ray_tmax, hitRecord &rec) const override {
        vec3 oc = center - r.getOrigin();
        auto a = r.getDirection().length_squared();
        auto h = dot(r.getDirection(), oc);
        auto c = oc.length_squared() - radius * radius;

        auto discriminant = h * h - a * c;
        if (discriminant < 0)
            return false;

        auto sqrtd = std::sqrt(discriminant);

        // Find the nearest root that lies in the acceptable range.
        auto root = (h - sqrtd) / a;
        if (root <= ray_tmin || ray_tmax <= root) {
            root = (h + sqrtd) / a;
            if (root <= ray_tmin || ray_tmax <= root)
                return false;
        }

        rec.t = root;
        rec.point = r.rayAt(rec.t);
        rec.pointNormal = (rec.point - center) / radius;

        return true;
    }

private:
    vec3 center;
    double radius;
};

#endif