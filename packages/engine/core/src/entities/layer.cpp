#include "entities/layer.h"

Layer::Layer(const std::string& name)
	: m_name(name) {
}

Layer::Layer(const std::string& name, uuids::uuid uuid)
	: m_name(name), m_uuid(uuid) 
{
}

bool Layer::isEffectivelyVisible() {
	if (!m_visible) {
		return false;
	}
	auto parentLayer = m_parent.lock();
	if (parentLayer) {
		return parentLayer->isEffectivelyVisible();
	}

	return true;
}

