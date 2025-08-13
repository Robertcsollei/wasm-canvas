#pragma once
#include <core/renderer.h>
#include <core/command_dispatcher.h>
#include <core/event_payloads.h>
#include <core/events_types.h>


namespace Core {

class Engine {

public:
    explicit Engine(IRenderer* renderer) noexcept;
    ~Engine();
    using Handler = std::function<void(const EventPayload)>;

public:
    bool running() { return true; };
    void update();
    void dummyAction();

    template <typename Command>
    void dispatch(const Command& cmd);

    template <typename Command, typename Handler>
    void registerCommandHandler(Handler&& handler) {
		m_dispatcher.registerHandler(handler);
	}


    void subscribe(EventTypes type, Handler handler);

private:
    struct Impl;
    Impl* m_;
    CommandDispatcher m_dispatcher;
};
}