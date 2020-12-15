#pragma once

#ifdef TE_PLATFORM_WINDOWS

extern TrueEngine::Application* TrueEngine::CreateApplication();

int main(int argc, char** argv)
{
	TrueEngine::Log::Init();
	TE_CORE_WARN("Initialized Log!");
	TE_INFO("Initialized Log!");

	auto app = TrueEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif