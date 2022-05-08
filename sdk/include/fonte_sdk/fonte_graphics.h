#ifndef FONTE_GRAPHICS_H
#define FONTE_GRAPHICS_H

typedef enum fonte_graphics_api_e {
    FONTE_GRAPHICS_API_OPENGL
    FONTE_GRAPHICS_API_VULKAN,
    FONTE_GRAPHICS_API_DIRECTX
} fonte_graphics_api_e;

typedef struct fonte_graphics_opengl_settings_t {
    uint32_t version_major;
    uint32_t version_minor;
    uint8_t multi_sampling_count;
    void *context;
} fonte_graphics_opengl_settings_t;

typedef struct fonte_graphics_api_settings_t {
    bool vsync;
    bool debug;
    fonte_graphics_api_e graphics_api;
    union {
        fonte_graphics_opengl_settings_t opengl_settings;
    };
} fonte_graphics_api_settings_t;


#endif
