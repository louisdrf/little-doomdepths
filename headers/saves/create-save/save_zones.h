//
// Created by louis on 26/10/2023.
//

#ifndef DOOM_SAVE_ZONES_H
#define DOOM_SAVE_ZONES_H

#include "../../../sqlite3/sqlite3.h"
#include "../../includes/structs.h"

void save_zones(Game* game, sqlite3 **conn);

#endif //DOOM_SAVE_ZONES_H
