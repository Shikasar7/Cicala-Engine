workspace "Cicala"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Cicala/vendor/GLFW/include"
IncludeDir["Glad"] = "Cicala/vendor/Glad/include"
IncludeDir["ImGui"] = "Cicala/vendor/imgui"
IncludeDir["glm"] = "Cicala/vendor/glm"

group "Dependencies"
	include "Cicala/vendor/GLFW"
	include "Cicala/vendor/Glad"
	include "Cicala/vendor/imgui"

group ""

project "Cicala"
	location "Cicala"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	pchheader "ccpch.h"
	pchsource "Cicala/src/ccpch.cpp"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
		"%{prj.name}/vendor/glm/glm/**.inl"

	}

	includedirs
	{	
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",
		"dwmapi"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"CC_PLATFORM_WINDOWS",
			"CC_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}


		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox" )
		}

	filter "configurations:Debug"
		defines "CC_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "CC_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "CC_DIST"
		runtime "Release"
		optimize "On"

	filter { "system:Windows", "configurations:Release"}
		buildoptions "/MT"

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
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Cicala/vendor/spdlog/include",
		"Cicala/src",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Cicala"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"CC_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "CC_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "CC_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "CC_DIST"
		runtime "Release"
		optimize "On"



