#ifndef COLOR_H
#define COLOR_H

#include "rtweekend.h"
#include "vec3.h"

// type alias for vec3 to colour
// x,y,z represents rgb values
using Colour = Vec3;

inline void writeColor(std::ostream &out, const Colour &pixel_color) {
    // Assign input colour to rgb
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Translate the [0,1] component values to the byte range [0,255].
    int rbyte = int(255.999 * r);
    int gbyte = int(255.999 * g);
    int bbyte = int(255.999 * b);

    // Write out the pixel color components.
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif