workspace "TrueEngine"
	architecture "x64"

	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "TrueEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "TrueEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "TrueEngine/vendor/imgui"

group "Dependencies"
	include "TrueEngine/vendor/GLFW"
	include "TrueEngine/vendor/Glad"
	include "TrueEngine/vendor/imgui"
group ""

project "TrueEngine"
	location "TrueEngine"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "tepch.h"
	pchsource "TrueEngine/src/tepch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"TE_PLATFORM_WINDOWS",
			"TE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox\"")
		}

	filter "configurations:Debug"
		defines "TE_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "TE_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "TE_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"TrueEngine/vendor/spdlog/include",
		"TrueEngine/src"
	}

	links
	{
		"TrueEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"TE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "TE_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "TE_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "TE_DIST"
		runtime "Release"
		optimize "On"