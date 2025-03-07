#include "vec3.h"

double &vec3::x() const {
    return *this->v[0];
}
double &vec3::y() const {
    return *this->v[1];
}
double &vec3::z() const {
    return *this->v[2];
}

// double dot(const vec3 &u, const vec3 &v) {
//     return u[0] * v[0] + u[1] * v[1] + u[2] * v[2];
// }

// vec3 cross(const vec3 &u, const vec3 &v) {
//     return vec3(u[1] * v[2] - u[2] * v[1],
//                 u[2] * v[0] - u[0] * v[2],
//                 u[0] * v[1] - u[1] * v[0]);
// }
// vec3 unit_vector(const vec3 &v) {
//     double len = v.length();
//     return v / len;
// }