project "FonteTestbed"
    kind "ConsoleApp"
    language "C"
    cdialect "C99"

    targetdir "../build/"
    objdir "../build/obj/"

    files { "**.c", "**.h" }
    includedirs { "../sdk/include/" }
    links {
        "FonteSDK"
    }
    defines { "FONTE_IMPORT_SYMBOLS" }
