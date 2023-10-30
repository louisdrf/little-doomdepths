//
// Created by louis on 22/09/2023.
/** all the functions concerning the main character
**/
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "../../headers/player/player.h"
#include "../../headers/includes/structs.h"
#include "../../headers/init/init_inventory.h"
#include "../../headers/init/init_spell.h"
#include "../../headers/inventory/inventory.h"
#include "../../headers/weapon/init_weapon.h"
#include "../../headers/inventory/potion.h"
#include "../../headers/monsters/monster_sprite.h"
#include "../../headers/armor/init_armor.h"
#include "../../headers/player/player_spell.h"


#define DEBUG false

/**
 * init the player
 * return a *Player
 */
Player *init_player(Game *game) {

        Player *player;
        Inventory *inventory = NULL;
        inventory = init_inventory();
        Book *book= NULL;
        book = init_book();
        Spell *first_spell = NULL;


    for(int j = 0; j < 2 ; j++) {
        first_spell = create_spell(first_spell, j);
        book->spell_stock = first_spell;
    }

        player = malloc(sizeof(Player));
        if(player == NULL) {
    #if DEBUG
            printf("Allocating memory for player failed.\n");
    #endif
            exit(1);
        }

        player->id = game->id;
        player->isAlive = true;
        player->turn = true; // the player attack first
        player->lifepoints_max = 100;
        player->lifepoints = player->lifepoints_max;
        player->shield=0;
        player->mana_max = 100;
        player->mana = player->mana_max;
        player->gold = 0;
        player->defense = 10;
        player->attacks_by_turn = 2;
        player->attacks_left = player->attacks_by_turn;
        player->min_strength = 10;
        player->max_strength = 16;
        player->book = book;
        player->currentX=0;
        player->currentY=0;
        init_player_draw(player);
        get_player_name(player);
        player->current_zone = game->zoneList[0];
        player->current_level = game->zoneList[0]->levelList[0][0];      // joueur initialisé au premier niveau de la premiere zone
        player->inventory = inventory;

        add_player_name_to_game(game, player);

    Weapon *weapon1 = init_weapon("epee1", 2, 8, 18, 4, RARE);
    Weapon *weapon2 = init_weapon("epee2", 2, 12, 24, 6, EPIC);
    Weapon *weapon3 = init_weapon("epee3", 3, 16, 24, 4, LEGENDARY);

    add_item(player, weapon1, NULL);
    add_item(player, weapon2, NULL);
    add_item(player, weapon3, NULL);

    Armor *armor1 = init_armor("armure1", 10, RARE);
    Armor *armor2 = init_armor("armure2", 15, EPIC);
    Armor *armor3 = init_armor("armure3", 20, LEGENDARY);

    add_item(player, NULL, armor1);
    add_item(player, NULL, armor2);
    add_item(player, NULL, armor3);

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

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------


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

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------


void print_player_stats(Player *player) {

    printf("\nPlayer initialized.\n");
    printf("Player stats :\n"
           "pv : %d\n"
           "mana : %d\n"
           "defense : %d\n", player->lifepoints, player->mana, player->defense);
}


//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

void get_player_name(Player *player) {

    char name[40];

    printf("\nVotre nom de joueur : ");
    fgets(name, sizeof(name), stdin);

    if(strchr(name, '\n') != NULL && strlen(name) == 1) {
        printf("\nVeuillez saisir un nom valide.\n");
        get_player_name(player);
    }
    else if(strlen(name) >= 38) {
        printf("\nVotre nom doit contenir 40 lettres au maximum.\n");
        get_player_name(player);
    }

    name[strlen(name) - 1] = '\0';

    player->name = malloc(strlen(name) + 1);
    strcpy(player->name, name);

    //printf("Nom du joueur : %s\n", player->name);
}


//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

void add_player_name_to_game(Game *game, Player *player) {

    game->player_name = malloc(strlen(player->name) + 1);
    strcpy(game->player_name, player->name);

    //printf("Nom de la sauvegarde : %s\n", game->player_name);
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------


/**
 * free inventory, draw and player itself
 * @param player
 */
void updateMovement(Zone* zone,Player *player, char command){
    switch (command) {
        case 'z':
            if(player->currentX - 1 < 0){
                printf("1");
                command=getch();
                updateMovement(zone,player,command);
            }else if(zone->levelList[player->currentX - 1][player->currentY]!=NULL){
                player->currentX--;
            }
            break;
        case 'q':
            if(player->currentY - 1 < 0){
                printf("2");
                command=getch();
                updateMovement(zone,player,command);
            }else if(zone->levelList[player->currentX][player->currentY - 1]!=NULL ){
                player->currentY--;
            }
            break;
        case 's':
            if(player->currentX + 1 >= zone->height){
                printf("3");
                command=getch();
                updateMovement(zone,player,command);
            }else if(zone->levelList[player->currentX + 1][player->currentY]!=NULL ) {
                player->currentX++;
            }
            break;
        case'd':
            if(player->currentY + 1 >= zone->width){
                printf("4");
                command=getch();
                updateMovement(zone,player,command);
            }else if(zone->levelList[player->currentX][player->currentY + 1]!=NULL ){
                player->currentY++;
            }
            break;
        default:
            break;
    }


    if(zone->levelList[player->currentX][player->currentY]!=NULL  ){
        player->current_level=zone->levelList[player->currentX][player->currentY];
    } else{
        command=getch();
        updateMovement(zone,player,command);
    }


}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------


void free_player(Player *player) {

    for(int i = 0; i < NBOBJECTS_MAX; i++) {
        free(player->inventory->armorList[i]);
        free(player->inventory->weaponList[i]);
    }
    free(player->draw);
    free(player->name);
    if(player->current_weapon != NULL) free(player->current_weapon);
    if(player->current_armor != NULL) free(player->current_armor);
    free(player);

#if DEBUG
    if(player == NULL)   printf("\nplayer correctly free\n");
#endif
}

