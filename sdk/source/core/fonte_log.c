#include <fonte_sdk/fonte_core.h>

#if defined(FONTE_PLATFORM_LINUX)

#define ANSI_COLOR_RESET "\033[0m"
#define ANSI_COLOR_GREEN "\033[32m"
#define ANSI_COLOR_YELLOW "\033[33m"
#define ANSI_COLOR_RED "\033[31m"

void fonte_log_info(const char *file, int line, const char *format, ...) {
    char final_format[1024];
    char time_format[64];
    time_t t;
    struct tm *current_time;
    va_list arg;

    t = time(NULL);
    current_time = localtime(&t);

    time_format[strftime(time_format, sizeof(time_format), "%Y-%m-%d %H:%M:%S", current_time)] = '\0';
    snprintf(final_format, 1024, ANSI_COLOR_GREEN "%s %s:%d INFO: %s\n" ANSI_COLOR_RESET, time_format, file, line, format);

    va_start(arg, format);
    vprintf(final_format, arg);
    va_end(arg);
}

void fonte_log_warning(const char *file, int line, const char *format, ...) {
    char final_format[1024];
    char time_format[64];
    time_t t;
    struct tm *current_time;
    va_list arg;

    t = time(NULL);
    current_time = localtime(&t);

    time_format[strftime(time_format, sizeof(time_format), "%Y-%m-%d %H:%M:%S", current_time)] = '\0';
    snprintf(final_format, 1024, ANSI_COLOR_YELLOW "%s %s:%d WARNING: %s\n" ANSI_COLOR_RESET, time_format, file, line, format);

    va_start(arg, format);
    vprintf(final_format, arg);
    va_end(arg);
}

void fonte_log_error(const char *file, int line, const char *format, ...) {
    char final_format[1024];
    char time_format[64];
    time_t t;
    struct tm *current_time;
    va_list arg;

    t = time(NULL);
    current_time = localtime(&t);

    time_format[strftime(time_format, sizeof(time_format), "%Y-%m-%d %H:%M:%S", current_time)] = '\0';
    snprintf(final_format, 1024, ANSI_COLOR_RED "%s %s:%d ERROR: %s\n" ANSI_COLOR_RESET, time_format, file, line, format);

    va_start(arg, format);
    vprintf(final_format, arg);
    va_end(arg);
}

#elif defined(FONTE_PLATFORM_WINDOWS)

#else

#error "Platform not supported"

#endif
