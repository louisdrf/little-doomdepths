//
// Created by louis on 22/09/2023.
/** all the functions concerning the main character
**/
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../headers/player/player.h"
#include "../../headers/includes/structs.h"
#include "../../headers/init/init_inventory.h"
#include "../../headers/inventory/inventory.h"
#include "../../headers/weapon/init_weapon.h"
#include "../../headers/inventory/potion.h"
#include "../../headers/monsters/monster_spritev2.h"


#define DEBUG false

/**
 * init the player
 * return a *Player
 */
Player *init_player(Level *level) {

        Player *player;
        Inventory *inventory = NULL;
        inventory = init_inventory();

        player = malloc(sizeof(Player));
        if(player == NULL) {
    #if DEBUG
            printf("Allocating memory for player failed.\n");
    #endif
            exit(1);
        }

        player->isAlive = true;
        player->turn = true; // the player attack first
        player->lifepoints_max = 100;
        player->lifepoints = player->lifepoints_max;
        player->mana_max = 100;
        player->mana = player->mana_max;
        player->gold = 0;
        player->defense = 10;
        player->attacks_by_turn = 2;
        player->attacks_left = player->attacks_by_turn;
        player->min_strength = 10;
        player->max_strength = 16;

        init_player_draw(player);
        player->current_level = level;
        player->inventory = inventory;

        Weapon *weapon1 = init_weapon("epee1", 2, 8, 18, 4, RARE);
        Weapon *weapon2 = init_weapon("epee2", 2, 12, 24, 6, EPIC);
        Weapon *weapon3 = init_weapon("epee3", 3, 16, 24, 4, LEGENDARY);

    add_item(player, weapon1, NULL);
    add_item(player, weapon2, NULL);
    add_item(player, weapon3, NULL);

    #if DEBUG
        print_player_stats(player);
    #endif

    if(player == NULL) {
        #if DEBUG
                printf("Error while creating player.\n");
        #endif
        exit(1);
    }
    if(player != NULL) return player;
    else {
        puts("\nInitializing player failed.");
        return NULL;
    }

}

void init_player_draw(Player *player) {

    char *draw = "      _,.\n"
                 "    ,` -.)\n"
                 "   ( _/-\\\\-._\n"
                 "  /,|`--._,-^|            ,\n"
                 "  \\_| |`-._/||          ,'|\n"
                 "    |  `-, / |         /  /\n"
                 "    |     || |        /  /\n"
                 "     `r-._||/   __   /  /\n"
                 " __,-<_     )`-/  `./  /\n"
                 "'  \\   `---'   \\   /  /\n"
                 "    |           |./  /\n"
                 "    /           //  /\n"
                 "\\_/' \\         |/  /\n"
                 " |    |   _,^-'/  /\n"
                 " |    , ``  (\\/  /_\n"
                 "  \\,.->._    \\X-=/^\n"
                 "  (  /   `-._//^`\n"
                 "   `Y-.____(__}\n"
                 "    |     {__)\n"
                 "          ()";

    player->draw = malloc(strlen(draw) + 1);
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


/**
 * free inventory, draw and player itself
 * @param player
 */
void free_player(Player *player) {

    for(int i = 0; i < NBOBJECTS_MAX; i++) {
        free(player->inventory->armorList[i]);
        free(player->inventory->weaponList[i]);
    }
    free(player->draw);
    if(player->current_weapon != NULL) free(player->current_weapon);
    free(player);

#if DEBUG
    if(player == NULL)   printf("\nplayer correctly free\n");
#endif
}

