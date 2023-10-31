//
// Created by mokrane on 23/10/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "../../headers/includes/structs.h"
#include "../../headers/includes/colors.h"
#include "../../headers/monsters/display_monster_loot.h"
#include"../../headers/inventory/inventory.h"

void get_Monster_loot(Player *player){

    unsigned short dropType = rand() % 3 + 1;
    //rand() % 3 + 1;
    unsigned short choice;
    printf("\ndropType : %d\n",dropType);//debug
    choice = display_monster_loot_choice(dropType, player);
    if(choice == 1){
        use_item(player,dropType);
    }
    if (choice == 2) {
        stock_item(player, dropType);
    }
    if (choice == 3) {
        printf(RED"Aucun item n'a ete choisi\n"RESET);
    }
    if(choice !=1 && choice !=2 && choice!=3) {
        printf(RED"Les monstres ne laissent tomber aucun item "RESET);
    }


}

int display_monster_loot_choice(unsigned short dropType, Player *player){
    unsigned short playerEntry;
    int yn=0;
    switch (dropType) {
        case 1: // Weapon
            if(player->current_level->monsters->monster_weapon != NULL){
                if (player->current_level->monsters->monster_weapon->rarity==COMMON) {
                    //case COMMON :
                    printf("\n\n");
                    printf(GREEN" ----|)>>>>>>>>>>\n");
                    printf(RESET"\n\n");
                    yn =1;
                }
                if (player->current_level->monsters->monster_weapon->rarity==RARE) {
                    //case RARE:
                    printf("\n\n");
                    printf(BLUE" ----|)>>>>>>>>>>-\n");
                    printf(RESET"\n\n");
                    yn=1;
                }
            }
            break;

        case 2: // Armor
            if(player->current_level->monsters->monster_armor != NULL){
                if (player->current_level->monsters->monster_armor->rarity == COMMON) {
                    //case COMMON :

                    printf("\n\n");
                    printf(GREEN"     |  |\n");
                    printf(GREEN"  ___|  |___ \n");
                    printf(GREEN" |          |\n");
                    printf(GREEN" |          |\n");
                    printf(GREEN" |__________|\n");
                    printf(RESET"\n\n");
                    yn=1;
                }
            if(player->current_level->monsters->monster_armor->rarity == RARE) {
                    //case RARE:
                    printf("\n\n");
                    printf(BLUE"     |  |\n");
                    printf(BLUE"  ___|  |___ \n");
                    printf(BLUE" |          |\n");
                    printf(BLUE" |          |\n");
                    printf(BLUE" |__________|\n");
                    printf(RESET"\n\n");
                    yn=1;
                }

            }
            break;
        default:
            break;
    }
    if(yn==1){
    printf("Equiper (1)     Garder dans l'inventaire (2)     Ne rien faire (3)\n\n-->  ");
    playerEntry = getch();
    playerEntry -= 48;
    while(playerEntry !=1 && playerEntry != 2 && playerEntry != 3) {
        playerEntry = getch();
        playerEntry -= 48;
    }
        return playerEntry;
    }else{
        return 4; // // Aucune arme ni armure disponible, retourne 4.
    }
}

void use_item(Player *player, unsigned short  dropType){
    switch (dropType) {

        case 1 : //Weapon
            if(player->current_level->monsters->monster_weapon != NULL){
                player->current_weapon=player->current_level->monsters->monster_weapon;
                player->current_level->monsters->monster_weapon=NULL;
                printf(GREEN"\nArme equipee\n"RESET);


            }else{
                printf(RED"\nArme du monstre n a pas ete correctement equiper !\n"RESET);
            }
            break;

        case 2 : //Armor
            if(player->current_level->monsters->monster_armor != NULL) {
                player->current_armor = player->current_level->monsters->monster_armor;
                printf(GREEN"\nArmure equipee.\n"RESET);
                player->current_level->monsters->monster_armor = NULL;
            }else{
                printf(RED"\nArmure du monstre n a pas ete correctement equiper !\n"RESET);
            }
            break;

        default:
            break;
    }

}
void stock_item(Player *player,unsigned short dropType){
    switch (dropType) {

        case 1 : //weapon
            if(player->current_level->monsters->monster_weapon != NULL){
                add_item(player,player->current_level->monsters->monster_weapon,NULL);
            printf(GREEN"\nArme ajoutee a l'inventaire\n"RESET);
            player->current_level->monsters->monster_weapon=NULL;
            }else{
                printf(RED"Arme du monstre n a pas ete correctement stocker !"RESET);
            }
            break;

        case 2 : //armor
            if(player->current_level->monsters->monster_armor != NULL) {
                add_item(player, NULL, player->current_level->monsters->monster_armor);
                printf(GREEN"\nArmure ajoutee a l'inventaire\n"RESET);
                player->current_level->monsters->monster_armor = NULL;
            }else{
                printf(RED"Armure du monstre n a pas ete correctement stocker !"RESET);
            }
            break;

        default:
            break;
    }


}
