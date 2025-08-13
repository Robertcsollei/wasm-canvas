#include "entities/layer_group.h"



void LayerGroup::addChild(const std::shared_ptr<Layer>& child) {
	if (child) {
		child->setParent(shared_from_this());
		children.push_back(child);
	}
}

void LayerGroup::removeChild(const std::shared_ptr<Layer>& child) {
	if (child) {
		auto it = std::remove(children.begin(), children.end(), child);
		if (it != children.end()) {
			children.erase(it, children.end());
			child->resetParent();
		}
	}
}

