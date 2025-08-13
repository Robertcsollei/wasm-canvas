#include "commands/commands.h"
#include <core/command_layer.h>
#include "managers/layer_manager.h"

void Commands::regitserLayerCommands(Core::Engine& engine)
{
	engine.registerCommandHandler<Core::AddLayerCommand>(
		[](LayerManager& l, const Core::AddLayerCommand& c) 
		{
			uuids::uuid uuid;
			uuid.from_string(c.data.uuid);
			auto layer = std::make_shared<Layer>(c.data.name, uuid);
			l.addLayer(layer);
		});
}