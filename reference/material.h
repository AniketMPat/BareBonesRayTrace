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

class dielectric : public material {
public:
    dielectric(double refraction_index) : refraction_index(refraction_index) {}

    bool scatter(ray &r_in, hitRecord &rec, colour &attenuation, ray &scattered)
        const override {
        attenuation = colour(1.0, 1.0, 1.0);
        double ri = rec.frontFace ? (1.0 / refraction_index) : refraction_index;

        vec3 unit_direction = unit_vector(r_in.getDirection());

        double cos_theta = std::fmin(dot(-unit_direction, rec.pointNormal), 1.0);
        double sin_theta = std::sqrt(1.0 - cos_theta * cos_theta);

        bool cannot_refract = ri * sin_theta > 1.0;
        vec3 direction;

        if (cannot_refract || reflectance(cos_theta, ri) > random_double())
            direction = reflect(unit_direction, rec.pointNormal);
        else
            direction = refract(unit_direction, rec.pointNormal, ri);

        scattered = ray(rec.point, direction);

        return true;
    }

private:
    // Refractive index in vacuum or air, or the ratio of the material's refractive index over
    // the refractive index of the enclosing media
    double refraction_index;

    static double reflectance(double cosine, double refraction_index) {
        // Use Schlick's approximation for reflectance.
        auto r0 = (1 - refraction_index) / (1 + refraction_index);
        r0 = r0 * r0;
        return r0 + (1 - r0) * std::pow((1 - cosine), 5);
    }
};

#endif