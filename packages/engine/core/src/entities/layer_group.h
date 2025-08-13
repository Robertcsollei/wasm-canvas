#pragma once
#include "entities/layer.h"
#include <vector>
#include <memory>
#include <string>

class LayerGroup : public Layer {

public:
    LayerGroup(const std::string& name = "Group")
		: Layer(name) {}

	~LayerGroup() override = default;

	void addChild(const std::shared_ptr<Layer>& child);
	void removeChild(const std::shared_ptr<Layer>& child);
	const std::vector<std::shared_ptr<Layer>>& getChildren() const { return children; }


private:
    std::vector<std::shared_ptr<Layer>> children;


};
