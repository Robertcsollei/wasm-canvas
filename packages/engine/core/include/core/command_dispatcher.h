#pragma once
#include <unordered_map>
#include <typeindex>
#include <functional>
#include <stdexcept>


namespace Core {
class CommandDispatcher {
public:
	template <typename Command, typename Handler>
	void registerHandler(Handler&& handler) {
		std::type_index key(typeid(Command));

		if (m_handlers.count(key)) {
			throw std::runtime_error("Handler already registered for this command");
		}

		// Store a type-erased lambda
		m_handlers[key] = [h = std::forward<Handler>(handler)](void* instance, const void* cmd) {
			h(*static_cast<std::decay_t<decltype(*instance)>*>(instance),
				*static_cast<const Command*>(cmd));
			};
	}

	template <typename Command, typename Instance>
	void dispatch(Instance& instance, const Command& cmd) const {
		auto it = m_handlers.find(std::type_index(typeid(Command)));
		if (it == m_handlers.end()) {
			throw std::runtime_error("No handler registered for this command");
		}
		it->second(&instance, &cmd);
	}

private:
	std::unordered_map<std::type_index, std::function<void(void*, const void*)>> m_handlers;
};
}