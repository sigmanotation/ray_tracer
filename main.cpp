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

    auto ground_material = make_shared<lambertian>(Color(0.5, 0.5, 0.5));
    world.add(make_shared<sphere>(Point3(0, -1000, 0), 1000, ground_material));

    for (int a = -11; a < 11; a++)
    {
        for (int b = -11; b < 11; b++)
        {
            auto choose_mat = random_double();
            Point3 center(a + 0.9 * random_double(), 0.2, b + 0.9 * random_double());

            if ((center - Point3(4, 0.2, 0)).length() > 0.9)
            {
                shared_ptr<material> sphere_material;

                if (choose_mat < 0.8)
                {
                    // diffuse
                    auto albedo = Color::random() * Color::random();
                    sphere_material = make_shared<lambertian>(albedo);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                }
                else if (choose_mat < 0.95)
                {
                    // metal
                    auto albedo = Color::random(0.5, 1);
                    auto fuzz = random_double(0, 0.5);
                    sphere_material = make_shared<metal>(albedo);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                }
                else
                {
                    // glass
                    sphere_material = make_shared<dielectric>(1.5);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                }
            }
        }
    }

    shared_ptr material1{make_shared<dielectric>(1.5)};
    world.add(make_shared<sphere>(Point3(0, 1, 0), 1.0, material1));

    shared_ptr material2{make_shared<lambertian>(Color(0.4, 0.2, 0.1))};
    world.add(make_shared<sphere>(Point3(-4, 1, 0), 1.0, material2));

    shared_ptr material3{make_shared<metal>(Color(0.7, 0.6, 0.5))};
    world.add(make_shared<sphere>(Point3(4, 1, 0), 1.0, material3));

    // shared_ptr material_ground{make_shared<lambertian>(Color(0.8, 0.8, 0.0))};
    // shared_ptr material_center{make_shared<lambertian>(Color(0.1, 0.2, 0.5))};
    // shared_ptr material_left{make_shared<dielectric>(1.5)};
    // shared_ptr material_bubble{make_shared<dielectric>(1.0 / 1.5)};
    // shared_ptr material_right{make_shared<metal>(Color(0.8, 0.6, 0.2))};

    // world.add(make_shared<sphere>(Point3(0.0, -100.5, -1.0), 100.0, material_ground));
    // world.add(make_shared<sphere>(Point3(0.0, 0.0, -1.2), 0.5, material_center));
    // world.add(make_shared<sphere>(Point3(-1.0, 0.0, -1.0), 0.5, material_left));
    // world.add(make_shared<sphere>(Point3(-1.0, 0.0, -1.0), 0.4, material_bubble));
    // world.add(make_shared<sphere>(Point3(1.0, 0.0, -1.0), 0.5, material_right));

    // Camera
    camera cam{};

    // cam.aspect_ratio = 16.0 / 9.0;
    // cam.image_width = 400;
    // cam.samples_per_pixel = 100;
    // cam.max_depth = 50;

    // cam.vfov = 20;
    // cam.lookfrom = Point3(-2.0, 2.0, 1.0);
    // cam.lookat = Point3(0.0, 0.0, -1.0);
    // cam.vup = vec3(0.0, 1.0, 0.0);

    // cam.defocus_angle = 10.0;
    // cam.focus_dist = 3.4;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 1200;
    cam.samples_per_pixel = 500;
    cam.max_depth = 50;

    cam.vfov = 20;
    cam.lookfrom = Point3(13, 2, 3);
    cam.lookat = Point3(0, 0, 0);
    cam.vup = vec3(0, 1, 0);

    cam.defocus_angle = 0.6;
    cam.focus_dist = 10.0;

    cam.render(world);
}