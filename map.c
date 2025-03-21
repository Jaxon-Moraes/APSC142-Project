// APSC 142 Engineering Programming Project Starter Code
// Copyright Sean Kauffman 2024

#include <stdio.h>

#include "defines.h"
#include "colours.h"
#include "map.h"

extern char *map, *dot_map;
extern int width, height;

/**
 * You should use this function to print out individual characters
 * in the colours used in the demo.
 * @param c
 */
static void printc(char c) {
    switch (c) {
        case WALL:
            change_text_colour(BLUE);
            break;
        case GHOST:
            change_text_colour(PINK);
            break;
        case PLAYER:
            change_text_colour(YELLOW);
            break;
        case DOT:
            change_text_colour(WHITE);
            break;
        default:
            change_text_colour(WHITE);
    }
    printf("%c", c);
}

void print_map(void) {
    for (int r = 0; r < width+1;r++){
        printc(WALL);
        printf(" ");

    }
    printc(WALL);
    printf("\n");
    for (int r = 0; r < height; r++){
        printc(WALL);
        printf(" ");
        for (int c = 0; c<width; c++){
            printc(map[r*width+c]);
            printf(" ");
        }
        printc(WALL);
        printf("\n");
    }
    for (int r = 0; r < width+1;r++){
        printc(WALL);
        printf(" ");
    }
    printc(WALL);
    printf("\n");
}

int is_wall(int y, int x) {
    return NOT_WALL;
}

char * load_map(char * filename, int *map_height, int *map_width) {
    return NULL;
}
