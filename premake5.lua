workspace "Fonte"
    configurations { "Debug", "Release" }
    platforms { "x64", "x86" }
    location "build/generated"
    toolset "clang"

    staticruntime "On"
    pic "On"

    filter "configurations:Debug"
        symbols "On"
        runtime "Debug"
    filter "configurations:Release"
        optimize "On"
        runtime "Release"
    filter "configurations:x86"
        architecture "x86"
    filter "configurations:x64"
        architecture "x64"

    startproject "testbed"

group "fonte_sdk"
include "sdk"

group "fonte_sdk/vendor"
include "sdk/vendor/glad"

group "tests"
include "testbed"
