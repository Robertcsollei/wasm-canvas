#include "api.hpp"
#include "app.h"

namespace engineWasmBinding {
    void dummyAction() {
        if (g_app) g_app->dummyAction();
        // else: optionally buffer the command or ignore until ready
    }
}

#ifdef __EMSCRIPTEN__
#include <emscripten/bind.h>
// embind bindings
EMSCRIPTEN_BINDINGS(core_api) {
    emscripten::function("dummyAction", &core::dummyAction);
}
#endif
