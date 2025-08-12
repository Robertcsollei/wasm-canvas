#pragma once
#include "renderer.hpp"

class RendererGL : public IRenderer {
public:
    void init() override;
    void beginFrame(int width, int height) override;
    void draw() override;
    void endFrame() override;
};