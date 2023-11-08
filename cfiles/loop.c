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
#include "../headers/zones/display_zone.h"
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
        printf("test");
        if(player->turn)
        {

            if(are_all_monsters_dead(player) == 1)              // retourne 1 si tous les monstres du niveau sont morts et passe le joueur au niveau supérieur
            {
                if(player->current_zone->map[player->currentX][player->currentY]==2){
                    player->current_zone->map[player->currentX][player->currentY]=3;
                    player->current_zone=game->zoneList[player->current_zone->id+1];
                    player->current_level=player->current_zone->levelList[player->currentX][player->currentY];
                }
                else{
                    printf("map :\n");
                    display_player_zone(player,game);
                    /*display_map_zone(zone, player);*/
                    moveEntry = getch();
                    printf("move %c",moveEntry);
                    updateMovement(player,moveEntry,game);
                }
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