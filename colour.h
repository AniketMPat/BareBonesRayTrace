#ifndef COLOUR_H
#define COLOUR_H

#include "vec3.h"
#include <iostream>

// Type alias for vec3
using color = vec3;

inline void write_color(std::ostream &out, const color &pixel_color) {
    // Convert the [0,1] colour value to [0,255]
    int r = int(255.999 * pixel_color.x());
    int g = int(255.999 * pixel_color.y());
    int b = int(255.999 * pixel_color.z());
    out << r << ' ' << g << ' ' << b << '\n';
}

#endif