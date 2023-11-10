//
// Created by louis on 01/10/2023.
//

#ifndef DOOM_MONSTER_SPRITE_H
#define DOOM_MONSTER_SPRITE_H

#include "../includes/structs.h"

char **init_monster_sprites();
char *return_monster_sprite(int type);
void print_monsters(Player *player);
Monster* little_print_monster(Monster* current);
void monster_indexes_to_zero(Player *player);

#endif //DOOM_MONSTER_SPRITE_H
