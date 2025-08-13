#pragma once
#include <vector>
#include <cstdint>
#include <string>

struct RasterData {
    int width;
    int height;
    int channels;
    std::vector<uint8_t> data; // Raw pixel data

    RasterData(int w, int h, int c)
        : width(w), height(h), channels(c),
        data(w* h* c, 0) {}
};
