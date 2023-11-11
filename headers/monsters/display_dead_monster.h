//
// Created by mokrane on 09/11/2023.
//
#include "../../headers/includes/structs.h"

void displayDeadMonstersItems(Player* player);
void displayDeadMonsterItem(Player* player,Monster * deadMonster, int monsterIndex );
void dead_monster_weapon_stats_print(Weapon *weapon, bool more);
void dead_monster_armor_stats_print(Armor *armor, bool more);
void dead_monster_health_potion_stats_print(Potion *healthpotion, bool more);
void dead_monster_mana_potion_stats_print(Potion *manapotion, bool more);
int player_choice();
const char *get_rarity_color(unsigned short rarity);
void monster_weapon_player_choice(Player *player, Monster *currentMonster, int choice);
void monster_armor_player_choice(Player *player, Monster *currentMonster, int choice);
void monster_ManaPotion_player_choice(Player *player, Monster *currentMonster, int choice);
void monster_HealthPotion_player_choice(Player *player, Monster *currentMonster, int choice);
#ifndef DOOM_DISPLAY_DEAD_MONSTER_H
#define DOOM_DISPLAY_DEAD_MONSTER_H

#endif //DOOM_DISPLAY_DEAD_MONSTER_H
