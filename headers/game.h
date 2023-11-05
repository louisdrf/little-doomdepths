//
// Created by louis on 22/09/2023.
//

#ifndef DOOM_GAME_H
#define DOOM_GAME_H
#include "includes/structs.h"

Game *init_game(int save_id);
void launch_new_game(int save_id);
void load_saved_game(int save_id);
void free_game(Game *game);

#endif //DOOM_GAME_H
