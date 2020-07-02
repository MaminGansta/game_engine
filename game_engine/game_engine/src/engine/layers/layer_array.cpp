
#include "../pch.h"
#include "layer_array.h"

namespace Engine
{
	void LayerArray::push_back(Layer* layer)
	{
		layers.push_back(layer);
		layer->OnAttach();
	}

	void LayerArray::remove(int id)
	{
		layers[id]->OnDetach();
		delete layers[id];
		layers.erase(layers.begin() + id);
	}

	void LayerArray::emplace(int id, Layer* layer)
	{
		layers.emplace(layers.begin() + id, layer);
		layer->OnAttach();
	}

	void LayerArray::swap(int id_1, int id_2)
	{
		std::swap(layers[id_1], layers[id_2]);
	}

	LayerArray::~LayerArray()
	{
		for (Layer* layer : layers)
		{
			layer->OnDetach();
			delete layer;
		}
	}

	Layer* LayerArray::operator [] (int id)
	{
		return layers[id];
	}

}