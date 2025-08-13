#include <core/event_bus.h>


EventBus::EventBus() = default;
EventBus::~EventBus() = default;

void EventBus::emit(Core::EventTypes type, const Core::EventPayload payload)
{
	auto it = m_handlers.find(magic_enum::enum_name(type));
	if (it != m_handlers.end()) {
		for (auto& handler : it->second) {
			handler(payload);
		}
	}
}

void EventBus::subscribe(Core::EventTypes type, Handler handler)
{
	m_handlers[magic_enum::enum_name(type)].push_back(std::move(handler));
}

void EventBus::clear()
{
	m_handlers.clear();
}