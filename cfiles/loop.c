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
#include "../headers/db_connexion.h"

/**
 * manages the game loop
 * @param game
 * @param player
 */

void launch_loop(Game *game, Player *player) {

    int playerEntry;
    char moveEntry;

    while(game->isRunning)
    {

        if(player->turn)
        {
            if(are_all_monsters_dead(player) == 1)              // retourne 1 si tous les monstres du niveau sont morts et passe le joueur au niveau supérieur
            {
                display_player_zone(player, game);
                moveEntry = getch();
                updateMovement(player,moveEntry, game);

            } else {
                system("cls");
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

                    case 'm':
                        display_player_all_zone(player, game);
                        break;

                    case 's':
                        display_spell_choice_sections(player);
                        break;

                    case 'x':
                        create_save(game, player);
                        break;

                }

                playerEntry -= 48;
                if(!player_attack(player, playerEntry)) continue;        // le joueur attaque le monstre dont l'id est passé en argument
            }

        }
        else {
            if(monsters_attack(player) == 1) {                      // retourne 1 si le joueur se fait tuer
                display_lose();
                sqlite3 *conn = connect_to_db();
                char query[50];
                sprintf(query, "UPDATE Game SET hasSave=0 WHERE id=%d;", game->id);
                prepare_and_exec_query(&conn, query);
                sqlite3_close(conn);
                break;
            }
        }
    }
}