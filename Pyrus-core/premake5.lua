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
		"GLEW_STATIC"
	}

	includedirs
	{
		"%{wks.location}/Pyrus-core/src",
		"%{wks.location}/Pyrus-core/assets",
		"%{wks.location}/Pyrus-core/vendor",
		"%{wks.location}/Pyrus-core/vendor/GLFW/include",
		"%{wks.location}/Pyrus-core/vendor/fmt/include",
		"%{wks.location}/Pyrus-core/vendor/GLEW/include"
	}

	libdirs 
	{ 
		"%{wks.location}/Pyrus-core/vendor/fmt/lib/",
		"%{wks.location}/Pyrus-core/vendor/GLEW/lib/"
	}

	links 
	{ 
		"opengl32", 
		"glu32", 
		"gdi32", 
		"user32", 
		"kernel32", 
		"dwmapi",
		"glew32s"
	}

	filter "action:vs*"
		targetdir "$(SolutionDir)build/$(Configuration)/"
		objdir "!$(SolutionDir)build/$(Configuration)/intermediates/"
		links "glfw3_mt"
		libdirs "%{wks.location}/Pyrus-core/vendor/GLFW/lib-vc2022"
			
	filter "action:codeblocks"
		targetdir "%{wks.location}/build/"
		objdir "!%{wks.location}/build/intermediates/"
		links "libglfw3.a"
		links "libopengl32.a"
		links "libgdi32.a"
		libdirs "%{wks.location}/Pyrus-core/vendor/GLFW/lib-mingw-w64"

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
		links "fmtd"

	filter "configurations:Release"
		defines "NDEBUG"
		runtime "Release"
		optimize "on"
		links "fmt"
