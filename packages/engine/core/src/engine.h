#pragma once
#include "renderer.hpp"


class Engine {

public:
    Engine(IRenderer* renderer);
    ~Engine();

public:
    bool running() { return true; };
    void update();
    void dummyAction();


private:
    IRenderer* m_renderer = nullptr;
};
