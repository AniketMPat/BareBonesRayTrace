#include "colour.h"

void write_colour(std::ostream &out, colour &pixel_colour) {
    // Convert the [0,1] colour value to [0,255]
    int r = int(255.999 * pixel_colour.x());
    int g = int(255.999 * pixel_colour.y());
    int b = int(255.999 * pixel_colour.z());
    out << r << ' ' << g << ' ' << b << '\n';
}