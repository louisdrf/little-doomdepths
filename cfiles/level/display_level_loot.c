//
// Created by mokrane on 06/10/2023.
//
#include <conio.h>
#include <stdio.h>
#include "../../headers/level/display_level_loot_weapons.h"
#include "../../headers/level/display_level_loot.h"
#include "../../headers/level/display_level_loot_armors.h"



/**
 * display choice menu for inventory sections (weapons, armors, potions)
 * @param level
 * @param player
 */



/*void display_level_loot_choice_sections(Level *level,Player *player) {
    int choice;
    printf("\n\n   Level Loot\n\n");
    printf("Armes          (1)\n");
    printf("Armures        (2)\n");
    //printf("Potions        (3)\n");
    printf("\n");
    printf("Quitter        (0)\n");
    choice = getch();
    choice -= 48;

    display_level_loot_section(level,player, choice);
}*/

/**
 * display the selected section
 * @param level
 * @param player
 * @param choice
*/
/*
void display_level_loot_section(Level *level,Player *player, int choice) {

    switch(choice) {
        case 0:
            return;

        case 1:
            display_level_loot_weapons(level,player);
            break;

        case 2:
            display_level_loot_armors(level,player);
            break;

        case 3:
            //display_player_potions(player);       //pas de potion dans le level loot
            break;


        default:
            display_level_loot_choice_sections(level,player);
    }
}
*/