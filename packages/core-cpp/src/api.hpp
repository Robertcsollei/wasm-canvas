#pragma once
#include <vector>
#include <cstdint>

namespace core {
  // Example: compute NDWI-like metric for two bands
  void ndwi(const float* nir, const float* green, float* out, std::size_t n);

  // Opaque handles pattern (avoid shipping big structs over JS boundary)
  using LayerId = uint32_t;
  LayerId add_layer();
  void    set_visible(LayerId id, bool visible);
  bool    is_visible(LayerId id);
}
