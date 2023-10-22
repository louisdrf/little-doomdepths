//
// Created by louis on 22/10/2023.
//

#ifndef DOOM_SAVE_PLAYER_SPELLS_H
#define DOOM_SAVE_PLAYER_SPELLS_H

#include "../../sqlite3/sqlite3.h"
#include "../includes/structs.h"

void save_player_spells(Player *player, sqlite3** conn);

#endif //DOOM_SAVE_PLAYER_SPELLS_H
