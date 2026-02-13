#include "vtex.h"
#include <stdio.h>

int main() {
    Texture texture = VTEX_LoadPPM("input.ppm");
    
    printf("%*s\n", 3*texture.width*texture.height, texture.data);
    return 0;
}
