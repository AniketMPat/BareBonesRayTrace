#include "rtweekend.h"
#include "vec3.h"
#include "sphere.h"
#include "hittableList.h"
#include "camera.h"

int main() {

    hittableList world;

    world.add(make_shared<sphere>(vec3(0, 0, -1), 0.5));
    world.add(make_shared<sphere>(vec3(0, -100.5, -1), 100));

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 550;
    cam.samples_per_pixel = 100;

    cam.render(world);
}