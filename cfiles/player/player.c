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
#include "../../headers/quests/create_quests.h"
#include "../../headers/player/player_spell.h"
#include "../../headers/inventory/potion.h"
#include "../../headers/includes/colors.h"
#include "../../headers/utils.h"

#define DEBUG false

/**
 * init the player
 * return a *Player
 */
Player *init_player(Game *game) {

        Player *player;
        Inventory *inventory = NULL;
        inventory = init_inventory();

        Book *book = init_book();


        player = malloc(sizeof(Player));
        if(player == NULL) {
    #if DEBUG
            printf("Allocating memory for player failed.\n");
    #endif
            exit(1);
        }

        player->id = game->id;
        player->currentXP = 0;
        player->totalXP = 0;
        player->levelXP = 0;                                            // niveau du joueur
        init_player_xp_levels(player);                                  // initialiser les niveaux
        player->nextLevelXP = player->levelsXP[player->levelXP + 1];

        init_player_draw(player);
        get_player_name(player);
        player->nbKill = 0;
        player->nbQuestDone = 0;
        player->nbLevelFinished = 0;
        player->isAlive = true;
        player->gold = 0;
        player->turn = true;
        player->lifepoints_max = 100;
        player->lifepoints = player->lifepoints_max;
        player->shield=0;
        player->mana_max = 100;
        player->mana = player->mana_max;
        player->defense = 5;
        player->current_weapon = NULL;
        player->current_armor = NULL;
        player->attacks_by_turn = 2;
        player->attacks_left = player->attacks_by_turn;
        player->min_strength = 6;
        player->max_strength = 12;
        player->nbSpells = 0;
        player->book = book;
        player->inventory = inventory;
        player->questList = create_quests();
        player->currentX=0;
        player->currentY=0;
        player->current_zone = game->zoneList[0];
        player->current_level = game->zoneList[0]->levelList[player->currentX][player->currentY];      // joueur initialisé au premier niveau de la premiere zone


    #if DEBUG
        print_player_stats(player);
    #endif

    if(player == NULL) {
        #if DEBUG
                printf("Error while creating player.\n");
        #endif
        exit(1);
    }


    return player;
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

void init_player_xp_levels(Player *player) {

    player->levelsXP[0] = 100;

    for(int i = 1; i < NB_PLAYER_LEVELS; i++) {
        player->levelsXP[i] = (int) (player->levelsXP[i-1] + (i * 50));
    }

#if DEBUG
    for(int i = 0; i < NB_PLAYER_LEVELS; i++) {
        printf("%d\n", player->levelsXP[i]);
    }
#endif
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

void next_xp_level(Player *player) {

    clear();

    printf(GREEN"Bien joue ! Vous passez au niveau %d !\n\n"RESET, player->levelXP + 1);
    printf("Pressez n'importe quelle touche...");
    getch();

    clear();
    printf("PV MAX : %d + 5 ", player->lifepoints_max);
    printf(RED"-> %d\n"RESET, (player->lifepoints_max + 5));
    printf("MANA MAX : %d + 5 ", player->mana_max);
    printf(BLUE"-> %d\n"RESET, (player->mana_max + 5));
    getch();
    clear();

    player->levelXP++;
    player->nextLevelXP = player->levelsXP[player->levelXP];
    player->currentXP = 0;
    player->lifepoints_max += 5;
    player->lifepoints += 5;
    player->mana_max += 5;
    player->mana += 5;

    if(player->levelXP % 5 == 0 && player->levelXP != 0) {

        player_new_spell(player);
        printf(GREEN"Vous debloquez un nouveau sort !   |  "RESET);
        printf(MAGENTA"%s"RESET, player->book->spell_stock->name);
        printf("  |\n\n");
        printf("Le sort a ete rajoute a votre liste de sorts.\n\n");
        printf("Pressez n'importe quelle touche...\n");
        getch();
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

/**
 * free inventory, draw and player itself
 * @param player
 */
void updateMovement(Player *player, char command, Game* game) {

    Zone* zone = player->current_zone;

    switch (command) {
        case 'z':
            if(player->currentX - 1 < 0){
                command=getch();
                updateMovement(player,command,game);
            }else if(zone->map[player->currentX - 1][player->currentY - 1]!=0){
                player->currentX--;
            }
            break;
        case 'q':
            if(player->currentY - 1 < 0){
                command=getch();
                updateMovement(player,command,game);
            }else if(zone->map[player->currentX][player->currentY - 1]!=0 ){
                player->currentY--;
            }
            break;
        case 's':
            if(player->currentX + 1 >= zone->height){
                command=getch();
                updateMovement(player,command,game);
            }else if(zone->map[player->currentX + 1][player->currentY]!=0 ) {
                player->currentX++;
            }
            break;
        case'd':
            if(player->currentY + 1 >= zone->width){
                command=getch();
                updateMovement(player,command,game);
            }else if(zone->map[player->currentX][player->currentY + 1]!=0 ){
                player->currentY++;
            }
            break;
        default:
            break;
    }


    if(zone->map[player->currentX][player->currentY]==1 || zone->map[player->currentX][player->currentY]==2 ){
        player->current_level=zone->levelList[player->currentX][player->currentY];

    }
    else if(zone->map[player->currentX][player->currentY]==3 ){
        player->current_zone=game->zoneList[player->current_zone->id+1];
        player->current_level=player->current_zone->levelList[player->currentX][player->currentY];
    }
    else{
        command=getch();
        updateMovement(player,command,game);
    }


}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------



