//
// Created by Benzekki Talal on 09/10/2023.
//

#ifndef DOOM_DISPLAY_SPELL_H
#define DOOM_DISPLAY_SPELL_H
#include "../includes/structs.h"
char* name_spell(int spell_type);
void print_spell_equipped(Player *player);
void display_spell_section(Player *player, int choice);
void print_spell_stocked(Player *player);
void display_spell_choice_sections(Player *player);

#endif //DOOM_DISPLAY_SPELL_H
