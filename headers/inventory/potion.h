//
// Created by louis on 30/09/2023.
//

#ifndef DOOM_POTION_H
#define DOOM_POTION_H
#include "../includes/structs.h"

void getPotion(Player *player);
int display_potion_choice();
void give_player_potion(Player *player, char* type);
Potion *createPotion(const char* name, const char* sprite, int healthValue, int manaValue);

#endif //DOOM_POTION_H
