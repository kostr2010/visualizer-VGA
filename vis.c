#include "vis.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void *vis_mem = (void *)0xEEEE0000; // 160x120 pix, each pixel - 8 bit

const int width  = 160;
const int height = 120;

// ====================
// UTILS

void* coord_to_pointer(void* mem, int x, int y) {
    return mem + sizeof(char) * 120 * y + sizeof(char) * x;
}

void set_pix(void* mem, int x, int y, Color color) {
    void* pixel_old = coord_to_pointer(mem, x, y);
    char  pixel_new =
        0 << 7 | 0 << 6 | 0 << 5 | 0 << 4 | 0 << 3 | color.b << 2 | color.g << 1 | color.r << 0;

    memcpy(pixel_old, &pixel_new, 1);
}

// ====================
// VISUALIZER

void vis_enemy_corvette(void* mem, int x, int y) {
    if (!(x >= 4 && x <= width - 5 && y >= 6 && y <= height - 7))
        return;

    Color color = {0, 0, 1};

    set_pix(mem, x, y, color);
    set_pix(mem, x, y + 1, color);
    set_pix(mem, x, y + 2, color);
    set_pix(mem, x, y + 3, color);
    set_pix(mem, x, y + 4, color);
    set_pix(mem, x, y - 1, color);
    set_pix(mem, x, y - 2, color);
    set_pix(mem, x, y - 3, color);
    set_pix(mem, x + 1, y, color);
    set_pix(mem, x + 1, y - 2, color);
    set_pix(mem, x + 1, y - 3, color);
    set_pix(mem, x + 1, y - 4, color);
    set_pix(mem, x + 1, y + 1, color);
    set_pix(mem, x + 1, y + 2, color);
    set_pix(mem, x - 1, y, color);
    set_pix(mem, x - 1, y - 2, color);
    set_pix(mem, x - 1, y - 3, color);
    set_pix(mem, x - 1, y - 4, color);
    set_pix(mem, x - 1, y + 1, color);
    set_pix(mem, x - 1, y + 2, color);
    set_pix(mem, x + 2, y, color);
    set_pix(mem, x + 2, y - 1, color);
    set_pix(mem, x + 2, y - 2, color);
    set_pix(mem, x + 2, y + 1, color);
    set_pix(mem, x + 2, y + 2, color);
    set_pix(mem, x + 2, y + 3, color);
    set_pix(mem, x - 2, y, color);
    set_pix(mem, x - 2, y - 1, color);
    set_pix(mem, x - 2, y - 2, color);
    set_pix(mem, x - 2, y + 1, color);
    set_pix(mem, x - 2, y + 2, color);
    set_pix(mem, x - 2, y + 3, color);
    set_pix(mem, x + 3, y, color);
    set_pix(mem, x + 3, y - 1, color);
    set_pix(mem, x + 3, y - 4, color);
    set_pix(mem, x + 3, y + 1, color);
    set_pix(mem, x + 3, y + 3, color);
    set_pix(mem, x - 3, y, color);
    set_pix(mem, x - 3, y - 1, color);
    set_pix(mem, x - 3, y - 4, color);
    set_pix(mem, x - 3, y + 1, color);
    set_pix(mem, x - 3, y + 3, color);
    set_pix(mem, x + 4, y, color);
    set_pix(mem, x + 4, y + 4, color);
    set_pix(mem, x + 4, y - 2, color);
    set_pix(mem, x + 4, y - 3, color);
    set_pix(mem, x - 4, y, color);
    set_pix(mem, x - 4, y + 4, color);
    set_pix(mem, x - 4, y - 2, color);
    set_pix(mem, x - 4, y - 3, color);
    set_pix(mem, x + 5, y + 1, color);
    set_pix(mem, x + 5, y + 2, color);
    set_pix(mem, x + 5, y - 4, color);
    set_pix(mem, x - 5, y + 1, color);
    set_pix(mem, x - 5, y + 2, color);
    set_pix(mem, x - 5, y - 4, color);
    set_pix(mem, x + 6, y + 3, color);
    set_pix(mem, x - 6, y - 3, color);
}

void vis_enemy_projectile(void* mem, int x, int y) {
    if (!(x >= 1 && x <= width - 2 && y >= 1 && y <= height - 2))
        return;

    Color color = {0, 0, 1};

    set_pix(mem, x, y, color);
    set_pix(mem, x, y + 1, color);
    set_pix(mem, x, y - 1, color);
    set_pix(mem, x + 1, y + 1, color);
    set_pix(mem, x + 1, y - 1, color);
    set_pix(mem, x - 1, y + 1, color);
    set_pix(mem, x - 1, y - 1, color);
    set_pix(mem, x + 1, y, color);
    set_pix(mem, x - 1, y, color);
}

