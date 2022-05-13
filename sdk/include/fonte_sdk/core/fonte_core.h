#ifndef FONTE_CORE_H
#define FONTE_CORE_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>

/* ========== PLATFORM_DETECTION ========== */
#if !defined(FONTE_PLATFORM_LINUX) || !defined(FONTE_PLATFORM_WINDOWS)
#	if defined(_WIN32)
#		define FONTE_PLATFORM_WINDOWS
#	elif defined(__linux__)
#		define FONTE_PLATFORM_LINUX
#	else
#		error "Platform not supported"
#	endif
#endif
/* ======================================== */

/* ========== SYMBOLS (FOR SCRIPTING) ========== */
#if defined(FONTE_EXPORT_SYMBOLS)
#	undef FONTE_EXPORT_SYMBOLS

#	if defined(FONTE_API)
#		undef FONTE_API
#	endif

#	ifdef FONTE_PLATFORM_WINDOWS
#		define FONTE_API __declspec(dllexport)
#	else
#		define FONTE_API
#	endif

#elif defined(FONTE_IMPORT_SYMBOLS)
#	undef FONTE_IMPORT_SYMBOLS

#	if defined(FONTE_API)
#		undef FONTE_API
#	endif

#	ifdef _WIN32
#		define FONTE_API __declspec(dllimport)
#	else
#		define FONTE_API
#	endif
#else
#	define FONTE_API
#endif

#if !defined(FONTE_CALL)
#	ifdef _MSC_VER
#		define FONTE_CALL __cdecl
#	else
#		define FONTE_CALL
#	endif
#endif
/* ============================================= */

/* ========== LOGGING AND ASSERT ========== */
#ifndef FONTE_RELEASE
#	define FONTE_INFO(...) 		fonte_log_info(__FILE__, __LINE__, __VA_ARGS__)
#	define FONTE_WARNING(...) 	fonte_log_warning(__FILE__, __LINE__, __VA_ARGS__)
#	define FONTE_ERROR(...) 	fonte_log_error(__FILE__, __LINE__, __VA_ARGS__)
#	define FONTE_ASSERT(cond, msg)										\
		if (!(cond)) {													\
			printf(_IMPL_LOG_DECORATOR("assertion failed") msg "\n");	\
			exit(EXIT_FAILURE);											\
		}
#else
#	define FONTE_INFO(...)
#	define FONTE_WARNING(...)
#	define FONTE_ERROR(...)
#	define
#endif

FONTE_API void fonte_log_info	(const char *file, int line, const char *format, ...);
FONTE_API void fonte_log_warning(const char *file, int line, const char *format, ...);
FONTE_API void fonte_log_error	(const char *file, int line, const char *format, ...);
/* ======================================== */

/* ========== ALLOCATOR ========== */
#ifndef FONTE_CUSTOM_ALLOCATOR
#	define FONTE_ALLOCATE(mem_size)				malloc(mem_size)
#	define FONTE_REALLOCATE(ptr, new_mem_size)	realloc((void *)ptr, new_mem_size)
#	define FONTE_DEALLOCATE(ptr)				free((void *)ptr)
#endif
#define FONTE_NEW(T)							(T *)FONTE_ALLOCATE(sizeof(T))
#define FONTE_NEW_BUFFER(T, len) 				(T *)FONTE_ALLOCATE(sizeof(T) * len)
#define FONTE_RESIZE_BUFFER(T, buf, new_len)	(T *)FONTE_REALLOCATE(buf, sizeof(T) * new_len)
#define FONTE_DELETE(obj)						FONTE_DEALLOCATE(obj)
/* =============================== */

/* ========== FILESYSTEM ========== */

typedef enum fonte_file_mode_e {
	FONTE_FILE_MODE_READ = 0x1,
	FONTE_FILE_MODE_WRITE = 0x2,
	FONTE_FILE_MODE_BINARY = 0x3
} fonte_file_mode_e;

typedef struct fonte_file_t {
	void *handle;
	bool is_valid;
} fonte_file_t;

FONTE_API fonte_file_t fonte_filesystem_open(const char *path, fonte_file_mode_e mode);

/* ================================ */

#endif
