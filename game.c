// APSC 142 Engineering Programming Project Starter Code
// Copyright Sean Kauffman 2024

#include "defines.h"
#include "game.h"

extern char * map, * dot_map;
extern int height;
extern int width;

int check_win(void) {
    return KEEP_GOING;
}

int check_loss(int player_y, int player_x, int ghosts_y[NUM_GHOSTS], int ghosts_x[NUM_GHOSTS]) {
    return KEEP_GOING;
}

