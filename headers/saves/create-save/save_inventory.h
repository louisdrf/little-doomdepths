//
// Created by louis on 22/10/2023.
//

#ifndef DOOM_SAVE_INVENTORY_H
#define DOOM_SAVE_INVENTORY_H

#include "../../includes/structs.h"
#include "../../../sqlite3/sqlite3.h"

void save_inventory(Player *player, sqlite3** conn);

#endif //DOOM_SAVE_INVENTORY_H
