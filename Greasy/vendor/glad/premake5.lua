
project "glad"

    language "C"
    architecture "x86_64"

    kind "StaticLib"
    
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
