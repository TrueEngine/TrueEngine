#include "TrueEngine.h"

class Sandbox : public TrueEngine::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

TrueEngine::Application* TrueEngine::CreateApplication()
{
	return new Sandbox();
}