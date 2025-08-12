#include "engine.h"
#include <iostream>
#include <thread>

Engine::Engine(IRenderer* renderer) 
	: m_renderer(renderer)
{
  // Initialize the application
std::cout << "Application initialized." << std::endl;
}

Engine::~Engine() 
{
  // Clean up resources
}



void Engine::update() 
{
// Update the application state
}


void Engine::dummyAction() {
	std::cout << "Dummy action!" << std::endl;
}
