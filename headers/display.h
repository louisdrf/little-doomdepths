//
// Created by louis on 22/09/2023.
//

#ifndef DOOM_DISPLAY_H
#define DOOM_DISPLAY_H

#include "player/player.h"

void display_init_menu();
void display_all(Player *player);

void display_player(Player *player);
void display_player_ath(Player *player);
void display_player_health(Player *player);
void display_player_mana(Player *player);
void display_monsters_alive(Monster *head);
void display_monster_health(Monster *monster);
void display_boss_health(Monster *monster);
void display_lose();
int display_next_level_menu();

#endif //DOOM_DISPLAY_H
