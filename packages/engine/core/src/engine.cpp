#include <core/engine.h>
#include <core/event_bus.h>
#include "managers/layer_manager.h"
#include <iostream>
#include <thread>

#include "commands/commands.h"

namespace Core {

	struct Engine::Impl {
		IRenderer* renderer = nullptr;   // not owning
		EventBus eventBus;
		LayerManager layerManager;
		bool running = false;

		Impl(IRenderer* r) : renderer(r), layerManager(eventBus) {}
	};

	Engine::Engine(IRenderer* renderer) noexcept : m_(new Impl(renderer)) 
	{
		std::cout << "XYX - App design." << std::endl;
		Commands::regitserLayerCommands(*this);
	}
	
	Engine::~Engine() 
	{ 
		m_->eventBus.clear();
		m_->layerManager.clear();
		delete m_; 
	}

	void Engine::update()
	{
		// Update the application state
	}


	void Engine::dummyAction() {
		std::cout << "Dummy action!" << std::endl;
	}


	void Engine::subscribe(EventTypes type, Handler handler)
	{
		m_->eventBus.subscribe(type, std::move(handler));
	}

	template <typename Command>
	void Engine::dispatch(const Command& cmd)
	{
		m_dispatcher.dispatch(m_->layerManager ,cmd);
		// dispatch with other contexts
		// m_dispatcher.dispatch(m_->xyzManager, cmd);
	}
}