project "Glad"
	kind "StaticLib"
	language "C"

	targetdir "../../../build/vendor/"
	objdir "../../../build/obj/"

	files {
		"gl.h",
        "gl.c"
	}
