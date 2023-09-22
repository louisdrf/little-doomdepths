//
// Created by louis on 22/09/2023.
//

#ifndef DOOM_PLAYER_H
#define DOOM_PLAYER_H

#include "structs.h"

Player *init_player();
void free_player(Player *player);

void init_player_draw(Player *player);
void print_player_stats(Player *player);

#endif //DOOM_PLAYER_H
