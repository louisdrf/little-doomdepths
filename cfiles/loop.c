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
#include "../headers/inventory/potion.h"
#include "../headers/monsters/monster_sprite.h"
#include "../headers/inventory/display_inventory.h"

/**
 * manages the game loop
 * @param game
 * @param player
 */
void launch_loop(Game *game, Player *player) {

    int playerEntry;
    char moveEntry;
    Zone * zone=game->zoneList[player->current_level->id];
    while(game->isRunning)
    {

        if(player->turn)
        {

            if(are_all_monsters_dead(player) == 1)              // retourne 1 si tous les monstres du niveau sont morts et passe le joueur au niveau supérieur
            {
                printf("map :\n");

                for(int i = 0; i < zone->height; i++) {
                    for(int j = 0; j < zone->width; j++) {
                        if(j==player->currentY && i==player->currentX){
                            printf("@ ");
                        } else{
                            printf("%d ",zone->map[i][j]);
                        }

                    }
                    printf("\n");
                }
                moveEntry = getch();
                printf("move %c",moveEntry);
                updateMovement(zone,player,moveEntry);

            } else{
                display_all(player); // affichage

                playerEntry = getch();

                switch(playerEntry) {
                    case 'q':
                        printf("\nFin de partie.\n");
                        game->isRunning = false;                        // cas de fin de partie
                        break;

                    case 'i':
                        display_inventory_choice_sections(player);
                        break;
                }

                playerEntry -= 48;

                if(playerEntry > 9 || playerEntry < 1) continue;

                player_attack(player, playerEntry);        // le joueur attaque le monstre dont l'id est passé en argument
            }

        }
        else {
            if(monsters_attack(player) == 1) {                      // retourne 1 si le joueur se fait tuer
                printf("\n test \n");
                display_lose();
                break;
            }
        }
    }
}