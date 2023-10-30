//
// Created by louis on 22/09/2023.
//

#ifndef DOOM_PLAYER_H
#define DOOM_PLAYER_H

#include "../includes/structs.h"

Player *init_player(Game *game);
void free_player(Player *player);
void get_player_name(Player *player);
void init_player_draw(Player *player);
void print_player_stats(Player *player);
void add_player_name_to_game(Game *game, Player *player);
void updateMovement(Zone* zone,Player *player, char command);
#endif //DOOM_PLAYER_H
