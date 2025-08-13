#pragma once

namespace Core {
struct IRenderer {
    virtual ~IRenderer() = default;

    virtual void init() = 0;
    virtual void beginFrame(int width, int height) = 0;
    virtual void draw() = 0;
    virtual void endFrame() = 0;
};
}