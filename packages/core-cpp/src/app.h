#pragma once
#include "render/renderer.h"


class App {

public:
    App();
    ~App();

public:
    bool running() { return true; };
    void update();
    void dummyAction();


private:
    Renderer renderer;
};
