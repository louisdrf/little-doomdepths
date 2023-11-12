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
#include "../headers/player/player_spell.h"
#include "../headers/zones/display_zone.h"
#include "../headers/spell/display_spell.h"
#include "../headers/saves/create-save/create_save.h"
#include "../sqlite3/sqlite3.h"
#include "../headers/includes/colors.h"
#include "../headers/saves/destroy_save.h"
#include "../headers/player/display_player_equipment.h"
#include "../headers/player/display_player_stats.h"
#include "../headers/quests/display_quests.h"
#include "../headers/quests/check_quests.h"
#include "../headers/utils.h"

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
        check_quests(player);

        if(player->turn && player->attacks_left != 0)
        {
            if((player->mana + 2) <= player->mana_max) player->mana += 2;

            if(are_all_monsters_dead(player) == 1)              // retourne 1 si tous les monstres du niveau sont morts et passe le joueur au niveau supérieur
            {
                if(!player->current_level->finished) {
                    clear();
                    display_next_level_menu();
                    player->current_level->finished = true;
                    player->nbLevelFinished++;
                    player->attacks_left = player->attacks_by_turn;
                }

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
                clear();
                display_all(player); // affichage

                playerEntry = getch();

                switch(playerEntry) {
                    case 'q':
                        printf("\nSave before quit ?\n");
                        printf(GREEN"Save and quit (x)     "RESET);
                        printf(RED"Quit (q)     "RESET);
                        printf("Return (enter any key)\n");
                        printf("-> ");
                        playerEntry = getch();
                        switch(playerEntry) {
                            case 'x':
                                create_save(game, player);
                                game->isRunning = false;
                                return;

                            case 'q':
                                printf("\nEnd of game.\n");
                                game->isRunning = false;
                                return;

                            default:
                                launch_loop(game, player);
                        }
                        continue;


                    case 'i':
                        display_inventory_choice_sections(player);
                        continue;

                    case 'e':
                        display_player_equipment(player);
                        continue;

                    case 'c':
                        display_player_stats(player);
                        continue;

                    case 'm':
                        display_player_all_zone(player, game);
                        continue;

                    case 'j':
                        display_quests_menu(player);
                        continue;

                    case 'l':
                       //display_level_loot_choice_sections(player->current_level,player);
                        continue;

                    case 's':
                        display_spell_choice_sections(player);
                        continue;

                    case 'x':
                        create_save(game, player);
                        continue;
                }

                playerEntry -= 48;
                if(!player_attack(player, playerEntry)) continue;        // le joueur attaque le monstre dont l'id est passé en argument
                if(are_all_monsters_dead(player) == 1){
                    player->shield = 0;
                }
            }

        }
        else {
            if(monsters_attack(player) == 1) {                      // retourne 1 si le joueur se fait tuer
                display_lose();
                destroy_save(game->id);
                game->isRunning = false;
                return;
            }
        }
    }
}