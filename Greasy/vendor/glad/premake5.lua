
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
