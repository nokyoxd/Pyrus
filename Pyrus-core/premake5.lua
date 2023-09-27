project "Pyrus-core"
	kind "SharedLib"
	staticruntime "off"
	targetname "Pyrus-core"

	language "C++"
	cppdialect "C++17"

	files
	{
		"**.h",
		"**.hpp",
		"**.cpp",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
	}

	includedirs
	{
		"%{wks.location}/Pyrus-core/src",
		"%{wks.location}/Pyrus-core/assets",
		"%{wks.location}/Pyrus-core/vendor",
		"%{wks.location}/Pyrus-core/vendor/GLFW/include"
	}

	-- Override for Visual Studio
	filter "action:vs*"
		targetdir "$(SolutionDir)build/$(Configuration)/"
		objdir "!$(SolutionDir)build/$(Configuration)/intermediates/"
		links { "glfw3_mt", "opengl32" }
		libdirs { "%{wks.location}/Pyrus-core/vendor/GLFW/lib-vc2022" }

	-- Override for CodeBlocks
	filter "action:codeblocks"
		targetdir "%{wks.location}/build/"
		objdir "!%{wks.location}/build/intermediates/"
		links { "libglfw3.a", "opengl32", "glu32", "gdi32", "user32", "kernel32", "dwmapi"}
		libdirs { "%{wks.location}/Pyrus-core/vendor/GLFW/lib-mingw-w64" }

	filter "system:Windows"
		system "windows"
		defines "PS_PLATFORM_WINDOWS"

	filter "system:Linux"
		system "linux"
		defines "PS_PLATFORM_LINUX"

	filter "configurations:Debug"
		defines "_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "NDEBUG"
		runtime "Release"
		optimize "on"
