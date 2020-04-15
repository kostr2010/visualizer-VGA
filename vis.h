#ifndef VIS_H_INCLUDED
#define VIS_H_INCLUDED

// ====================
// UTILS

typedef enum { false, true } bool;

typedef struct Color {
    bool r, g, b;
} Color;

void* coord_to_pointer(void* mem, int x, int y);

void set_pix(void* mem, int x, int y, Color color);

// ====================
// VISUALIZER

void vis_enemy_corvette(void* mem, int x, int y);
void vis_enemy_projectile(void* mem, int x, int y);
void vis_player_ship(void* mem, int x, int y);
void vis_player_projectile(void* mem, int x, int y);
void vis_start_screen(void* mem);
void vis_death_screen(void* mem);

#endif