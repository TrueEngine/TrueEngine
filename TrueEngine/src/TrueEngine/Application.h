#pragma once

#include "Core.h"

#include "TrueEngine/Window.h"
#include "TrueEngine/LayerStack.h"
#include "TrueEngine/Events/Event.h"
#include "TrueEngine/Events/ApplicationEvent.h"

namespace TrueEngine {

	class TRUE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}