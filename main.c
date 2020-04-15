#include "vis.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Color color   = {1, 1, 0};
    char* vis_mem = calloc(120 * 160, sizeof(char));

    vis_player_ship(vis_mem, 10, 10);

    // char* pixel = (char*)coord_to_pointer((void*)vis_mem, 0, 1);

    // set_pix(vis_mem, 0, 1, color);

    // for (int i = 0; i < 8; i++) {
    //     printf("%d", !!((*(pixel) << i) & 0x80));
    // }
    // printf("\n");

    return 0;
}