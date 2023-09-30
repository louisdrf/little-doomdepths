//
// Created by Benzekki Talal on 25/09/2023.
//

#ifndef DOOM_MONSTER_SPRITE_H
#define DOOM_MONSTER_SPRITE_H
#include "../includes/structs.h"
void show_monster_player(char **sprite_player,char **sprite_monster1,char **sprite_monster2,char **sprite_monster3);
char** monster_sprite_random(int type);
void free_sprite(char **sprite);
#endif //DOOM_MONSTER_SPRITE_H
