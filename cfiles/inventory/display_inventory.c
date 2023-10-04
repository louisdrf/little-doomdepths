//
// Created by louis on 02/10/2023.
//

#include <conio.h>
#include <stdio.h>
#include <string.h>
#include "../../headers/inventory/display_inventory.h"
#include "../../headers/inventory/display_inventory_potions.h"
#include "../../headers/inventory/display_inventory_weapons.h"
#include "../../headers/inventory/display_inventory_armors.h"


/**
 * display choice menu for inventory sections (weapons, armors, potions)
 * @param player
 */
void display_inventory_choice_sections(Player *player) {
    int choice;
    printf("\n\n    Inventaire\n\n");
    printf("Armes          (1)\n");
    printf("Armures        (2)\n");
    printf("Potions        (3)\n");
    printf("\n");
    printf("Quitter        (0)\n");
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
        case 0:
            return;

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
            display_inventory_choice_sections(player);
    }
}




