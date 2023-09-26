//
// Created by louis on 24/09/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "../headers/includes/structs.h"
#include "../headers/includes/defines.h"
#include "../headers/loop.h"
#include "../headers/game.h"
#include "../headers/display.h"
#include "../headers/player/player_attack.h"
#include "../headers/monsters/monster.h"
#include "../headers/init/init_level.h"

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
                        if(display_next_level_menu() == 1) next_level(game, player);
                        else return;
                    }
            }
            else {
                if(monsters_attack(player) == 1) {                      // retourne 1 si le joueur se fait tuer
                    display_lose();
                    break;
                }
            }
    }
}