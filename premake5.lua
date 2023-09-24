workspace "Mayday"
	architecture "x64"
	startproject "Mayday-core"

	configurations
	{
		"Debug",
		"Release"
	}

	flags
	{
		"MultiProcessorCompile"
	}


include "Mayday-core"
include "Mayday-client"
