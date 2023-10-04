//
// Created by louis on 04/10/2023.
//

#ifndef DOOM_DISPLAY_INVENTORY_POTIONS_H
#define DOOM_DISPLAY_INVENTORY_POTIONS_H

#include "../includes/structs.h"

void display_player_potions(Player *player);

void both_potions_in_inventory(Player *player);
void inventory_only_mana_potion(Player *player);
void inventory_only_health_potion(Player *player);

void display_both_potions();
void display_mana_potion();
void display_health_potion();

#endif //DOOM_DISPLAY_INVENTORY_POTIONS_H
