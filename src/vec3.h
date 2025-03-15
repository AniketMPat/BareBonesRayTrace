#ifndef VEC3_H
#define VEC3_H

#include "rtweekend.h"

class Vec3 {
public:
    // Default 0 and parameterized ructors
    Vec3() : v{0, 0, 0} {}
    Vec3(double _v1, double _v2, double _v3) : v{_v1, _v2, _v3} {}
    Vec3(const Vec3 &_rhs) : v{_rhs.v[0], _rhs.v[1], _rhs.v[2]} {}
    Vec3(Vec3 &_rhs) : v{_rhs.v[0], _rhs.v[1], _rhs.v[2]} {}

    // getters
    double x() const;
    double y() const;
    double z() const;

    double operator[](int i) { return v[i]; }
    double operator[](int i) const { return v[i]; }

    // Turn vec elems negative
    Vec3 operator-();

    Vec3 &operator+=(Vec3 &rhs);
    Vec3 &operator-=(Vec3 &rhs);
    Vec3 &operator+=(double d);
    Vec3 &operator-=(double d);
    Vec3 &operator*=(double d);
    Vec3 &operator/=(double d);

    double length() const;
    double length_squared() const;

    bool near_zero() const;

    static Vec3 random();
    static Vec3 random(double min, double max);

private:
    double v[3];
};

// Binary operations with vectors and doubles
Vec3 operator+(const Vec3 &_u, const Vec3 &_v);
Vec3 operator+(const Vec3 &_v, double d);
Vec3 operator+(double d, const Vec3 &_v);

Vec3 operator-(const Vec3 _u, const Vec3 _v);
Vec3 operator-(const Vec3 &_v, double d);
Vec3 operator-(double d, const Vec3 &_v);

Vec3 operator*(const Vec3 &u, const Vec3 &v);
Vec3 operator*(const Vec3 &_v, double d);
Vec3 operator*(double d, const Vec3 &_v);

Vec3 operator/(const Vec3 &_v, double d);

double dot(const Vec3 &_u, const Vec3 &_v);
Vec3 cross(const Vec3 &_u, const Vec3 &_v);
Vec3 unit_vector(const Vec3 &_v);
Vec3 random_unit_vector();
Vec3 random_on_hemisphere(const Vec3 &normal);
Vec3 reflect(const Vec3 &v, const Vec3 &n);

// display
std::ostream &operator<<(std::ostream &os, const Vec3 &vector3);

#endif