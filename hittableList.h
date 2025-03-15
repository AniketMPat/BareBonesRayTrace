#ifndef HITTABLELIST_H
#define HITTABLELIST_H

#include "hittable.h"

class hittableList : public hittable {
public:
    std::vector<std::shared_ptr<hittable>> objects;

    hittableList() {}
    hittableList(std::shared_ptr<hittable> object) { add(object); }

    void clear() { objects.clear(); }

    void add(std::shared_ptr<hittable> object) {
        objects.push_back(object);
    }

    virtual bool hit(ray &r, interval ray_t, hitRecord &rec) const override {
        hitRecord temp_rec;
        bool hit_anything = false;
        auto closest_so_far = ray_t.max;

        for (const auto &object : objects) {
            if (object->hit(r, interval(ray_t.min, closest_so_far), temp_rec)) {
                hit_anything = true;
                closest_so_far = temp_rec.t;
                rec = temp_rec;
            }
        }

        return hit_anything;
    }
};

#endif