void vis_player_ship(void* mem, int x, int y) {
    if (!(x >= 8 && x <= width - 9 && y >= 4 && y <= height - 5))
        return;

    Color color = {1, 1, 1};

    set_pix(mem, x, y, color);
    set_pix(mem, x, y + 1, color);
    set_pix(mem, x, y + 2, color);
    set_pix(mem, x, y + 4, color);
    set_pix(mem, x, y - 1, color);
    set_pix(mem, x, y - 2, color);
    set_pix(mem, x, y - 3, color);
    set_pix(mem, x + 2, y, color);
    set_pix(mem, x - 2, y, color);
    set_pix(mem, x - 1, y - 1, color);
    set_pix(mem, x - 2, y - 1, color);
    set_pix(mem, x + 1, y - 1, color);
    set_pix(mem, x + 2, y - 1, color);
    set_pix(mem, x - 1, y - 2, color);
    set_pix(mem, x - 2, y - 2, color);
    set_pix(mem, x + 1, y - 2, color);
    set_pix(mem, x + 2, y - 2, color);
    set_pix(mem, x - 1, y - 3, color);
    set_pix(mem, x + 1, y - 3, color);
    set_pix(mem, x + 1, y + 4, color);
    set_pix(mem, x - 1, y + 4, color);
    set_pix(mem, x + 2, y + 4, color);
    set_pix(mem, x + 2, y + 3, color);
    set_pix(mem, x + 2, y + 2, color);
    set_pix(mem, x - 2, y + 4, color);
    set_pix(mem, x - 2, y + 3, color);
    set_pix(mem, x - 2, y + 2, color);
    set_pix(mem, x + 3, y - 4, color);
    set_pix(mem, x + 3, y + 2, color);
    set_pix(mem, x + 3, y + 3, color);
    set_pix(mem, x - 3, y - 4, color);
    set_pix(mem, x - 3, y + 2, color);
    set_pix(mem, x - 3, y + 3, color);
    set_pix(mem, x + 4, y + 1, color);
    set_pix(mem, x + 4, y, color);
    set_pix(mem, x + 4, y - 1, color);
    set_pix(mem, x + 4, y - 2, color);
    set_pix(mem, x + 4, y - 3, color);
    set_pix(mem, x + 4, y - 4, color);
    set_pix(mem, x - 4, y + 1, color);
    set_pix(mem, x - 4, y, color);
    set_pix(mem, x - 4, y - 1, color);
    set_pix(mem, x - 4, y - 2, color);
    set_pix(mem, x - 4, y - 3, color);
    set_pix(mem, x - 4, y - 4, color);
    set_pix(mem, x + 5, y - 3, color);
    set_pix(mem, x - 5, y - 3, color);
    set_pix(mem, x + 6, y + 1, color);
    set_pix(mem, x + 6, y, color);
    set_pix(mem, x + 6, y - 1, color);
    set_pix(mem, x + 6, y - 2, color);
    set_pix(mem, x + 6, y - 3, color);
    set_pix(mem, x - 6, y + 1, color);
    set_pix(mem, x - 6, y, color);
    set_pix(mem, x - 6, y - 1, color);
    set_pix(mem, x - 6, y - 2, color);
    set_pix(mem, x - 6, y - 3, color);
    set_pix(mem, x + 7, y, color);
    set_pix(mem, x + 7, y - 1, color);
    set_pix(mem, x + 7, y - 2, color);
    set_pix(mem, x + 7, y - 3, color);
    set_pix(mem, x + 7, y - 4, color);
    set_pix(mem, x - 7, y, color);
    set_pix(mem, x - 7, y - 1, color);
    set_pix(mem, x - 7, y - 2, color);
    set_pix(mem, x - 7, y - 3, color);
    set_pix(mem, x - 7, y - 4, color);
    set_pix(mem, x + 8, y + 1, color);
    set_pix(mem, x + 8, y, color);
    set_pix(mem, x + 8, y - 1, color);
    set_pix(mem, x + 8, y - 2, color);
    set_pix(mem, x + 8, y - 3, color);
    set_pix(mem, x - 8, y + 1, color);
    set_pix(mem, x - 8, y, color);
    set_pix(mem, x - 8, y - 1, color);
    set_pix(mem, x - 8, y - 2, color);
    set_pix(mem, x - 8, y - 3, color);
}

