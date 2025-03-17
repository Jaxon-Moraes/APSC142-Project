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

// Checks if the player has been caught by a ghost
/*
*player_y is the player's y coordinates (the height)
* player_x is the player's x coordinates(the width)
* ghosts_y is the ghost's y coordinates (the height)
* ghosts_x is the ghost's x coordinates (the width)
* YOU_LOSE 0 is when a ghost catches a player
* KEEP_GOING 1 allows the player to continue playing in the case they are not caught
*/

int check_loss(int player_y, int player_x, int ghosts_y[NUM_GHOSTS], int ghosts_x[NUM_GHOSTS]) {
    for (int i = 0; i < NUM_GHOSTS; i++) {
        if (player_x == ghosts_x[i] && player_y == ghosts_y[i]) {
            return YOU_LOSE;
        }
    }
    return KEEP_GOING;
}

