
#include "pch.h"
#include "application.h"

namespace Engine
{
    Application::Application() 
    {
        main_window = create_window();
    }

	Application::~Application() {}

    // ================== Layers ======================
	void Application::push_layer(Layer* layer)
	{
		layer_array.push_back(layer);
	}

	void Application::emplace_layer(int id, Layer* layer)
	{
		layer_array.emplace(id, layer);
	}

    void Application::remove_layer(int id)
    {
        layer_array.remove(id);
    }

	void Application::swap_layers(int id_1, int id_2)
	{
		layer_array.swap(id_1, id_2);
	}
	

    // =================== Window ====================
    sf::RenderWindow* Application::create_window()
    {
        sf::ContextSettings settings;
        settings.depthBits = 24;
        settings.stencilBits = 8;
        settings.antialiasingLevel = 4;
        settings.majorVersion = 3;
        settings.minorVersion = 0;

        return new sf::RenderWindow(sf::VideoMode(800, 600), "Widnow", sf::Style::Default, settings);
    }

    void Application::window_onEvent(Event& event)
    {
        if (event.type == sf::Event::Closed)
            main_window->close();
    }



    // ======================= Run ========================
	void Application::run()
	{
        while (main_window->isOpen())
        {
            // Send events
            Event event;
            while (main_window->pollEvent(event))
            {
                for (auto& layer : layer_array.layers)
                    layer->OnEvent(event);
                
                window_onEvent(event);
            }
            
            // Update layers
            for (auto& layer : layer_array.layers)
                layer->OnUpdate();

            // render window
            main_window->display();
        }
	}

}