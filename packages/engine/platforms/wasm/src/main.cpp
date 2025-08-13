#include "emscripten_shim.h"
#include <core/engine.h>
#include <renderer/renderer_gl.h>



static void tick() {
    engineWasmBinding::g_engine->update();
}

int main() {
    static Renderer::RendererGL renderer;
    static Core::Engine engine(&renderer);
    engineWasmBinding::g_engine = &engine;
    emscripten_set_main_loop(tick, 0, 1);
    return 0;
}