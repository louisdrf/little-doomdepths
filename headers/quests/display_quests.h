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
void get_quest_rewards(Quest *quest, Player *player);
void get_weapon_quest_reward(Quest *quest, Player *player);
void get_armor_quest_reward(Quest *quest, Player *player);

#endif //DOOM_DISPLAY_QUESTS_H
