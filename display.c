//
// Created by louis on 22/09/2023.
//
#include <stdio.h>
#include "display.h"
#include "player.h"
#include "colors.h"


void display_init_menu() {
    printf("----Doomdepths----\n");
    printf("Play from last save (1)\n");
    printf("New game            (2)\n");
    printf("Exit                (3)\n\n");
}

void display_player(Player *player) {
    printf("%s", player->draw);
}

void display_player_ath(Player *player) {

    display_player_health(player);
    display_player_mana(player);
}

void display_player_health(Player *player) {

    int i = 0;

    printf("Health:   ");
    while(i < player->lifepoints) {
        printf("#");
        i++;
    }
    while(i < 100) {
        printf("-");
        i++;
    }

    printf( "  %d/100", player->lifepoints);
    printf("\n");

}


void display_player_mana(Player *player) {

    int i = 0;

    printf("Mana:     ");

        while(i < player->mana) {
            printf("#");
            i++;
        }
        while(i < 100) {
                printf("-");
                i++;
        }


    printf( "  %d/100", player->mana);
    printf("\n");
}