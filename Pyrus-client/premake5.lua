project "Mayday-client"
	kind "WindowedApp"
	staticruntime "on"
	targetname "Mayday-client"

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
		"%{wks.location}/Mayday-client/src",
		"%{wks.location}/Mayday-client/assets",
		"%{wks.location}/Mayday-client/vendor",
		"%{wks.location}/Mayday-core/src",
	}

	libdirs
	{
		"%{wks.location}/Build/$(Configuration)/"
	}

	links 
	{
		"d3d9",
		"Mayday-core",
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
