#pragma once

#ifdef TE_PLATFORM_WINDOWS
	#ifdef TE_BUILD_DLL
		#define TRUE_API __declspec(dllexport)
	#else
		#define TRUE_API _declspec(dllimport)
	#endif
#else
	#error The TrueEngine only supports Windows!
#endif