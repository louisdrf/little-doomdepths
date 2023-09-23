//
// Created by louis on 22/09/2023.
//

#ifndef DOOM_DISPLAY_H
#define DOOM_DISPLAY_H

#include "player.h"

void display_init_menu();
void display_player(Player *player);
void display_player_ath(Player *player);
void display_player_health(Player *player);
void display_player_mana(Player *player);

#endif //DOOM_DISPLAY_H
