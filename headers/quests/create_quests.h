//
// Created by louis on 04/11/2023.
//

#ifndef DOOM_CREATE_QUESTS_H
#define DOOM_CREATE_QUESTS_H

#include "../includes/structs.h"

Quest *create_quests();
Quest *init_quest(Quest *head, int id, char *description, bool armorReward, bool weaponReward, int goldReward);
void free_quest_list(Quest *questList);

#endif //DOOM_CREATE_QUESTS_H
