#ifndef VEC3_H
#define VEC3_H
#include <cmath>
#include <iostream>

class vec3 {
public:
    // Default 0 and parameterized constructors
    vec3() {}
    vec3(double _v1, double _v2, double _v3) {}

    vec3(vec3 &_rhs) : v{_rhs[0], _rhs[1], _rhs[2]} {}

    // getters
    double &x() const;
    double &y() const;
    double &z() const;

    double &operator[](const int i) const;
    double &operator[](const int i);

    // Basic Vec operations
    vec3 &operator-(); // Turn vec elems negative
    friend vec3 &operator-(vec3 lhs, const vec3 &rhs);
    friend vec3 &operator-(vec3 lhs, const double &rhs);
    friend vec3 &operator+(vec3 lhs, const vec3 &rhs);
    friend vec3 &operator+(vec3 lhs, const double &rhs);
    friend vec3 &operator*(vec3 lhs, const vec3 &rhs);
    friend vec3 &operator*(vec3 lhs, const double &rhs);
    friend vec3 &operator/(vec3 lhs, const vec3 &rhs);
    friend vec3 &operator/(vec3 lhs, const double &rhs);

    vec3 &operator+=(const double d);
    vec3 &operator+=(const vec3 &_v);
    vec3 &operator-=(const double d);
    vec3 &operator-=(const vec3 &_v);
    vec3 &operator*=(const double d);
    vec3 &operator*=(const vec3 &_v);
    vec3 &operator/=(const vec3 &_v);
    vec3 &operator/=(const double d);

    // Vector operations

    double length() const;
    double length_squared() const;

private:
    double v[3];
};

double dot(const vec3 &u, const vec3 &v);
vec3 cross(const vec3 &u, const vec3 &v);
vec3 unit_vector(const vec3 &v);

#endif