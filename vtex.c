#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "vtex.h"


Texture VTEX_LoadPPM(char* path) {
    FILE* file = fopen(path, "rb");
    printf("Loading texture %s... ", path);
    int max_value;
    Texture texture;
    
    int8_t c = fgetc(file);
    assert(c == 'P');
    c = fgetc(file);
    assert(c == '6');
    fgetc(file);
    
    fscanf(file, "%d %d", &texture.width, &texture.height);
    texture.data = calloc(sizeof(uint8_t), 3*texture.width*texture.height);
    fgetc(file);
    
    fscanf(file, "%d", &max_value);
    if (max_value != 255) {
	fprintf(stderr, "ERROR: Not supported max value\n");
	exit(1);
    }
    fgetc(file);

    int count = 0;
    while((c = fgetc(file)) != EOF) {
	texture.data[count++] = c;
    }
    if (count != texture.width*texture.height*3) {
	fprintf(stderr, "ERROR: Expected %d pixels, got %d\n", texture.width*texture.height, count/3);
    }
    
    fclose(file);
    printf("DONE\n");
    return texture;
}
