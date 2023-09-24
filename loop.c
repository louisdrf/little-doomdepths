//
// Created by louis on 24/09/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "structs.h"
#include "defines.h"
#include "loop.h"
#include "display.h"
#include "player_attack.h"

void launch_loop(Game *game, Player *player) {

    int playerEntry; // id du monstre ciblé par le joueur

    while(game->isRunning)
    {
        display_all(player); // affichage
        playerEntry = getch();

        if(playerEntry == 'q') {
            printf("\nFin de partie.\n");
            game->isRunning = false; // cas de fin de partie
        }

        playerEntry -= 48;

            if(player->turn && player->attacks_left > 0) {
                player_attack(player, playerEntry); // attaque le monstre dont l'id est passé en paramètre
            }



    }

    exit(0);
}