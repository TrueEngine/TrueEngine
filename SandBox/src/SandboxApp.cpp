#include <TrueEngine.h>

class ExampleLayer : public TrueEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		TE_INFO("ExampleLayer::Update");
	}

	void OnEvent(TrueEngine::Event& event) override
	{
		TE_TRACE("{0}", event);
	}

};

class Sandbox : public TrueEngine::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushLayer(new TrueEngine::ImGuiLayer());
	}

	~Sandbox()
	{

	}

};

TrueEngine::Application* TrueEngine::CreateApplication()
{
	return new Sandbox();
}