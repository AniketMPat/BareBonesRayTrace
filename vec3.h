#ifndef VEC3_H
#define VEC3_H
#include <cmath>
#include <iostream>

class vec3 {
public:
    // x,y,z coordinates
    double v[3];

    // Default 0 and parameterized constructors
    vec3() : v{0, 0, 0} {}
    vec3(double _v1, double _v2, double _v3) : v{_v1, _v2, _v3} {}

    double x() const { return v[0]; }
    double y() const { return v[1]; }
    double z() const { return v[2]; }

    double operator[](const int i) const { return v[i]; }
    double &operator[](const int i) { return v[i]; }

    // Basic Vec operations
    vec3 operator-() { return {-v[0], -v[1], -v[2]}; }
    vec3 operator+(const vec3 &_v) const {
        return {v[0] + _v[0], v[1] + _v[1], v[2] + _v[2]};
    }
    vec3 operator-(const vec3 &_v) const {
        return {v[0] - _v[0], v[1] - _v[1], v[2] - _v[2]};
    }
    vec3 operator*(const vec3 &_v) const {
        return {v[0] * _v[0], v[1] * _v[1], v[2] * _v[2]};
    }
    vec3 operator/(const vec3 &_v) const {
        if (_v[0] != 0 && _v[1] != 0 && _v[2] != 0) {
            return {v[0] / _v[0], v[1] / _v[1], v[2] / _v[2]};
        }
        return vec3(0, 0, 0);
    }
    vec3 operator/(const double d) const {
        if (d != 0) {
            return vec3(v[0] / d, v[1] / d, v[2] / d);
        }
        return vec3(0, 0, 0);
    }

    vec3 operator+=(double d) {
        v[0] += d;
        v[1] += d;
        v[2] += d;
        return *this;
    }
    vec3 operator+=(const vec3 &_v) {
        v[0] += _v[0];
        v[1] += _v[1];
        v[2] += _v[2];
        return *this;
    }
    vec3 operator-=(double d) {
        v[0] -= d;
        v[1] -= d;
        v[2] -= d;
        return *this;
    }
    vec3 operator-=(const vec3 &_v) {
        v[0] -= _v[0];
        v[1] -= _v[1];
        v[2] -= _v[2];
        return *this;
    }
    vec3 operator*=(double d) {
        v[0] *= d;
        v[1] *= d;
        v[2] *= d;
        return *this;
    }
    vec3 operator*=(const vec3 &_v) {
        v[0] *= _v[0];
        v[1] *= _v[1];
        v[2] *= _v[2];
        return *this;
    }
    vec3 operator/=(double d) {
        if (d == 0) {
            return *this;
        }
        v[0] /= d;
        v[1] /= d;
        v[2] /= d;
        return *this;
    }

    // Vector operations

    double length() const {
        return std::sqrt(length_squared());
    }

    double length_squared() const {
        return (v[0] * v[0]) + (v[1] * v[1]) + (v[2] * v[2]);
    }

    double dot(const vec3 &u, const vec3 &v) {
        return u[0] * v[0] + u[1] * v[1] + u[2] * v[2];
    }

    vec3 cross(const vec3 &u, const vec3 &v) {
        return vec3(u[1] * v[2] - u[2] * v[1],
                    u[2] * v[0] - u[0] * v[2],
                    u[0] * v[1] - u[1] * v[0]);
    }

    vec3 unit_vector(const vec3 &v) {
        double len = v.length();
        return v / len;
    }
};

#endif