//
// Created by louis on 29/10/2023.
//

#ifndef DOOM_LOAD_LEVEL_MONSTERS_H
#define DOOM_LOAD_LEVEL_MONSTERS_H

#include "../../includes/structs.h"
#include "../../../sqlite3/sqlite3.h"

void load_level_monsters(Level *level, int save_id, int height_index, int width_index, int zone_id, sqlite3 **conn);

#endif //DOOM_LOAD_LEVEL_MONSTERS_H
