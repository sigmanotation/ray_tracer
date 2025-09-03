#include "rt.h"
#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "material.h"
#include "sphere.h"

int main()
{
    // World
    hittable_list world{};

    shared_ptr material_ground{make_shared<lambertian>(Color(0.8, 0.8, 0.0))};
    shared_ptr material_center{make_shared<lambertian>(Color(0.1, 0.2, 0.5))};
    shared_ptr material_left{make_shared<dielectric>(1.5)};
    shared_ptr material_bubble{make_shared<dielectric>(1.0 / 1.5)};
    shared_ptr material_right{make_shared<metal>(Color(0.8, 0.6, 0.2))};

    world.add(make_shared<sphere>(Point3(0.0, -100.5, -1.0), 100.0, material_ground));
    world.add(make_shared<sphere>(Point3(0.0, 0.0, -1.2), 0.5, material_center));
    world.add(make_shared<sphere>(Point3(-1.0, 0.0, -1.0), 0.5, material_left));
    world.add(make_shared<sphere>(Point3(-1.0, 0.0, -1.0), 0.4, material_bubble));
    world.add(make_shared<sphere>(Point3(1.0, 0.0, -1.0), 0.5, material_right));

    // Camera
    camera cam{};

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 600;
    cam.samples_per_pixel = 100;
    cam.max_depth = 50;

    cam.vfov = 20;
    cam.lookfrom = Point3(-2.0, 2.0, 1.0);
    cam.lookat = Point3(0.0, 0.0, -1.0);
    cam.vup = vec3(0.0, 1.0, 0.0);

    cam.defocus_angle = 0.0;
    cam.focus_dist = 3.4;

    cam.render(world);
}