//
// Created by louis on 28/10/2023.
//

#ifndef DOOM_LOAD_ZONES_H
#define DOOM_LOAD_ZONES_H

#include "../../includes/structs.h"
#include "../../../sqlite3/sqlite3.h"

void load_zones(Game *game, sqlite3 **conn);

#endif //DOOM_LOAD_ZONES_H
