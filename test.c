#include "vtex.h"
#include <stdio.h>

int main() {
    Texture texture = VTEX_LoadPPM("textures/default.ppm");

    for (int i = 0; i < texture.width*texture.height; i++) {
	printf("%d %d %d\n",
	       (int)texture.data[3*i+0],
	       (int)texture.data[3*i+1],
	       (int)texture.data[3*i+2]
	    );
    }
    return 0;
}
