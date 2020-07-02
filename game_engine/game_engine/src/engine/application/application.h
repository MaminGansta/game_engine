#pragma once

#include "../layers/layer_array.h"

namespace Engine
{
	struct Application
	{
		LayerArray layer_array;
		sf::RenderWindow* main_window;

		Application();
		virtual ~Application();

		void push_layer(Layer* layer);
		void remove_layer(int id);
		void emplace_layer(int id, Layer* layer);
		void swap_layers(int id_1, int id_2);

		virtual sf::RenderWindow* create_window();

		void run();

	};

	Application* create_application();
}