#pragma once
#include <functional>
#include <unordered_map>
#include <vector>
#include <string>
#include <string_view>
#include <core/magic_enum.h>
#include <core/events_types.h>
#include <core/event_payloads.h>


class EventBus {
public:
	EventBus();
	~EventBus();

	// Disable copy and move semantics
	EventBus(const EventBus&) = delete;
	EventBus& operator=(const EventBus&) = delete;
	EventBus(EventBus&&) = delete;
	EventBus& operator=(EventBus&&) = delete;

public:
	using Handler = std::function<void(const Core::EventPayload)>;

	void emit(Core::EventTypes type, const Core::EventPayload payload);
	void subscribe(Core::EventTypes type, Handler handler);
	void clear();

private:
	std::unordered_map<std::string_view, std::vector<Handler>> m_handlers;
};