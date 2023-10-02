//
// Created by louis on 02/10/2023.
//

#include <conio.h>
#include <stdio.h>
#include "../../headers/inventory/display_inventory.h"



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
    printf("armes");
}


void display_player_armors(Player *player) {
    printf("armures");
}

void display_player_potions(Player *player) {
    printf("potions");
}