#pragma once

#include "layer.h"


namespace Engine
{
	struct LayerArray
	{
		std::vector<Layer*> layers;

		void push_back(Layer* layer);
		void remove(int id);
		void emplace(int id, Layer* layer);
		void swap(int id_1, int id_2);

		Layer* operator [] (int id);
		~LayerArray();
	};
}