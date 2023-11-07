//
// Created by louis on 07/11/2023.
//

#ifndef DOOM_LOAD_PLAYER_QUESTS_H
#define DOOM_LOAD_PLAYER_QUESTS_H

#include "../../../sqlite3/sqlite3.h"
#include "../../includes/structs.h"

void load_player_quests(Player *player, sqlite3 **conn);
void load_quest_weapon(Quest *quest, int player_id, sqlite3 **conn);
void load_quest_armor(Quest *quest, int player_id, sqlite3 **conn);

#endif //DOOM_LOAD_PLAYER_QUESTS_H
