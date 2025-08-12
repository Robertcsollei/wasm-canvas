#pragma once
#if defined(__EMSCRIPTEN__)
#include <emscripten/emscripten.h>
#else
// Stubs so IntelliSense is happy when not on the wasm toolchain.
inline void emscripten_set_main_loop(void(*)(void), int, int) {}
#endif
