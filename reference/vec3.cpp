#include "vec3.h"
#include "rtweekend.h"

double &vec3::x() { return this->v[0]; }
double &vec3::y() { return this->v[1]; }
double &vec3::z() { return this->v[2]; }

vec3 vec3::operator-() const {
    return vec3(-v[0], -v[1], -v[2]);
}

vec3 &vec3::operator+=(vec3 &rhs) {
    this->v[0] += rhs.v[0];
    this->v[1] += rhs.v[1];
    this->v[2] += rhs.v[2];
    return *this;
}
vec3 &vec3::operator-=(vec3 &rhs) {
    this->v[0] -= rhs.v[0];
    this->v[1] -= rhs.v[1];
    this->v[2] -= rhs.v[2];
    return *this;
}
vec3 &vec3::operator+=(double d) {
    this->v[0] += d;
    this->v[1] += d;
    this->v[2] += d;
    return *this;
}
vec3 &vec3::operator-=(double d) {
    this->v[0] -= d;
    this->v[1] -= d;
    this->v[2] -= d;
    return *this;
}
vec3 &vec3::operator*=(double d) {
    this->v[0] *= d;
    this->v[1] *= d;
    this->v[2] *= d;
    return *this;
}
vec3 &vec3::operator/=(double d) {
    this->v[0] /= d;
    this->v[1] /= d;
    this->v[2] /= d;
    return *this;
}

double vec3::length() const {
    return sqrt(this->length_squared());
}
double vec3::length_squared() const {
    return (this->v[0] * this->v[0]) + (this->v[1] * this->v[1]) + (this->v[2] * this->v[2]);
}

bool vec3::near_zero() const {
    // Return true if the vector is close to zero in all dimensions.
    auto s = 1e-8;
    return (std::fabs(v[0]) < s) && (std::fabs(v[1]) < s) && (std::fabs(v[2]) < s);
}

vec3 vec3::random() {
    return vec3(random_double(), random_double(), random_double());
}

vec3 vec3::random(double min, double max) {
    return vec3(random_double(min, max), random_double(min, max), random_double(min, max));
}

vec3 operator+(const vec3 &_u, const vec3 &_v) {
    return vec3(_u[0] + _v[0], _u[1] + _v[1], _u[2] + _v[2]);
}
vec3 operator+(double d, const vec3 &_v) {
    return vec3(_v[0] + d, _v[1] + d, _v[2] + d);
}
vec3 operator+(const vec3 &_v, double d) {
    return d + _v;
}

vec3 operator-(const vec3 _u, const vec3 _v) {
    return vec3(_u[0] - _v[0], _u[1] - _v[1], _u[2] - _v[2]);
}
vec3 operator-(const vec3 &_v, double d) {
    return vec3(_v[0] - d, _v[1] - d, _v[2] - d);
}
vec3 operator-(double d, const vec3 _v) {
    return _v - d;
}

vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3(u[0] * v[0], u[1] * v[1], u[2] * v[2]);
}
vec3 operator*(const vec3 &_v, double d) {
    return vec3(_v[0] * d, _v[1] * d, _v[2] * d);
}
vec3 operator*(double d, const vec3 &_v) {
    return _v * d;
}

vec3 operator/(const vec3 &_v, double d) {
    return vec3(_v[0] / d, _v[1] / d, _v[2] / d);
}

double dot(const vec3 &_u, const vec3 &_v) {
    return (_u[0] * _v[0]) + (_u[1] * _v[1]) + (_u[2] * _v[2]);
}
vec3 cross(const vec3 &_u, const vec3 &_v) {
    return vec3(_u[1] * _v[2] - _u[2] * _v[1],
                _u[2] * _v[0] - _u[0] * _v[2],
                _u[0] * _v[1] - _u[1] * _v[0]);
}
vec3 unit_vector(const vec3 &_v) {
    return _v / _v.length();
}
vec3 random_in_unit_disk() {
    while (true) {
        auto p = vec3(random_double(-1, 1), random_double(-1, 1), 0);
        if (p.length_squared() < 1)
            return p;
    }
}
vec3 random_unit_vector() {
    while (true) {
        auto p = vec3::random(-1, 1);
        auto lensq = p.length_squared();
        if (1e-160 < lensq && lensq <= 1) {
            return p / sqrt(lensq);
        }
    }
}
vec3 random_on_hemisphere(const vec3 &normal) {
    vec3 on_unit_sphere = random_unit_vector();
    if (dot(on_unit_sphere, normal) > 0.0) // In the same hemisphere as the normal
        return on_unit_sphere;
    else
        return -on_unit_sphere;
}
vec3 reflect(const vec3 &v, const vec3 &n) {
    return v - 2 * dot(v, n) * n;
}
vec3 refract(const vec3 &uv, const vec3 &n, double etai_over_etat) {
    auto cos_theta = std::fmin(dot(-uv, n), 1.0);
    vec3 r_out_perp = etai_over_etat * (uv + cos_theta * n);
    vec3 r_out_parallel = -std::sqrt(std::fabs(1.0 - r_out_perp.length_squared())) * n;
    return r_out_perp + r_out_parallel;
}

std::ostream &operator<<(std::ostream &os, const vec3 &_v) {
    return os << _v[0] << " " << _v[1] << " " << _v[2] << "\n";
}