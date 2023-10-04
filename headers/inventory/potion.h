//
// Created by louis on 30/09/2023.
//

#ifndef DOOM_POTION_H
#define DOOM_POTION_H
#include "../includes/structs.h"

void getPotion(Player *player);
int display_potion_choice(unsigned short potionType);

void give_player_potion(Player *player, unsigned short type);
void use_potion(Player *player, unsigned short potionType);

Potion *createPotion(const char* name, const char* sprite, unsigned short healthValue, unsigned short manaValue);

#endif //DOOM_POTION_H
