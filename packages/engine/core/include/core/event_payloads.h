
#pragma once
#include <string>
#include <variant>
#include <optional>

namespace Core {
    struct LayerChangedPayload {
        std::string name;
        std::string uuid;
        bool visible;
    };

    struct LayerRemovedPayload {
        std::string uuid;
    };

    using EventPayload = std::variant<
        LayerChangedPayload,
        LayerRemovedPayload
    >;
}
