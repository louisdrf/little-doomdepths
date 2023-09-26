//
// Created by louis on 24/09/2023.
//

#ifndef DOOM_MONSTER_H
#define DOOM_MONSTER_H
#include "../includes/structs.h"

int are_all_monsters_dead(Player *player);
Monster *getTargetMonster(Player *player, int id);
int monsters_attack(Player *player);

#endif //DOOM_MONSTER_H
