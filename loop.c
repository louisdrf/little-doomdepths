//
// Created by louis on 24/09/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "structs.h"
#include "defines.h"
#include "loop.h"
#include "game.h"
#include "display.h"
#include "player_attack.h"
#include "monster.h"
#include "init_level.h"

/**
 * manages the game loop
 * @param game
 * @param player
 */
void launch_loop(Game *game, Player *player) {

    int playerEntry;

    while(game->isRunning)
    {
        display_all(player); // affichage

            if(player->turn)
            {
                    playerEntry = getch();
                    if(playerEntry == 'q') {
                        printf("\nFin de partie.\n");
                        game->isRunning = false;                        // cas de fin de partie
                        break;
                    }
                    playerEntry -= 48;                                  // décalage ASCII de la saisie pour obtenir la valeur numérique
                    if(playerEntry > 9 || playerEntry < 1) continue;

                    player_attack(player, playerEntry);        // le joueur attaque le monstre dont l'id est passé en argument

                    if(are_all_monsters_dead(player) == 1)              // retourne 1 si tous les monstres du niveau sont morts et passe le joueur au niveau supérieur
                    {
                        next_level(game, player);
                    }
            }
            else {
                if(monsters_attack(player) == 1) break;                     // retourne 1 si le joueur se fait tuer
            }
    }

    exit(0);
}