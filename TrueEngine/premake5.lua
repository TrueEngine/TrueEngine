project "TrueEngine"
	kind "StaticLib"
	language "C#"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

--	pchheader "hzpch.h"
--	pchsource "src/hzpch.cpp"

	files
	{
		"src/**.cs",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	includedirs
	{
		"src",
	}

	links
	{
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
		}

	filter "configurations:Debug"
		defines "TE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "TE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "TE_DIST"
		runtime "Release"
		optimize "on"