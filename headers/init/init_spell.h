//
// Created by Benzekki Talal on 09/10/2023.
//

#ifndef DOOM_INIT_SPELL_H
#define DOOM_INIT_SPELL_H
#include "../includes/structs.h"

Spell *create_random_spell(Spell *head, int index);
Spell *create_spell(Spell *head, int index, int power, int mana_cost, int spell_type, char *name);
void player_new_spell(Player *player);

Book *init_book();

#endif //DOOM_INIT_SPELL_H
