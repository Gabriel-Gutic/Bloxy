dependencies = {}
dependencies["GLFW"] = "Dependencies/GLFW/GLFW/include"
dependencies["Glad"] = "Dependencies/Glad/Glad/include"
dependencies["STBImage"] = "Dependencies/STBImage/STBImage"
dependencies["ImGui"] = "Dependencies/ImGui/imgui"

group "Dependencies"
	include "Dependencies/GLFW"
	include "Dependencies/Glad"
	include "Dependencies/STBImage"
	--include "dependencies/ImGui"
group ""

project "Bloxy"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "on"

	targetdir (bin_dir)
	objdir (bin_int_dir)

	pchheader("pchBloxy.h")
	pchsource("Source/pchBloxy.cpp")

	files 
	{
		"Source/**.cpp",
		"Source/**.h",
	}

	includedirs
	{
		"Source",
		"Source/Bloxy",
		dependencies["GLFW"],
		dependencies["Glad"],
		dependencies["ImGui"],
		dependencies["STBImage"],
		dependencies["ImGui"] .. "/imgui",
		"Dependencies/glm",
		"Dependencies/spdlog/include",
	}

	links 
	{
		"GLFW",
		"Glad",
		"STBImage",
		--"ImGui",
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"BLOXY_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "DEBUG"
		defines "BLOXY_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "RELEASE"
		defines "BLOXY_RELEASE"
		runtime "Release"
		symbols "on"