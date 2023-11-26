dependencies = {}
dependencies["GLFW"] = "dependencies/GLFW/GLFW/include"
dependencies["Glad"] = "dependencies/Glad/Glad/include"
dependencies["ImGui"] = "dependencies/ImGui/imgui"

group "Dependencies"
	include "dependencies/GLFW"
	include "dependencies/Glad"
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
	pchsource("src/pchBloxy.cpp")

	files 
	{
		"src/**.cpp",
		"src/**.h",
	}

	includedirs
	{
		"src",
		"src/Bloxy",
		dependencies["GLFW"],
		dependencies["Glad"],
		dependencies["ImGui"],
		dependencies["ImGui"] .. "/imgui",
	}

	links 
	{
		"GLFW",
		"Glad",
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