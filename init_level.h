//
// Created by louis on 24/09/2023.
//

#ifndef DOOM_INIT_LEVEL_H
#define DOOM_INIT_LEVEL_H

#include "structs.h"

Level *init_level(int id);
void next_level(Game *game, Player *player);

#endif //DOOM_INIT_LEVEL_H
