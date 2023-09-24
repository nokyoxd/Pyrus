project "Mayday-core"
	kind "SharedLib"
	staticruntime "on"
	targetname "Mayday-core"

	language "C++"
	cppdialect "C++20"

	targetdir "$(SolutionDir)build/$(Configuration)/"
	objdir "!$(SolutionDir)build/$(Configuration)/intermediates/"

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
		"%{wks.location}/Mayday-core/src",
		"%{wks.location}/Mayday-core/assets",
		"%{wks.location}/Mayday-core/vendor",
	}

	links 
	{
		"d3d9",
	}

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