void vis_player_projectile(void* mem, int x, int y) {
    if (!(x >= 0 && x <= width - 1 && y >= 2 && y <= height - 3))
        return;

    Color color = {1, 1, 1};

    set_pix(mem, x, y + 2, color);
    set_pix(mem, x, y + 1, color);
    set_pix(mem, x, y, color);
    set_pix(mem, x, y - 1, color);
    set_pix(mem, x, y - 2, color);
}

void vis_start_screen(void* mem) {
    /*
     */
}

void vis_death_screen(void* mem) {
    Color color = {1, 1, 1};

    int x = 10, y = 70;

    set_pix(mem, x + 6, y - 3, color);
    set_pix(mem, x + 6, y - 4, color);
    set_pix(mem, x + 6, y - 5, color);
    set_pix(mem, x + 6, y - 6, color);
    set_pix(mem, x + 6, y - 7, color);
    set_pix(mem, x + 6, y - 8, color);
    set_pix(mem, x + 7, y - 7, color);
    set_pix(mem, x + 7, y - 8, color);
    set_pix(mem, x + 7, y - 9, color);
    set_pix(mem, x + 7, y - 10, color);
    set_pix(mem, x + 7, y - 11, color);
    set_pix(mem, x + 8, y - 11, color);
    set_pix(mem, x + 8, y - 12, color);
    set_pix(mem, x + 9, y - 11, color);
    set_pix(mem, x + 9, y - 12, color);
    set_pix(mem, x + 10, y - 10, color);
    set_pix(mem, x + 10, y - 11, color);
    set_pix(mem, x + 11, y - 10, color);
    set_pix(mem, x + 11, y - 11, color);
    set_pix(mem, x + 12, y - 3, color);
    set_pix(mem, x + 12, y - 4, color);
    set_pix(mem, x + 12, y - 5, color);
    set_pix(mem, x + 12, y - 9, color);
    set_pix(mem, x + 12, y - 10, color);
    set_pix(mem, x + 13, y - 5, color);
    set_pix(mem, x + 13, y - 6, color);
    set_pix(mem, x + 13, y - 9, color);
    set_pix(mem, x + 13, y - 17, color);
    set_pix(mem, x + 13, y - 18, color);
    set_pix(mem, x + 13, y - 19, color);
    set_pix(mem, x + 13, y - 9, color);
    set_pix(mem, x + 14, y - 6, color);
    set_pix(mem, x + 14, y - 8, color);
    set_pix(mem, x + 14, y - 9, color);
    set_pix(mem, x + 14, y - 15, color);
    set_pix(mem, x + 14, y - 16, color);
    set_pix(mem, x + 14, y - 17, color);
    set_pix(mem, x + 14, y - 18, color);
    set_pix(mem, x + 14, y - 19, color);
    set_pix(mem, x + 14, y - 20, color);
    set_pix(mem, x + 15, y - 6, color);
    set_pix(mem, x + 15, y - 7, color);
    set_pix(mem, x + 15, y - 8, color);
    set_pix(mem, x + 15, y - 9, color);
    set_pix(mem, x + 15, y - 12, color);
    set_pix(mem, x + 15, y - 14, color);
    set_pix(mem, x + 15, y - 15, color);
    set_pix(mem, x + 15, y - 16, color);
    set_pix(mem, x + 15, y - 17, color);
    set_pix(mem, x + 15, y - 18, color);
    set_pix(mem, x + 15, y - 19, color);
    set_pix(mem, x + 15, y - 20, color);
    set_pix(mem, x + 15, y - 21, color);
    set_pix(mem, x + 16, y - 3, color);
    set_pix(mem, x + 16, y - 4, color);
    set_pix(mem, x + 16, y - 8, color);
    set_pix(mem, x + 16, y - 9, color);
    set_pix(mem, x + 16, y - 12, color);
    set_pix(mem, x + 16, y - 14, color);
    set_pix(mem, x + 16, y - 15, color);
    set_pix(mem, x + 16, y - 19, color);
    set_pix(mem, x + 16, y - 20, color);
    set_pix(mem, x + 16, y - 21, color);
    set_pix(mem, x + 17, y - 4, color);
    set_pix(mem, x + 17, y - 5, color);
    set_pix(mem, x + 17, y - 6, color);
    set_pix(mem, x + 17, y - 7, color);
    set_pix(mem, x + 17, y - 8, color);
    set_pix(mem, x + 17, y - 9, color);
    set_pix(mem, x + 17, y - 10, color);
    set_pix(mem, x + 17, y - 11, color);
    set_pix(mem, x + 17, y - 12, color);
    set_pix(mem, x + 17, y - 14, color);
    set_pix(mem, x + 17, y - 15, color);
    set_pix(mem, x + 17, y - 19, color);
    set_pix(mem, x + 17, y - 20, color);
    set_pix(mem, x + 17, y - 21, color);
    set_pix(mem, x + 17, y - 22, color);
    set_pix(mem, x + 18, y - 8, color);
    set_pix(mem, x + 18, y - 9, color);
    set_pix(mem, x + 18, y - 10, color);
    set_pix(mem, x + 18, y - 11, color);
    set_pix(mem, x + 18, y - 12, color);
    set_pix(mem, x + 18, y - 14, color);
    set_pix(mem, x + 18, y - 15, color);
    set_pix(mem, x + 18, y - 19, color);
    set_pix(mem, x + 18, y - 20, color);
    set_pix(mem, x + 18, y - 21, color);
    set_pix(mem, x + 18, y - 22, color);
    set_pix(mem, x + 18, y - 23, color);
    set_pix(mem, x + 19, y - 4, color);
    set_pix(mem, x + 19, y - 5, color);
    set_pix(mem, x + 19, y - 6, color);
    set_pix(mem, x + 19, y - 7, color);
    set_pix(mem, x + 19, y - 8, color);
    set_pix(mem, x + 19, y - 9, color);
    set_pix(mem, x + 19, y - 10, color);
    set_pix(mem, x + 19, y - 11, color);
    set_pix(mem, x + 19, y - 12, color);
    set_pix(mem, x + 19, y - 14, color);
    set_pix(mem, x + 19, y - 15, color);
    set_pix(mem, x + 19, y - 16, color);
    set_pix(mem, x + 19, y - 20, color);
    set_pix(mem, x + 19, y - 21, color);
    set_pix(mem, x + 19, y - 22, color);
    set_pix(mem, x + 19, y - 23, color);
    set_pix(mem, x + 19, y - 24, color);
    set_pix(mem, x + 20, y - 3, color);
    set_pix(mem, x + 20, y - 4, color);
    set_pix(mem, x + 20, y - 8, color);
    set_pix(mem, x + 20, y - 9, color);
    set_pix(mem, x + 20, y - 12, color);
    set_pix(mem, x + 20, y - 13, color);
    set_pix(mem, x + 20, y - 15, color);
    set_pix(mem, x + 20, y - 16, color);
    set_pix(mem, x + 20, y - 19, color);
    set_pix(mem, x + 20, y - 20, color);
    set_pix(mem, x + 20, y - 21, color);
    set_pix(mem, x + 20, y - 22, color);
    set_pix(mem, x + 20, y - 23, color);
    set_pix(mem, x + 20, y - 24, color);
    set_pix(mem, x + 21, y - 6, color);
    set_pix(mem, x + 21, y - 7, color);
    set_pix(mem, x + 21, y - 8, color);
    set_pix(mem, x + 21, y - 12, color);
    set_pix(mem, x + 21, y - 13, color);
    set_pix(mem, x + 21, y - 14, color);
    set_pix(mem, x + 21, y - 19, color);
    set_pix(mem, x + 21, y - 20, color);
    set_pix(mem, x + 21, y - 21, color);
    set_pix(mem, x + 21, y - 23, color);
    set_pix(mem, x + 21, y - 24, color);
    set_pix(mem, x + 21, y - 25, color);
    set_pix(mem, x + 21, y - 28, color);
    set_pix(mem, x + 22, y - 6, color);
    set_pix(mem, x + 22, y - 8, color);
    set_pix(mem, x + 22, y - 9, color);
    set_pix(mem, x + 22, y - 14, color);
    set_pix(mem, x + 22, y - 15, color);
    set_pix(mem, x + 22, y - 16, color);
    set_pix(mem, x + 22, y - 17, color);
    set_pix(mem, x + 22, y - 19, color);
    set_pix(mem, x + 22, y - 20, color);
    set_pix(mem, x + 22, y - 21, color);
    set_pix(mem, x + 22, y - 24, color);
    set_pix(mem, x + 22, y - 25, color);
    set_pix(mem, x + 22, y - 27, color);
    set_pix(mem, x + 22, y - 28, color);
    set_pix(mem, x + 22, y - 29, color);
    set_pix(mem, x + 23, y - 5, color);
    set_pix(mem, x + 23, y - 6, color);
    set_pix(mem, x + 23, y - 9, color);
    set_pix(mem, x + 23, y - 10, color);
    set_pix(mem, x + 23, y - 16, color);
    set_pix(mem, x + 23, y - 17, color);
    set_pix(mem, x + 23, y - 19, color);
    set_pix(mem, x + 23, y - 20, color);
    set_pix(mem, x + 23, y - 23, color);
    set_pix(mem, x + 23, y - 24, color);
    set_pix(mem, x + 23, y - 25, color);
    set_pix(mem, x + 23, y - 26, color);
    set_pix(mem, x + 23, y - 27, color);
    set_pix(mem, x + 23, y - 29, color);
    set_pix(mem, x + 23, y - 30, color);
    set_pix(mem, x + 24, y - 3, color);
    set_pix(mem, x + 24, y - 4, color);
    set_pix(mem, x + 24, y - 5, color);
    set_pix(mem, x + 24, y - 10, color);
    set_pix(mem, x + 24, y - 11, color);
    set_pix(mem, x + 24, y - 12, color);
    set_pix(mem, x + 24, y - 16, color);
    set_pix(mem, x + 24, y - 17, color);
    set_pix(mem, x + 24, y - 19, color);
    set_pix(mem, x + 24, y - 20, color);
    set_pix(mem, x + 24, y - 22, color);
    set_pix(mem, x + 24, y - 25, color);
    set_pix(mem, x + 24, y - 26, color);
    set_pix(mem, x + 24, y - 28, color);
    set_pix(mem, x + 24, y - 29, color);
    set_pix(mem, x + 25, y - 12, color);
    set_pix(mem, x + 25, y - 13, color);
    set_pix(mem, x + 25, y - 15, color);
    set_pix(mem, x + 25, y - 16, color);
    set_pix(mem, x + 25, y - 17, color);
    set_pix(mem, x + 25, y - 19, color);
    set_pix(mem, x + 25, y - 23, color);
    set_pix(mem, x + 25, y - 24, color);
    set_pix(mem, x + 25, y - 25, color);
    set_pix(mem, x + 25, y - 26, color);
    set_pix(mem, x + 25, y - 27, color);
    set_pix(mem, x + 25, y - 28, color);
    set_pix(mem, x + 26, y - 4, color);
    set_pix(mem, x + 26, y - 5, color);
    set_pix(mem, x + 26, y - 6, color);
    set_pix(mem, x + 26, y - 12, color);
    set_pix(mem, x + 26, y - 13, color);
    set_pix(mem, x + 26, y - 16, color);
    set_pix(mem, x + 26, y - 17, color);
    set_pix(mem, x + 26, y - 22, color);
    set_pix(mem, x + 26, y - 25, color);
    set_pix(mem, x + 26, y - 26, color);
    set_pix(mem, x + 26, y - 28, color);
    set_pix(mem, x + 26, y - 29, color);
    set_pix(mem, x + 27, y - 2, color);
    set_pix(mem, x + 27, y - 3, color);
    set_pix(mem, x + 27, y - 4, color);
    set_pix(mem, x + 27, y - 6, color);
    set_pix(mem, x + 27, y - 9, color);
    set_pix(mem, x + 27, y - 10, color);
    set_pix(mem, x + 27, y - 11, color);
    set_pix(mem, x + 27, y - 12, color);
    set_pix(mem, x + 27, y - 17, color);
    set_pix(mem, x + 27, y - 18, color);
    set_pix(mem, x + 27, y - 23, color);
    set_pix(mem, x + 27, y - 24, color);
    set_pix(mem, x + 27, y - 25, color);
    set_pix(mem, x + 27, y - 26, color);
    set_pix(mem, x + 27, y - 27, color);
    set_pix(mem, x + 27, y - 29, color);
    set_pix(mem, x + 27, y - 30, color);
    set_pix(mem, x + 28, y - 2, color);
    set_pix(mem, x + 28, y - 3, color);
    set_pix(mem, x + 28, y - 4, color);
    set_pix(mem, x + 28, y - 5, color);
    set_pix(mem, x + 28, y - 6, color);
    set_pix(mem, x + 28, y - 7, color);
    set_pix(mem, x + 28, y - 8, color);
    set_pix(mem, x + 28, y - 9, color);
    set_pix(mem, x + 28, y - 18, color);
    set_pix(mem, x + 28, y - 27, color);
    set_pix(mem, x + 28, y - 28, color);
    set_pix(mem, x + 28, y - 29, color);
    set_pix(mem, x + 29, y - 2, color);
    set_pix(mem, x + 29, y - 3, color);
    set_pix(mem, x + 29, y - 4, color);
    set_pix(mem, x + 29, y - 6, color);
    set_pix(mem, x + 29, y - 28, color);
    set_pix(mem, x + 30, y - 4, color);
    set_pix(mem, x + 30, y - 5, color);
    set_pix(mem, x + 30, y - 6, color);
}
