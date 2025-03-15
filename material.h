#ifndef MATERIAL_H
#define MATERIAL_H

#include "hittable.h"
#include "colour.h"

class material {
public:
    virtual ~material() = default;

    virtual bool scatter(ray &r_in, hitRecord &rec, colour &attenuation, ray &scattered) const {
        return false;
    }
};

class lambertian : public material {
public:
    lambertian(const colour &albedo) : albedo(albedo) {}

    bool scatter(ray &r_in, hitRecord &rec, colour &attenuation, ray &scattered)
        const override {
        auto scatter_direction = rec.pointNormal + random_unit_vector();

        // Catch degenerate scatter direction
        if (scatter_direction.near_zero()) {
            scatter_direction = rec.pointNormal;
        }

        scattered = ray(rec.point, scatter_direction);
        attenuation = albedo;
        return true;
    }

private:
    colour albedo;
};

class metal : public material {
public:
    metal(const colour &albedo, double fuzz) : albedo(albedo), fuzz(fuzz < 1 ? fuzz : 1) {}

    bool scatter(ray &r_in, hitRecord &rec, colour &attenuation, ray &scattered)
        const override {
        vec3 reflected = reflect(r_in.getDirection(), rec.pointNormal);
        reflected = unit_vector(reflected) + (fuzz * random_unit_vector());
        scattered = ray(rec.point, reflected);
        attenuation = albedo;
        return (dot(scattered.getDirection(), rec.pointNormal) > 0);
    }

private:
    colour albedo;
    double fuzz;
};

#endif