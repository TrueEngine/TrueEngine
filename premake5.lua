include "./vendor/premake/premake_customization/solution_items.lua"

workspace "TrueEngine"
	architecture "x86_64"
	startproject "TrueEditor"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
-- IncludeDir["GLFW"] = "%{wks.location}/Hazel/vendor/GLFW/include"

group "Dependencies"
	include "vendor/premake"
group ""

include "TrueEngine"
include "TrueEditor"