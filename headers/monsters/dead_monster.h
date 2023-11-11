//
// Created by mokra on 08/11/2023.
//

#ifndef DOOM_DEAD_MONSTER_H
#define DOOM_DEAD_MONSTER_H
#include "../../headers/includes/structs.h"

void addMonsterToDeadList(Level* level, Monster* monster);
bool isMonsterInDeadList(Level* level, Monster* monsterToCheck);
#endif //DOOM_DEAD_MONSTER_H
