//
// Created by louis on 22/09/2023.
/** all the functions concerning the main character
**/
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "player.h"
#include "structs.h"

#define DEBUG true

/**
 * init the player
 * return a *Player
 */
Player *init_player() {

        Player *player;

        player = malloc(sizeof(Player));
        if(player == NULL) {
    #if DEBUG
            printf("Allocating memory for player failed.\n");
    #endif
            exit(1);
        }

        player->isAlive = true;
        player->turn = true; // the player attack first
        player->lifepoints = 100;
        player->mana = 100;
        player->defense = 10;
        player->attacks_by_turn = 1;
        player->min_strength = 10;
        player->max_strength = 25;

        init_player_draw(player);

    #if DEBUG
        print_player_stats(player);
    #endif

        return player;
}



void init_player_draw(Player *player) {

    char *draw = "   ^_^   \n  /   \\  \n /     \\ \n|       |\n|   |   |\n|___|___|\n";

    player->draw = malloc(sizeof(draw) + 1);
    strcpy(player->draw, draw);

    if(strlen(player->draw) == 0) {
        printf("Error while drawing the player.\n");
        exit(1);
    }
}



void print_player_stats(Player *player) {

    printf("\nPlayer initialized.\n");
    printf("Player stats :\n"
           "pv : %d\n"
           "mana : %d\n"
           "defense : %d\n", player->lifepoints, player->mana, player->defense);
}


void free_player(Player *player) {
    free(player);

#if DEBUG
    if(player == NULL)   printf("\nplayer correctly free\n");
#endif
}

