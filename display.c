//
// Created by louis on 22/09/2023.
//
#include <stdio.h>
#include "display.h"
#include "player.h"

void display_init_menu() {
    printf("----Doomdepths----\n");
    printf("Play from last save (1)\n");
    printf("New game            (2)\n");
    printf("Exit                (3)\n\n");
}

void display_player(Player *player) {
    printf("%s", player->draw);
}