// APSC 142 Engineering Programming Project Starter Code
// Copyright Sean Kauffman 2024

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <stdio.h>

// make sure not to modify anything in this extern block
extern "C"{
#include "defines.h"
#include "map.h"
#include "actor.h"
#include "game.h"
char *map = NULL, *dot_map = NULL;
int width, height;
}

/**
 * This file is where you should put your tests for your code.
 * Your code must have tests that execute at least 85% of the code in
 * required functions for you to get full marks for the project.
 * Make sure to check out the course videos on automated testing for
 * more information about how to write tests.
 */

/* tests for map.c */
TEST_SUITE_BEGIN("Map tests");

// tests for load_map
TEST_CASE("A test for load_map") {
    CHECK(0 == 0);
}

// tests for is_wall

TEST_SUITE_END();

/* tests for actor.c */
TEST_SUITE_BEGIN("Actor tests");

// tests for sees_player

// tests for move_player

// tests for move_ghost

TEST_SUITE_END();

/* tests for game.c */
TEST_SUITE_BEGIN("check_loss");
TEST_CASE("Basic") {
    int player_y = 0;
    int player_x = 0;
    int ghosts_y[NUM_GHOSTS] = {0,0};
    int ghosts_x[NUM_GHOSTS] = {0,0};
    CHECK(check_loss(player_y, player_x, ghosts_y, ghosts_x) == YOU_LOSE);
    player_y = 1;
    player_x = 1;
    CHECK(check_loss(player_y, player_x, ghosts_y, ghosts_x) == KEEP_GOING);
    ghosts_y[0] = 1;
    ghosts_x[0] = 1;
    CHECK(check_loss(player_y, player_x, ghosts_y, ghosts_x) == YOU_LOSE);
    player_y = 2;
    ghosts_y[1] = 2;
    ghosts_x[1] = 1;
    CHECK(check_loss(player_y, player_x, ghosts_y, ghosts_x) == YOU_LOSE);
}
TEST_CASE("First Ghost") {
    int ghosts_y[NUM_GHOSTS] = {0,0};
    int ghosts_x[NUM_GHOSTS] = {0,0};
    //when first ghost shares player coodinates (c,r)
    for(int r =0; r < height; r++){
        for(int c =0; c <width;c++){
            ghosts_y[0] = r;
            ghosts_x[0] = c;
            ghosts_y[1] = (r+1)%height;
            ghosts_x[1] = (c+1)%width;
            CHECK(check_loss(r,c,ghosts_y,ghosts_x) == YOU_LOSE);
            printf("%d",check_loss(r,c,ghosts_y,ghosts_x));
        }
    }
}
TEST_CASE("Second Ghost") {
    int ghosts_y[NUM_GHOSTS] = {0,0};
    int ghosts_x[NUM_GHOSTS] = {0,0};
    //when seccond ghost shares player coordinates (r,c)
    for(int r =0; r < height; r++) {
        for(int c =0; c <width;c++){
            ghosts_y[1] = r;
            ghosts_x[1] = c;
            ghosts_y[0] = (r+1)%height;
            ghosts_x[0] = (c+1)%width;
            CHECK(check_loss(r,c,ghosts_y,ghosts_x) == YOU_LOSE);
            printf("%d",check_loss(r,c,ghosts_y,ghosts_x));
        }
        printf("\n");

    }
}
TEST_CASE("Both Ghosts") {
    int ghosts_y[NUM_GHOSTS] = {0,0};
    int ghosts_x[NUM_GHOSTS] = {0,0};
    //when both ghosts share player coodinates (r,c)
    for(int r =0; r < height; r++){
        for(int c =0; c <width;c++){
            ghosts_y[1] = r;
            ghosts_x[1] = c;
            ghosts_y[0] = r;
            ghosts_x[0] = c;
            CHECK(check_loss(r,c,ghosts_y,ghosts_x) == YOU_LOSE);
            printf("%d",check_loss(r,c,ghosts_y,ghosts_x));
        }
        printf("\n");
    }
}
TEST_CASE("Neither Ghost") {
    int ghosts_y[NUM_GHOSTS] = {0,0};
    int ghosts_x[NUM_GHOSTS] = {0,0};
    
 //when neither ghosts shares player coodinates (r,c)
 for(int r =0; r < height; r++){
    for(int c =0; c <width;c++){
        ghosts_y[1] = (r+1)%height;
        ghosts_x[1] = (c+1)%width;
        ghosts_y[0] = (r+1)%height;
        ghosts_x[0] = (c+1)%width;
        CHECK(check_loss(r,c,ghosts_y,ghosts_x) == KEEP_GOING);
        printf("%d",check_loss(r,c,ghosts_y,ghosts_x));
    }
     printf("\n");
}
}

TEST_SUITE_END();