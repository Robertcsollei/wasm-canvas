#include "managers/layer_manager.h"
#include <core/events_types.h>
#include <core/event_payloads.h>


LayerManager::LayerManager(EventBus& eventBus)
	: m_eventBus(eventBus)
{ 
}


void LayerManager::addLayer(std::shared_ptr<Layer> layer)
{
	layers[layer->m_uuid] = layer;
	m_eventBus.emit(
		Core::EventTypes::LayerAdded,
		Core::LayerChangedPayload{
			.name = layer->m_name,
			.uuid = uuids::to_string(layer->m_uuid),
			.visible = layer->isEffectivelyVisible()
		}
	);
}

void LayerManager::removeLayer(uuids::uuid id)
{
	auto it = layers.find(id);
	if (it != layers.end()) {
		layers.erase(it);
		m_eventBus.emit(
			Core::EventTypes::LayerRemoved,
			Core::LayerRemovedPayload{ .uuid = uuids::to_string(id) }
		);
	}
}

std::shared_ptr<Layer> LayerManager::getLayer(uuids::uuid id) const
{
	auto it = layers.find(id);
	if (it != layers.end()) {
		return it->second;
	}
	return nullptr; // Return nullptr if layer not found
}

void LayerManager::clear()
{
	layers.clear(); // Clear all layers
}


