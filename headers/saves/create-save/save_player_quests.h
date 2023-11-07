//
// Created by louis on 07/11/2023.
//

#ifndef DOOM_SAVE_PLAYER_QUESTS_H
#define DOOM_SAVE_PLAYER_QUESTS_H

#include "../../includes/structs.h"
#include "../../../sqlite3/sqlite3.h"

void save_player_quests(Player *player, sqlite3** conn);
void save_quest_weapon(int player_id, Quest *quest, sqlite3** conn);
void save_quest_armor(int player_id, Quest *quest, sqlite3** conn);

#endif //DOOM_SAVE_PLAYER_QUESTS_H
