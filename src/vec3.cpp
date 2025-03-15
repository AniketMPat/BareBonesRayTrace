#include "vec3.h"
#include "rtweekend.h"

double Vec3::x() const { return this->v[0]; }
double Vec3::y() const { return this->v[1]; }
double Vec3::z() const { return this->v[2]; }

Vec3 Vec3::operator-() {
    return Vec3(-this->v[0], -this->v[1], -this->v[2]);
}

Vec3 &Vec3::operator+=(Vec3 &rhs) {
    this->v[0] += rhs.v[0];
    this->v[1] += rhs.v[1];
    this->v[2] += rhs.v[2];
    return *this;
}
Vec3 &Vec3::operator-=(Vec3 &rhs) {
    this->v[0] -= rhs.v[0];
    this->v[1] -= rhs.v[1];
    this->v[2] -= rhs.v[2];
    return *this;
}
Vec3 &Vec3::operator+=(double d) {
    this->v[0] += d;
    this->v[1] += d;
    this->v[2] += d;
    return *this;
}
Vec3 &Vec3::operator-=(double d) {
    this->v[0] -= d;
    this->v[1] -= d;
    this->v[2] -= d;
    return *this;
}
Vec3 &Vec3::operator*=(double d) {
    this->v[0] *= d;
    this->v[1] *= d;
    this->v[2] *= d;
    return *this;
}
Vec3 &Vec3::operator/=(double d) {
    this->v[0] /= d;
    this->v[1] /= d;
    this->v[2] /= d;
    return *this;
}

double Vec3::length() const {
    return sqrt(this->length_squared());
}
double Vec3::length_squared() const {
    return (this->v[0] * this->v[0]) + (this->v[1] * this->v[1]) + (this->v[2] * this->v[2]);
}

bool Vec3::near_zero() const {
    // Return true if the vector is close to zero in all dimensions.
    auto s = 1e-8;
    return (std::fabs(v[0]) < s) && (std::fabs(v[1]) < s) && (std::fabs(v[2]) < s);
}

Vec3 Vec3::random() {
    return Vec3(random_double(), random_double(), random_double());
}

Vec3 Vec3::random(double min, double max) {
    return Vec3(random_double(min, max), random_double(min, max), random_double(min, max));
}

Vec3 operator+(const Vec3 &_u, const Vec3 &_v) {
    return Vec3(_u[0] + _v[0], _u[1] + _v[1], _u[2] + _v[2]);
}
Vec3 operator+(double d, const Vec3 &_v) {
    return Vec3(_v[0] + d, _v[1] + d, _v[2] + d);
}
Vec3 operator+(const Vec3 &_v, double d) {
    return d + _v;
}

Vec3 operator-(const Vec3 _u, const Vec3 _v) {
    return Vec3(_u[0] - _v[0], _u[1] - _v[1], _u[2] - _v[2]);
}
Vec3 operator-(const Vec3 &_v, double d) {
    return Vec3(_v[0] - d, _v[1] - d, _v[2] - d);
}
Vec3 operator-(double d, const Vec3 _v) {
    return _v - d;
}

Vec3 operator*(const Vec3 &u, const Vec3 &v) {
    return Vec3(u[0] * v[0], u[1] * v[1], u[2] * v[2]);
}
Vec3 operator*(const Vec3 &_v, double d) {
    return Vec3(_v[0] * d, _v[1] * d, _v[2] * d);
}
Vec3 operator*(double d, const Vec3 &_v) {
    return _v * d;
}

Vec3 operator/(const Vec3 &_v, double d) {
    return Vec3(_v[0] / d, _v[1] / d, _v[2] / d);
}

double dot(const Vec3 &_u, const Vec3 &_v) {
    return (_u[0] * _v[0]) + (_u[1] * _v[1]) + (_u[2] * _v[2]);
}
Vec3 cross(const Vec3 &_u, const Vec3 &_v) {
    return Vec3(_u[1] * _v[2] - _u[2] * _v[1],
                _u[2] * _v[0] - _u[0] * _v[2],
                _u[0] * _v[1] - _u[1] * _v[0]);
}
Vec3 unit_vector(const Vec3 &_v) {
    return _v / _v.length();
}
Vec3 random_unit_vector() {
    while (true) {
        auto p = Vec3::random(-1, 1);
        auto lensq = p.length_squared();
        if (1e-160 < lensq && lensq <= 1) {
            return p / sqrt(lensq);
        }
    }
}
Vec3 random_on_hemisphere(const Vec3 &normal) {
    Vec3 on_unit_sphere = random_unit_vector();
    if (dot(on_unit_sphere, normal) > 0.0) // In the same hemisphere as the normal
        return on_unit_sphere;
    else
        return -on_unit_sphere;
}
Vec3 reflect(const Vec3 &v, const Vec3 &n) {
    return v - 2 * dot(v, n) * n;
}

std::ostream &operator<<(std::ostream &os, const Vec3 &_v) {
    return os << _v[0] << " " << _v[1] << " " << _v[2] << "\n";
}