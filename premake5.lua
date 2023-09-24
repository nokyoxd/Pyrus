require "codeblocks"

workspace "Pyrus"
	architecture "x64"
	startproject "Pyrus-client"
	toolset "gcc"

	configurations
	{
		"Debug",
		"Release"
	}

	flags
	{
		"MultiProcessorCompile"
	}


include "Pyrus-core"
include "Pyrus-client"
