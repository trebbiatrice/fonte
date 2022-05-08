project "FonteSDK"
    kind "SharedLib"
    language "C"
    cdialect "C99"

    targetdir "../build/"
    objdir "../build/obj/"

    files { "source/**.c", "include/**.h" }
    includedirs { "include/" }
    links {
        "Glad"
    }
    defines { "FONTE_EXPORT_SYMBOLS" }

    --filter "configurations:Debug"
        defines { "FONTE_DEBUG" }
    filter "configurations:Release"
        defines { "FONTE_RELEASE" }

	filter "system:linux"
		links {
			"pthread",
			"dl",
			"X11",
			"m",
			"GL",
		}

	filter "system:windows"
        defines { "_CRT_SECURE_NO_WARNINGS" }
		links {
			"opengl32",
			"gdi32",
			"user32",
			"kernel32"
		}
