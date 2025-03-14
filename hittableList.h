#ifndef HITTABLELIST_H
#define HITTABLELIST_H

#include "hittable.h"
#include "rtweekend.h"
#include <vector>

class hittableList : public hittable {
public:
    std::vector<std::shared_ptr<hittable>> objects;

    hittableList() {}
    hittableList(std::shared_ptr<hittable> object) { add(object); }

    void clear() { objects.clear(); }

    void add(std::shared_ptr<hittable> object) {
        objects.push_back(object);
    }

    bool hit(ray &r, double ray_tmin, double ray_tmax, hitRecord &rec) const override {
        hitRecord temp_rec;
        bool hit_anything = false;
        auto closest_so_far = ray_tmax;

        for (const auto &object : objects) {
            if (object->hit(r, ray_tmin, closest_so_far, temp_rec)) {
                hit_anything = true;
                closest_so_far = temp_rec.t;
                rec = temp_rec;
            }
        }

        return hit_anything;
    }
};

#endif