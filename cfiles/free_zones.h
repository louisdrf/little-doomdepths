//
// Created by louis on 10/11/2023.
//

#ifndef DOOM_FREE_ZONES_H
#define DOOM_FREE_ZONES_H

#include "../headers/game.h"

void free_all_zones(Game *game);
void free_zone(Game* game, int index);
void free_levels(Game *game, int i, int j);

#endif //DOOM_FREE_ZONES_H
