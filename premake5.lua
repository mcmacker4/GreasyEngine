
-- Variables
buildDir = "Build/%{cfg.system}-%{cfg.buildcfg}/%{prj.name}/"

-- Project Configuration
workspace "GreasyEngine"
    configurations { "Release", "Debug" }

include "Greasy/vendor/glfw"

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
        "%{prj.name}/vendor/GLFW/include"
    }

    links {
        "GLFW"
    }

    filter "configurations:Debug"
        defines { "GR_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        optimize "On"
    
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        defines { "GR_WINDOWS", "GR_DLLEXPORT" }
        systemversion "latest"
    
    filter "system:linux"
        defines { "GR_LINUX" }

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

    prebuildcommands {
        "{COPY} %{cfg.buildtarget.directory}../Greasy/Greasy.dll %{cfg.buildtarget.directory}"
    }

    filter "configurations:Debug"
        defines { "GR_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        optimize "On"

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        defines { "GR_WINDOWS" }
        systemversion "latest"
--        prebuildcommands {
--            "{COPY} Build/%{cfg.system}-%{cfg.buildcfg}/Greasy/Greasy.dll Build/%{cfg.system}-%{cfg.buildcfg}/%{prj.name}/Greasy.dll"
--        }
    
    filter "system:linux"
        defines { "GR_LINUX" }