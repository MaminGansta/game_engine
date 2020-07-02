
#include "../engine/engine.h"


struct ImGuiLayer : Engine::Layer
{
    sf::RenderWindow* window;

    sf::Color bgColor;
    float color[3] = { 0.f, 0.f, 0.f };
    char windowTitle[255] = "ImGui + SFML = <3";
    sf::Clock deltaClock;


    ImGuiLayer(sf::RenderWindow* window)
        :
        Layer("ImGui"),
        window(window)
	{}

	void OnAttach() override
	{
        ImGui::SFML::Init(*window);
        window->setTitle(windowTitle);
	}

	void OnDetach() override
	{
        ImGui::SFML::Shutdown();
	}

	void OnUpdate() override
	{
        window->clear(bgColor); // fill background with color

        window->resetGLStates(); // call it if you only draw ImGui. Otherwise not needed.

        ImGui::SFML::Update(*window, deltaClock.restart());

        ImGui::Begin("Sample window");

        if (ImGui::ColorEdit3("Background color", color)) {
            bgColor.r = static_cast<sf::Uint8>(color[0] * 255.f);
            bgColor.g = static_cast<sf::Uint8>(color[1] * 255.f);
            bgColor.b = static_cast<sf::Uint8>(color[2] * 255.f);
        }

        // Window title text edit
        ImGui::InputText("Window title", windowTitle, 255);

        if (ImGui::Button("Update window title")) {
            window->setTitle(windowTitle);
        }
        ImGui::End(); // end window

        ImGui::SFML::Render(*window);
	}

	void OnEvent(Event& event) override
	{
        ImGui::SFML::ProcessEvent(event);
	}

};



struct Sandbox : Engine::Application
{
	Sandbox()
	{
        push_layer(new ImGuiLayer(main_window));
	}
};



Engine::Application* Engine::create_application()
{
	return new Sandbox();
}

