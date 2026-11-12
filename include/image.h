#pragma once
#include <list>
#include <glm/glm.hpp>
#include <vector>
#include <cstdint>

struct Image
{
    static const int CHANNELS = 3;

    int width, height;
    std::vector<float> pixels;

    Image(const int w, const int h);
    void set_pixel(const int x, const int y, const glm::vec3 c);
    void save(const char* file_name) const;
};