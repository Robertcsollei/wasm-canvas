#include "emscripten_shim.h"
#include "engine.h"
#include "api.hpp"
#include "renderer_gl.hpp"


static void tick() {
    engineWasmBinding::g_engine->update();
}

int main() {
    static RendererGL renderer;
    static Engine engine(&renderer);
    engineWasmBinding::g_engine = &engine;
    emscripten_set_main_loop(tick, 0, 1);
    return 0;
}