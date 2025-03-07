#ifndef VEC3_H
#define VEC3_H
#include <cmath>
#include <iostream>

class vec3 {
public:
    // Default 0 and parameterized constructors
    vec3() {}
    vec3(double _v1, double _v2, double _v3) : v{_v1, _v2, _v3} {}
    vec3(vec3 &_rhs) : v{_rhs[0], _rhs[1], _rhs[2]} {}
    vec3(const vec3 &_rhs) : v{_rhs[0], _rhs[1], _rhs[2]} {}

    // getters
    double &x();
    double &y();
    double &z();

    const double &operator[](const int i) const;
    double &operator[](const int i);

    // Turn vec elems negative
    vec3 &operator-();
    // Basic Vec operations
    vec3 &operator+(const vec3 &rhs);
    vec3 &operator-(const vec3 &rhs);
    vec3 &operator*(const vec3 &rhs);
    vec3 &operator/(const vec3 &rhs);
    // Operations with double
    vec3 &operator+(const double &rhs);
    vec3 &operator-(const double &rhs);
    vec3 &operator*(const double &rhs);
    vec3 &operator/(const double &rhs);
    // Assiciativity with vec3 + double to double + vec3
    friend vec3 operator-(const double &lhs, vec3 &rhs);
    friend vec3 operator+(const double &lhs, vec3 &rhs);
    friend vec3 operator*(const double &lhs, vec3 &rhs);
    friend vec3 operator/(const double &lhs, vec3 &rhs);

    vec3 &operator+=(const vec3 &rhs);
    vec3 &operator-=(const vec3 &rhs);
    vec3 &operator*=(const vec3 &rhs);
    vec3 &operator/=(const vec3 &rhs);
    vec3 &operator+=(const double d);
    vec3 &operator-=(const double d);
    vec3 &operator*=(const double d);
    vec3 &operator/=(const double d);

    // Vector operations

    double length();
    double length_squared();

private:
    double v[3];
};

double dot(const vec3 &u, const vec3 &v);
vec3 cross(const vec3 &u, const vec3 &v);
vec3 unit_vector(vec3 &v);

std::ostream &operator<<(std::ostream &os, const vec3 &vector3);

#endif