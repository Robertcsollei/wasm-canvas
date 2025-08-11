#include "api.hpp"
#include <unordered_map>

namespace core {
  void ndwi(const float* nir, const float* green, float* out, std::size_t n) {
    for (std::size_t i=0; i<n; ++i) {
      float a = green[i], b = nir[i];
      out[i] = (a - b) / (a + b + 1e-6f);
    }
  }

  static std::unordered_map<LayerId, bool> vis;
  static LayerId nextId = 1;

  LayerId add_layer() { vis[nextId] = true; return nextId++; }
  void set_visible(LayerId id, bool v) { vis[id] = v; }
  bool is_visible(LayerId id) { return vis[id]; }
}

#ifdef __EMSCRIPTEN__
#include <emscripten/bind.h>
// embind bindings
EMSCRIPTEN_BINDINGS(core_api) {
  emscripten::function("add_layer", &core::add_layer);
  emscripten::function("set_visible", &core::set_visible);
  emscripten::function("is_visible", &core::is_visible);

  // Example: pass typed arrays
  emscripten::function("ndwi", +[](uintptr_t nirPtr, uintptr_t greenPtr, uintptr_t outPtr, std::size_t n){
    auto nir   = reinterpret_cast<const float*>(nirPtr);
    auto green = reinterpret_cast<const float*>(greenPtr);
    auto out   = reinterpret_cast<float*>(outPtr);
    core::ndwi(nir, green, out, n);
  });
}
#endif
