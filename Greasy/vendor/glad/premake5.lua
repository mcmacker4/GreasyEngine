buildDir = "%{wks.location}/Build/%{cfg.system}-%{cfg.buildcfg}/%{prj.name}/"

project "glad"

    language "C"
    architecture "x86_64"

    kind "StaticLib"

    targetdir(buildDir)
    objdir(buildDir .. ".obj")
    
    files { "src/glad.c" }
    includedirs { "include/" }

    filter "configurations:Debug"
        symbols "On"

    filter "configurations:Release"
        optimize "On"

    filter "system:windows"
        systemversion "latest"
        links { "opengl32.lib" }

    filter "system:linux"
        links { "GL" }
        buildoptions { "-fPIC" }
