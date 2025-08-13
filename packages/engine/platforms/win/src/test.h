#pragma once
#include <core/engine.h>
#include <core/command_layer.h>
#include <iostream>


void testEventPayloads(Core::Engine& engine) 
{

	// Subscribe to internal events.
	engine.subscribe(
		Core::EventTypes::LayerAdded, 
		[](const Core::EventPayload& payload) {
			if (auto p = std::get_if<Core::LayerChangedPayload>(&payload)) {
				std::cout << "Layer added: "
					<< p->name << " with ID: "
					<< p->uuid << ", visible: "
					<< std::boolalpha << p->visible << std::endl;
			}
			else {
				std::cerr << "Unexpected payload type for LayerAdded event.\n";
			}
		});



	// Dispatch a Command to Engine -> does some action
	engine.dispatch(Core::AddLayerCommand({
		.name = "Test Layer"
		}));
}