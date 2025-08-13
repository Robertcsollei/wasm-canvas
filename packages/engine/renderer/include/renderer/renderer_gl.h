#pragma once
#include <core/renderer.h>


namespace Renderer {

    class RendererGL : public Core::IRenderer {
    public:
        void init() override;
        void beginFrame(int width, int height) override;
        void draw() override;
        void endFrame() override;
    };

}