#pragma once

#include "ray.h"

class material;

class hit_record
{
public:
    Point3 p{};
    vec3 normal{};
    shared_ptr<material> mat;
    double t{};
    bool front_face{};

    void set_face_normal(const ray &r, const vec3 &outward_normal)
    {
        // Sets the hit record normal vector
        // NOTE: the parameter `outward_normal` is assumed to have unit length

        front_face = dot(r.direction(), outward_normal) < 0.0;
        normal = front_face ? outward_normal : -1.0 * outward_normal;
    }
};

class hittable
{
public:
    virtual ~hittable() = default;
    virtual bool hit(const ray &r, interval ray_t, hit_record &rec) const = 0;
};