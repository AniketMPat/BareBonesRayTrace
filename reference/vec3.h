#ifndef VEC3_H
#define VEC3_H

#include "rtweekend.h"

class vec3 {
public:
    // Default 0 and parameterized ructors
    vec3() : v{0, 0, 0} {}
    vec3(double _v1, double _v2, double _v3) : v{_v1, _v2, _v3} {}
    vec3(const vec3 &_rhs) : v{_rhs.v[0], _rhs.v[1], _rhs.v[2]} {}
    vec3(vec3 &_rhs) : v{_rhs.v[0], _rhs.v[1], _rhs.v[2]} {}

    // getters
    double &x();
    double &y();
    double &z();

    double operator[](int i) { return v[i]; }
    double operator[](int i) const { return v[i]; }

    // Turn vec elems negative
    vec3 operator-();

    vec3 &operator+=(vec3 &rhs);
    vec3 &operator-=(vec3 &rhs);
    vec3 &operator+=(double d);
    vec3 &operator-=(double d);
    vec3 &operator*=(double d);
    vec3 &operator/=(double d);

    double length() const;
    double length_squared() const;

    bool near_zero() const;

    static vec3 random();
    static vec3 random(double min, double max);

private:
    double v[3];
};

// Binary operations with vectors and doubles
vec3 operator+(const vec3 &_u, const vec3 &_v);
vec3 operator+(const vec3 &_v, double d);
vec3 operator+(double d, const vec3 &_v);

vec3 operator-(const vec3 _u, const vec3 _v);
vec3 operator-(const vec3 &_v, double d);
vec3 operator-(double d, const vec3 &_v);

vec3 operator*(const vec3 &u, const vec3 &v);
vec3 operator*(const vec3 &_v, double d);
vec3 operator*(double d, const vec3 &_v);

vec3 operator/(const vec3 &_v, double d);

double dot(const vec3 &_u, const vec3 &_v);
vec3 cross(const vec3 &_u, const vec3 &_v);
vec3 unit_vector(const vec3 &_v);
vec3 random_unit_vector();
vec3 random_on_hemisphere(const vec3 &normal);
vec3 reflect(const vec3 &v, const vec3 &n);

// display
std::ostream &operator<<(std::ostream &os, const vec3 &vector3);

#endif