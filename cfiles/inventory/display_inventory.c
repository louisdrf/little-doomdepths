//
// Created by louis on 02/10/2023.
//

#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../headers/inventory/display_inventory.h"
#include "../../headers/inventory/display_inventory_potions.h"
#include "../../headers/inventory/display_inventory_weapons.h"
#include "../../headers/inventory/display_inventory_armors.h"
#include "../../headers/includes/colors.h"


/**
 * display choice menu for inventory sections (weapons, armors, potions)
 * @param player
 */
void display_inventory_choice_sections(Player *player) {

    system("cls");

    int choice;
    printf("\n\n    Inventaire\n\n");
    printf(GREEN"Armes          (1)\n"RESET);
    printf(BLUE"Armures        (2)\n"RESET);
    printf("Potions        (3)\n");
    printf("\n");
    printf(RED"Quitter        (0)\n"RESET);
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




