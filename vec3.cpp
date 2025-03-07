#include "vec3.h"

double &vec3::x() {
    return this->v[0];
}
double &vec3::y() {
    return this->v[1];
}
double &vec3::z() {
    return this->v[2];
}

const double &vec3::operator[](const int i) const {
    return this->v[i];
}
double &vec3::operator[](const int i) {
    return this->v[i];
}

vec3 &vec3::operator-(const vec3 &rhs) {
    this->v[0] -= rhs.v[0];
    this->v[1] -= rhs.v[1];
    this->v[2] -= rhs.v[2];
    return *this;
}
vec3 &vec3::operator-() {
    this->v[0] = -this->v[0];
    this->v[1] = -this->v[1];
    this->v[2] = -this->v[2];
    return *this;
}
vec3 &vec3::operator+(const vec3 &rhs) {
    this->v[0] += rhs.v[0];
    this->v[1] += rhs.v[1];
    this->v[2] += rhs.v[2];
    return *this;
}
vec3 &vec3::operator*(const vec3 &rhs) {
    this->v[0] *= rhs.v[0];
    this->v[1] *= rhs.v[1];
    this->v[2] *= rhs.v[2];
    return *this;
}
vec3 &vec3::operator/(const vec3 &rhs) {
    if (rhs.v[0] == 0 || rhs.v[1] == 0 || rhs.v[2] == 0) {
        exit(1);
    }
    this->v[0] /= rhs.v[0];
    this->v[1] /= rhs.v[1];
    this->v[2] /= rhs.v[2];
    return *this;
}

vec3 &vec3::operator+(const double &rhs) {
    this->v[0] += rhs;
    this->v[1] += rhs;
    this->v[2] += rhs;
    return *this;
}
vec3 &vec3::operator-(const double &rhs) {
    this->v[0] -= rhs;
    this->v[1] -= rhs;
    this->v[2] -= rhs;
    return *this;
}
vec3 &vec3::operator*(const double &rhs) {
    this->v[0] *= rhs;
    this->v[1] *= rhs;
    this->v[2] *= rhs;
    return *this;
}
vec3 &vec3::operator/(const double &rhs) {
    if (rhs == 0) {
        exit(1);
    }
    this->v[0] /= rhs;
    this->v[1] /= rhs;
    this->v[2] /= rhs;
    return *this;
}

vec3 operator-(const double &lhs, vec3 &rhs) {
    rhs -= lhs;
    return rhs;
}
vec3 operator+(const double &lhs, vec3 &rhs) {
    rhs += lhs;
    return rhs;
}
vec3 operator*(const double &lhs, vec3 &rhs) {
    rhs *= lhs;
    return rhs;
}
vec3 operator/(const double &lhs, vec3 &rhs) {
    if (lhs == 0) {
        exit(1);
    }
    rhs /= lhs;
    return rhs;
}

vec3 &vec3::operator+=(const vec3 &rhs) {
    this->v[0] += rhs[0];
    this->v[1] += rhs[1];
    this->v[2] += rhs[2];
    return *this;
}
vec3 &vec3::operator-=(const vec3 &rhs) {
    this->v[0] -= rhs[0];
    this->v[1] -= rhs[1];
    this->v[2] -= rhs[2];
    return *this;
}
vec3 &vec3::operator*=(const vec3 &rhs) {
    this->v[0] *= rhs[0];
    this->v[1] *= rhs[1];
    this->v[2] *= rhs[2];
    return *this;
}
vec3 &vec3::operator/=(const vec3 &rhs) {
    if (rhs.v[0] == 0 || rhs.v[1] == 0 || rhs.v[2] == 0) {
        exit(1);
    }
    this->v[0] /= rhs[0];
    this->v[1] /= rhs[1];
    this->v[2] /= rhs[2];
    return *this;
}
vec3 &vec3::operator+=(const double d) {
    this->v[0] += d;
    this->v[1] += d;
    this->v[2] += d;
    return *this;
}
vec3 &vec3::operator-=(const double d) {
    this->v[0] -= d;
    this->v[1] -= d;
    this->v[2] -= d;
    return *this;
}
vec3 &vec3::operator*=(const double d) {
    this->v[0] *= d;
    this->v[1] *= d;
    this->v[2] *= d;
    return *this;
}
vec3 &vec3::operator/=(const double d) {
    if (d == 0) {
        exit(1);
    }
    this->v[0] /= d;
    this->v[1] /= d;
    this->v[2] /= d;
    return *this;
}

double vec3::length() {
    return sqrt(this->length_squared());
}

double vec3::length_squared() {
    return (this->v[0] * this->v[0]) + (this->v[1] * this->v[1]) + (this->v[2] * this->v[2]);
}

double dot(const vec3 &u, const vec3 &v) {
    return u[0] * v[0] + u[1] * v[1] + u[2] * v[2];
}

vec3 cross(const vec3 &u, const vec3 &v) {
    double x = u[1] * v[2] - u[2] * v[1];
    double y = u[2] * v[0] - u[0] * v[2];
    double z = u[0] * v[1] - u[1] * v[0];
    vec3 res(x, y, x);
    return res;
}

vec3 unit_vector(vec3 &v) {
    // const double len = v.length();
    return v / v.length();
}

std::ostream &operator<<(std::ostream &os, const vec3 &v) {
    os << '{' << v[0] << ',' << v[1] << ',' << v[2] << '}';
    return os;
}