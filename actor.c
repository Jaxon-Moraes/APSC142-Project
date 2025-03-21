// APSC 142 Engineering Programming Project Starter Code
// Copyright Sean Kauffman 2024

#include "defines.h"
#include "actor.h"
#include <stdlib.h>

extern char *map, *dot_map; // global map array
extern int width;
extern int height;


char sees_player(int player_y, int player_x, int ghost_y, int ghost_x) {
    return SEES_NOTHING;
}

int move_player(int *player_y, int *player_x, char direction) {
    int new_x = *player_x;
    int new_y = *player_y;

    //Determine new position based on input directions
    switch(direction){
        case 'w': new_y--; break; // Move up
        case 's': new_y++; break; // Move down
        case 'a': new_x--; break; // Move left
        case 'd': new_x++; break; // Move right
        default: return MOVED_INVALID_DIRECTION; // Invalid input
    }

    // Check if the new position is within the bounds (not a wall)
    if ((new_x >= 0) && (new_x < width) && (new_y >= 0) && (new_y < height)){
        if((map[((new_y * width) + new_x)%(width*height)] != WALL)) {
            dot_map[new_y * width + new_x] = EMPTY;
            map[new_y * width + new_x] = PLAYER;
            map[*player_y * width + (*player_x)] = EMPTY;
            *player_x = new_x;
            *player_y = new_y;
            return MOVED_OKAY; // Success!
        }
    }

    return MOVED_WALL;

}

int move_ghost(int * y, int * x, char direction) {
    return MOVED_OKAY;
}
