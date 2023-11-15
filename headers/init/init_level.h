//
// Created by louis on 24/09/2023.
//

#ifndef DOOM_INIT_LEVEL_H
#define DOOM_INIT_LEVEL_H

#include "../includes/structs.h"

Level *init_level(int id, double multiplicator, int type);
Level *init_level_boss(int id, double multiplicator, int type);
Level *init_level_chest(int id, double multiplicator, int type);


#endif //DOOM_INIT_LEVEL_H
