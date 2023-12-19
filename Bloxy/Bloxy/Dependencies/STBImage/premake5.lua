project "STBImage"
	kind "StaticLib"
	language "C++"
	cppdialect "C++11"
	staticruntime "on"

	targetdir (bin_dir)
	objdir (bin_int_dir)

	files
	{
		"STBImage/stb_image.h",
		"stb_image.cpp",
	}

	includedirs
	{
		"STBImage",
	}

	filter "system:windows"
        systemversion "latest"

        defines
        {
            "STBIMAGE_PLATFORM_WINDOWS",
        }

	filter "configurations:Debug"
		defines "STBIMAGE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "STBIMAGE_RELEASE"
		runtime "Release"
		symbols "on"