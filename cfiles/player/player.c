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


#define DEBUG true

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
        player->max_strength = 25;

        player->current_level = level;

        player->inventory = inventory;

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

    player->draw = malloc(sizeof(strlen(draw)) + 1);
    strcpy(player->draw, draw);

    if(strlen(player->draw) == 0) {
        printf("Error while drawing the player.\n");
        exit(1);
    }
}

char** player_sprite(){
    char **sprite=malloc(sizeof(char *)*20*14);

    sprite[0]="      _,.                   ";
    sprite[1]="    ,` -.)                  ";
    sprite[2]="   ( _/-\\\\-._               ";
    sprite[3]="  /,|`--._,-^|            , ";
    sprite[4]="  \\_| |`-._/||          ,'| ";
    sprite[5]="    |  `-, / |         /  / ";
    sprite[6]="    |     || |        /  /  ";
    sprite[7]="     `r-._||/   __   /  /   ";
    sprite[8]=" __,-<_     )`-/  `./  /    ";
    sprite[9]="'  \\   `---'   \\   /  /     ";
    sprite[10]="    |           |./  /      ";
    sprite[11]="    /           //  /       ";
    sprite[12]="\\_/' \\         |/  /        ";
    sprite[13]=" |    |   _,^-'/  /         ";
    sprite[14]=" |    , ``  (\\/  /_         ";
    sprite[15]="  \\,.->._    \\X-=/^         ";
    sprite[16]="  (  /   `-._//^`           ";
    sprite[17]="   `Y-.____(__}             ";
    sprite[18]="    |     {__)              ";
    sprite[19]="          ()                ";

    return sprite;
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

