//
// Created by louis on 04/10/2023.
//

#include <string.h>
#include <stdio.h>
#include <conio.h>
#include "../../headers/inventory/display_inventory_armors.h"
#include "../../headers/inventory/display_inventory.h"
#include "../../headers/includes/colors.h"
#include "../../headers/armor/init_armor.h"
#include "../../headers/utils.h"


void display_player_armors(Player *player) {

    int i = 0;
    int inventoryWidth = 0;
    int choice;

    clear();

    if(player->inventory->armorList[i] == NULL) {
        printf(RED"\nAucune armure dans l'inventaire\n\n"RESET);
        printf("Retour (pressez n'importe quelle touche)\n");
        int pass = getch();
        return;
    }

    while(player->inventory->armorList[i] != NULL)
    {

        inventoryWidth = 30 + (int)strlen(player->inventory->armorList[i]->name);

        printf("+");
        for(int j = 0; j < inventoryWidth; j++) {                                               // affichage de la ligne du haut
            printf("-");
        }
        printf("+\n");

        printf("| id : %d |  ", i);                                                      // affiche le numero de l'armure pour choisir celle à équiper

        switch(player->inventory->armorList[i]->rarity) {
            case COMMON:
                printf(GREEN"%s  "RESET, player->inventory->armorList[i]->name);
                break;
                // affiche le nom de l'armure avec la couleur selon sa rareté
            case RARE:
                printf(BLUE"%s  "RESET, player->inventory->armorList[i]->name);
                break;

            case EPIC:
                printf(MAGENTA"%s  "RESET, player->inventory->armorList[i]->name);
                break;

            case LEGENDARY:
                printf(YELLOW"%s  "RESET, player->inventory->armorList[i]->name);
                break;
        }
        printf("|  ");


        printf("defense : ");                                                                                                           // affiche la defense de l'armure
        printf(BLUE"%d"RESET, player->inventory->armorList[i]->defense);

        printf("\n");
        i++;
    }

    printf("+");
    for(int j = 0; j < inventoryWidth; j++) {                                                                                                   // affiche la ligne du bas
        printf("-");
    }
    printf("+\n");


    printf("\n");
    printf("Equiper une armure (1)    Retour (2)    Fermer l'inventaire (3)\n");
    choice = getch();
    choice -= 48;           // décalage ascii

    switch(choice) {

        case 1:                                                 // equipe l'armure choisie
            printf("Id de l'armure a equiper : ");
            choice = getch();
            choice -= 48;
            player->current_armor = player->inventory->armorList[choice];
            player->defense = player->current_armor->defense;
            printf("\n\n");
            printf("Armure equipee : ");
            display_armor_stats(player->inventory->armorList[choice]);
            display_inventory_choice_sections(player);
            break;

        case 2:
            display_inventory_choice_sections(player);
            break;

        case 3:
            return;

        default:
            display_player_armors(player);
    }
}