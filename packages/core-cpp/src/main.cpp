#include <emscripten/emscripten.h>
#include "globals.h"
#include "app.h"

App* g_app = nullptr;  

static void tick() {
    g_app->update();
}

int main() {
App app;
g_app = &app;
emscripten_set_main_loop(tick, 0, 1);
}