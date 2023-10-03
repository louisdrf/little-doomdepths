//
// Created by louis on 02/10/2023.
//

#include <conio.h>
#include <stdio.h>
#include <string.h>
#include "../../headers/inventory/display_inventory.h"
#include "../../headers/includes/colors.h"


/**
 * display choice menu for inventory sections (weapons, armors, potions)
 * @param player
 */
void display_inventory_choice_sections(Player *player) {
    int choice;
    printf("Inventaire\n");
    printf("Armes (1)      Armures (2)       Potions (3)\n");
    choice = getch();
    choice -= 48;

    display_inventory_section(player, choice);
}


/**
 * display the selected section
 * @param player
 * @param choice
 */
void display_inventory_section(Player *player, int choice) {

    switch(choice) {

        case 1:
            display_player_weapons(player);
            break;

        case 2:
            display_player_armors(player);
            break;

        case 3:
            display_player_potions(player);
            break;

        default:
            break;
    }
}


void display_player_weapons(Player *player) {

    int i = 0;
    int inventoryWidth = 0;
    int choice;

    while(player->inventory->weaponList[i] != NULL) {

        inventoryWidth = 40 + (int)strlen(player->inventory->weaponList[i]->name);

        printf("+");
        for(int j = 0; j < inventoryWidth; j++) {
            printf("-");
        }
        printf("+\n");

        printf("| id : %d |  ", i);

        switch(player->inventory->weaponList[i]->rarity) {
            case COMMON:
                printf(GREEN"%s  "RESET, player->inventory->weaponList[i]->name);
                break;

            case RARE:
                printf(BLUE"%s  "RESET, player->inventory->weaponList[i]->name);
                break;

            case EPIC:
                printf(MAGENTA"%s  "RESET, player->inventory->weaponList[i]->name);
                break;

            case LEGENDARY:
                printf(YELLOW"%s  "RESET, player->inventory->weaponList[i]->name);
                break;
        }
        printf("|  ");


        printf("att : ");
        printf(RED"%d-%d "RESET, player->inventory->weaponList[i]->min_strength, player->inventory->weaponList[i]->max_strength);
        printf("|  ");

        printf("mana : ");
        printf(BLUE "%d "RESET, player->inventory->weaponList[i]->mana_cost);

        printf("\n");
        i++;
    }

    printf("+");
    for(int j = 0; j < inventoryWidth; j++) {
        printf("-");
    }
    printf("+\n");

    printf("\n");
    printf("Equiper une arme (1)     Fermer l'inventaire (2)\n");
    choice = getch();
    choice -= 48;           // décalage ascii

    switch(choice) {

        case 1:
            printf("Id de l'arme a equiper : ");
            choice = getch();
            choice -= 48;
            player->current_weapon = player->inventory->weaponList[choice];
            printf("\n\n");
            printf("arme equipee : %s | %d-%d | %d \n\n", player->current_weapon->name, player->current_weapon->min_strength, player->current_weapon->max_strength, player->current_weapon->mana_cost);
            break;

        case 2:
            return;
            break;

        default:
            break;
    }
}


void display_player_armors(Player *player) {

}

void display_player_potions(Player *player) {
    printf("potions");
}