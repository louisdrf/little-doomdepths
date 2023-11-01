//
// Created by louis on 01/11/2023.
//

#ifndef DOOM_LOAD_PLAYER_INVENTORY_H
#define DOOM_LOAD_PLAYER_INVENTORY_H

#include "../../includes/structs.h"
#include "../../../sqlite3/sqlite3.h"

void load_player_inventory(Player *player, sqlite3 **conn);
void load_player_inventory_weapons(Player *player, sqlite3 **conn);
void load_player_inventory_armors(Player *player, sqlite3 **conn);

#endif //DOOM_LOAD_PLAYER_INVENTORY_H
