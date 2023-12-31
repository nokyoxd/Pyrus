project "Pyrus-client"
	kind "ConsoleApp"
	staticruntime "off"
	targetname "Pyrus-client"

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
		"%{wks.location}/Pyrus-client/src",
		"%{wks.location}/Pyrus-client/assets",
		"%{wks.location}/Pyrus-client/vendor",
		"%{wks.location}/Pyrus-core/src",
	}

	libdirs
	{
		"%{wks.location}/Build/$(Configuration)/"
	}

	links 
	{
		"Pyrus-core",
	}

	filter "action:vs*"
		targetdir "$(SolutionDir)build/$(Configuration)/"
		objdir "!$(SolutionDir)build/$(Configuration)/intermediates/"

	filter "action:codeblocks"
		targetdir "%{wks.location}/build/"
		objdir "!%{wks.location}/build/intermediates/"

	filter "system:Windows"
		system "Windows"
		defines "PS_PLATFORM_WINDOWS"

	filter "system:Linux"
		system "Linux"
		defines "PS_PLATFORM_LINUX"

	filter "configurations:Debug"
		defines "_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "NDEBUG"
		runtime "Release"
		optimize "on"
