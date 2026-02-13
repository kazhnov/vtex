#include <stdint.h>

typedef struct {
    uint8_t *data;
    uint32_t width;
    uint32_t height;
} Texture;

Texture VTEX_LoadPPM(char* path);
