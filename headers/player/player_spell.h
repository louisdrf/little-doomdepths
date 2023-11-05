//
// Created by Benzekki Talal on 03/10/2023.
//

#ifndef DOOM_PLAYER_SPELL_H
#define DOOM_PLAYER_SPELL_H

#include "../includes/structs.h"


void add_spell(Player *player, Spell *spell);
int get_first_spell_free_space(Player *player);
Spell *get_spell_stocked(Player *player,int choice);
void spell_damage(Player *player,int idMonster,Spell *spell);
void spell_heal(Player *player,Spell *spell);
void spell_shield(Player *player,Spell *spell);
void spell_aoe(Player *player,Spell *spell);
void free_spell_list(Spell *spellList);

#endif //DOOM_PLAYER_SPELL_H
