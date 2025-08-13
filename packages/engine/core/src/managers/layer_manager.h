#pragma once
#include <memory>
#include <unordered_map>

#include "entities/layer.h"
#include <core/event_bus.h>


class LayerManager {

public:
	LayerManager(EventBus& eventBus);
	~LayerManager() = default;

	// Disable copy and move semantics
	LayerManager(const LayerManager&) = delete;
	LayerManager& operator=(const LayerManager&) = delete;
	LayerManager(LayerManager&&) = delete;
	LayerManager& operator=(LayerManager&&) = delete;

public:
    void addLayer(std::shared_ptr<Layer> layer);
	void removeLayer(uuids::uuid id);
    std::shared_ptr<Layer> getLayer(uuids::uuid id) const;
	void clear();

private:
    std::unordered_map<uuids::uuid, std::shared_ptr<Layer>> layers;
	EventBus& m_eventBus;

};
