#include "app.h"
#include <iostream>
#include <thread>

App::App() 
	: renderer()
{
  // Initialize the application
std::cout << "Application initialized." << std::endl;
}

App::~App() 
{
  // Clean up resources
}



void App::update() 
{
std::cout << "Run Updated!" << std::endl;
// Update the application state
  renderer.renderFrame();
}


void App::dummyAction() {
	std::cout << "Dummy action!" << std::endl;
}
