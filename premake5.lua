
-- Variables
buildDir = "Build/%{cfg.system}-%{cfg.buildcfg}/%{prj.name}/"

-- Project Configuration
workspace "GreasyEngine"
    configurations { "Release", "Debug" }

include "Greasy/vendor/glfw"
include "Greasy/vendor/glad"

project "Greasy"
    kind "SharedLib"
    basedir "Greasy"

    language "C++"
    architecture "x86_64"

    targetdir(buildDir)
    objdir(buildDir .. ".obj")

    files {
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/include/**.hpp"
    }

    includedirs {
        "%{prj.name}/src/",
        "%{prj.name}/include/",
        "%{prj.name}/vendor/glfw/include",
        "%{prj.name}/vendor/glad/include"
    }

    links {
        "glfw",
        "glad"
    }

    filter "configurations:Debug"
        defines { "GR_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        optimize "On"
    
    filter "system:windows"
        cppdialect "C++17"
        defines { "GR_WINDOWS", "GR_DLLEXPORT" }
        systemversion "latest"
    
    filter "system:linux"
        defines { "GR_LINUX" }
        links { "X11", "m", "rt", "GL" }

project "Sandbox"
    kind "ConsoleApp"
    basedir "Sandbox"

    language "C++"
    architecture "x86_64"

    targetdir(buildDir)
    objdir(buildDir .. ".obj")

    files {
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/include/**.hpp"
    }

    includedirs {
        "%{prj.name}/src/",
        "%{prj.name}/include/",
        "Greasy/include/"
    }

    links {
        "Greasy"
    }

    filter "configurations:Debug"
        defines { "GR_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        optimize "On"

    filter "system:windows"
        cppdialect "C++17"
        defines { "GR_WINDOWS" }
        systemversion "latest"
        prebuildcommands {
            "{COPY} %{cfg.buildtarget.directory}../Greasy/Greasy.dll %{cfg.buildtarget.directory}"
        }
    
    filter "system:linux"
        defines { "GR_LINUX" }
        links { "X11", "m", "rt" }
