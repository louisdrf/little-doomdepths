//
// Created by louis on 24/09/2023.
//

#ifndef DOOM_MONSTER_H
#define DOOM_MONSTER_H
#include "structs.h"

Monster *getTargetMonster(Player *player, int id);
int monsters_attack(Player *player);

#endif //DOOM_MONSTER_H
