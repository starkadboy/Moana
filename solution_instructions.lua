workspace "Moana"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}_%{cfg.system}%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "vendor/src/glfw/include"

include "vendor/src/glfw"

project "MoanaEngine"
	location "code"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin/" .. outputdir .. "/temp/%{prj.name}")

	pchheader "PrecompiledHeaders.h"
	pchsource "code/MoanaEngine/PrecompiledHeaders.cpp"

	files
	{
		"code/%{prj.name}/**.h",
		"code/%{prj.name}/**.cpp"
	}

	includedirs
	{
		"code/%{prj.name}",
		"vendor/src/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links 
	{ 
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MOA_WINDOWS",
			"MOA_ENGINE_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "MOA_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "MOA_RELEASE"
		optimize "on"

project "Sandbox"
	location "code"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin/" .. outputdir .. "/temp/%{prj.name}")

	files
	{
		"code/%{prj.name}/**.h",
		"code/%{prj.name}/**.cpp"
	}

	includedirs
	{
		"vendor/src/spdlog/include",
		"code/MoanaEngine"
	}

	links
	{
		"Moana"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

		defines
		{
			"MOA_WINDOWS"
		}

	filter "configurations:Debug"
		defines "MOA_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "MOA_RELEASE"
		optimize "on"