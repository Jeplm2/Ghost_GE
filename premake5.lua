workspace "Ghost"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Ghost"
    location "Ghost"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .."/%{prj.name}")
    targetdir ("bin-int/" .. outputdir .."/%{prj.name}")

    files
    {
        "/%{prj.name}/src/**.h",
        "/%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/src/"
    }

    filter "system:linux"
        cppdialect "C++17"
        staticruntime "On"

        defines
        {
            GHOST_PLATFORM_LINUX,
            GHOST_API
        }

    filter "configurations:Debug"
        defines "GHOST_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "GHOST_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "GHOST_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .."/%{prj.name}")
    targetdir ("bin-int/" .. outputdir .."/%{prj.name}")

    files
    {
        "/%{prj.name}/src/**.h",
        "/%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "Ghost/src"
    }

    links
    {
        "Ghost"
    }

    filter "system:linux"
        cppdialect "C++17"
        staticruntime "On"

        defines
        {
            GHOST_PLATFORM_LINUX,
        }

    filter "configurations:Debug"
        defines "GHOST_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "GHOST_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "GHOST_DIST"
        optimize "On"