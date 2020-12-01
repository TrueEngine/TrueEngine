#pragma once

#ifdef TE_PLATFORM_WINDOWS

extern TrueEngine::Application* TrueEngine::CreateApplication();

int main(int argc, char** argv)
{
	TrueEngine::Log::Init();
	TE_CORE_WARN("Initialized Log!");
	TE_INFO("Initialized Log!");
	int a = 5;
	TE_INFO("Hello! Var={0}", a);

	auto app = TrueEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif