using namespace std;
#include <iostream>
#include <glm/glm.hpp>
#include "image.h"
#include <optional>

struct Ray {
    glm::vec3 origin;
    glm::vec3 direction;
};

struct Sphere {
    glm::vec3 center;
    float radius;
};

optional<float> intersect(const Ray& ray, const Sphere& sphere) {
    const float a = glm::dot(ray.direction, ray.direction);
    const auto co = ray.origin - sphere.center;
    const float b = 2 * glm::dot(ray.direction, co);
    const float c = glm::dot(co, co) - sphere.radius * sphere.radius;

    const float delta = b * b - 4 * a * c;

    if (delta >= 0) {
        const float sqrtDelta = std::sqrt(delta);
        float ta = (-b - sqrtDelta) / (2 * a);
        float tb = (-b + sqrtDelta) / (2 * a);

        if (ta > 0)
            return { ta };
        if (tb > 0)
            return { tb };
    }

    return {};
}

int main()
{
    int Width = 640;
    int Height = 480;
    Image img(Width, Height);
    const Sphere sphere{ glm::vec3{ Width / 2, Height / 2, 500 }, 200 };
    for (int y = 0; y < Height; ++y) {
        for (int x = 0; x < Width; ++x) {
            const Ray ray{ glm::vec3{ x + 0.5f, y + 0.5f, 0 }, glm::vec3{ 0, 0, 1 } };
            const auto it = intersect(ray, sphere);
            if (it) {
                glm::vec3 Pixel = {1.0f, 0, 0};
                img.set_pixel(x, y, Pixel);
            }
            else {
                glm::vec3 Pixel = {0, 0, 0};
                img.set_pixel(x, y, Pixel);
            }
        }
    }
    
    img.save("img.png");
    return 0;
};