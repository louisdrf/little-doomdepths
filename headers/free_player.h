//
// Created by louis on 10/11/2023.
//

#ifndef DOOM_FREE_PLAYER_H
#define DOOM_FREE_PLAYER_H

#include "includes/structs.h"

void free_player(Player *player);
void free_inventory(Player *player);
void free_armor(Armor *a);
void free_weapon(Weapon *w);

void free_quest_list(Quest *questList);
void free_spell_list(Spell *spellList);
void destroy_potion(Potion* potion);

#endif //DOOM_FREE_PLAYER_H
