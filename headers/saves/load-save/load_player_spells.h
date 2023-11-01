//
// Created by louis on 01/11/2023.
//

#ifndef DOOM_LOAD_PLAYER_SPELLS_H
#define DOOM_LOAD_PLAYER_SPELLS_H

#include "../../../headers/includes/structs.h"
#include "../../../sqlite3/sqlite3.h"

void load_player_spells(Player *player, sqlite3 **conn);

#endif //DOOM_LOAD_PLAYER_SPELLS_H
