//
// Created by louis on 22/09/2023.
//

#ifndef DOOM_DISPLAY_H
#define DOOM_DISPLAY_H

#include "player/player.h"

void display_init_menu();
int display_save_choice();
void display_all(Player *player);

void display_play_or_destroy_save(int save_id);
void display_player_ath(Player *player);
void display_player_health(Player *player);
void display_player_mana(Player *player);
void display_monsters_alive(Monster *head);


void display_lose();
int display_next_level_menu();

#endif //DOOM_DISPLAY_H
