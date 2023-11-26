project "SandBox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "on"

	targetdir (bin_dir)
	objdir (bin_int_dir)

	pchheader("pch.h")
	pchsource("src/pch.cpp")

	files 
	{
		"src/**.cpp",
		"src/**.h",
	}

	includedirs
	{
		"src",
		sln .. "Bloxy/src",
		sln .. "Bloxy/src/Bloxy",
		sln .. "Bloxy/dependencies/ImGui/ImGui",
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