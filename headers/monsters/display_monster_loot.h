//
// Created by mokrane on 24/10/2023.
//

#ifndef DOOM_DISPLAY_MONSTER_LOOT_H
#define DOOM_DISPLAY_MONSTER_LOOT_H
#include "../includes/structs.h"


void get_Monster_loot(Player *player);
int display_monster_loot_choice(unsigned short dropType, Player *player);
void use_item(Player *player, unsigned short  dropType);
void stock_item(Player *player,unsigned short dropType);

#endif //DOOM_DISPLAY_MONSTER_LOOT_H
