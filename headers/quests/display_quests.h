//
// Created by louis on 04/11/2023.
//

#ifndef DOOM_DISPLAY_QUESTS_H
#define DOOM_DISPLAY_QUESTS_H

#include "../includes/structs.h"

void display_quests_menu(Player *player);
void display_quests(Player *player);
void display_done_quests(Player *player);
void display_quest_rewards(Player* player, int quest_id);

#endif //DOOM_DISPLAY_QUESTS_H
