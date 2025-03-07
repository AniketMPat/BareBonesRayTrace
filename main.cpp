// #include "colour.h"
// #include "ray.h"
#include "vec3.cpp"
#include "vec3.h"
#include <iostream>

int main() {

    vec3 a = {5, 5, 5};
    vec3 b = {2, 2, 2};
    const double c = 2;

    auto d = a + b;
    auto e = a - b;
    auto f = a * b;
    auto g = a / b;

    a += b;
    a -= b;
    a *= b;
    a /= b;

    vec3 aa(10, 10, 10);
    vec3 bb(aa);

    std::cout << unit_vector(bb) << "\n";
}