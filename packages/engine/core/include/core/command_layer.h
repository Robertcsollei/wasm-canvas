// commands/layer_commands.hpp
#pragma once
#include <string>
#include <optional>

namespace Core {

	struct LayerDto {
		std::string uuid;
		std::string name;
		bool visible;
		std::string parentId;
		int childIndex;
	};

	struct AddLayerCommand {
		LayerDto data;
	};


} // namespace Core
