//
// Created by louis on 28/10/2023.
//

#ifndef DOOM_LOAD_LEVELS_H
#define DOOM_LOAD_LEVELS_H

#include "../../includes/structs.h"
#include "../../../sqlite3/sqlite3.h"

void load_levels(Game *game, int zone_id, sqlite3 **conn);

#endif //DOOM_LOAD_LEVELS_H
