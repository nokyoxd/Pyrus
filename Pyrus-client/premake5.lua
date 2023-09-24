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

	-- Override for Visual Studio
	filter "action:vs*"
		targetdir "$(SolutionDir)build/$(Configuration)/"
		objdir "!$(SolutionDir)build/$(Configuration)/intermediates/"

	-- Override for CodeBlocks
	filter "action:codeblocks"
		targetdir "%{wks.location}/build/"
		objdir "!%{wks.location}/build/intermediates/"

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "NDEBUG"
		runtime "Release"
		optimize "on"
