project "SandBox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "on"

	targetdir (bin_dir)
	objdir (bin_int_dir)

	pchheader("pch.h")
	pchsource("Source/pch.cpp")

	files 
	{
		"Source/**.cpp",
		"Source/**.h",
	}

	includedirs
	{
		"Source",
		sln .. "Bloxy/Source",
		sln .. "Bloxy/Source/Bloxy",
		sln .. "Bloxy/Dependencies/ImGui/ImGui",
		sln .. "Bloxy/Dependencies/spdlog/include",
		sln .. "Bloxy/Dependencies/glm",
	}

	links
	{
		"Bloxy",
	}

	filter "system:windows"
		systemversion "latest"
		--kind "WindowedApp"

		defines
		{
			"SANDBOX_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "DEBUG"
		defines "SANDBOX_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "RELEASE"
		defines "SANDBOX_RELEASE"
		runtime "Release"
		symbols "on"