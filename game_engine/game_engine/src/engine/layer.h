#pragma once

#include "core.h"

#include <SFML/Window/Event.hpp>
using sf::Event;

namespace Engine
{
	struct ENGINE_API Layer
	{
		std::string name;

		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}
	};
}
