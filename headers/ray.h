#pragma once

#include "vec3.h"

class ray
{
public:
    // Constructors
    ray() {}
    ray(const Point3 &origin, const vec3 &direction) : orig{origin}, dir{direction} {}

    // Member functions
    const Point3 &origin() const { return orig; }
    const vec3 &direction() const { return dir; }
    Point3 at(double t) const { return (orig + t * dir); }

private:
    Point3 orig{};
    vec3 dir{};
};