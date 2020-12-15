#include "tepch.h"
#include "Application.h"

#include "TrueEngine/Events/ApplicationEvent.h"
#include "TrueEngine/Log.h"

namespace TrueEngine {

	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() {

	}

	void Application::Run() {

		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}
