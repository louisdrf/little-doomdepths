//
// Created by louis on 02/10/2023.
//

#ifndef DOOM_DISPLAY_INVENTORY_H
#define DOOM_DISPLAY_INVENTORY_H

//
// Created by louis on 02/10/2023.
//
#include "../../headers/includes/structs.h"


void display_inventory_choice_sections(Player *player);
void display_inventory_section(Player *player, int choice);

void display_player_weapons(Player *player);
void display_player_armors(Player *player);
void display_player_potions(Player *player);

#endif //DOOM_DISPLAY_INVENTORY_H
