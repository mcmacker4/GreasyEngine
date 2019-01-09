
-- Variables
buildDir = "Build/%{cfg.system}-%{cfg.buildcfg}/%{prj.name}/"

-- Project Configuration
workspace "GreasyEngine"
    configurations { "Release", "Debug" }

include "Greasy/vendor/sdl"

project "Greasy"
    kind "SharedLib"
    basedir "Greasy"

    targetdir(buildDir)
    objdir(buildDir .. ".obj")

    files {
        "./Source/**.cpp",
        "./Source/**.hpp"
    }

    links {
        "SDL"
    }

    filter "configurations:Debug"
        defines { "GR_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        optimize "On"

project "Sandbox"
    kind "ConsoleApp"
    basedir "Sandbox"

    targetdir(buildDir)
    objdir(buildDir .. ".obj")

    files {
        "./Source/**.cpp",
        "./Source/**.hpp"
    }

    links {
        "Greasy"
    }

    filter "configurations:Debug"
        defines { "GR_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        optimize "On"