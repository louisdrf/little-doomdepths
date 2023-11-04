//
// Created by Benzekki Talal on 09/10/2023.
//
#include "../../headers/includes/structs.h"
#include "../../headers/player/player_spell.h"
#include "../../headers/spell/display_spell.h"
#include "../../headers/monsters/monster.h"
#include "../../headers/includes/colors.h"
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

char* name_spell(int spell_type){
    static char *spell[][4] = {
            {"Regen","Heal"},
            {"Magic missile","Thunderbolt"},
            {"Protection","Blue Shield"},
            {"Earthquake","Fireball"}
    };
    return spell[spell_type][rand()%2];
}

/*
 * enum spell_type {
    HEAL,
    DAMAGE,
    SHIELD,
    AOE,
    BUFF_SPEED,
};
 */

void print_spell_equipped(Player *player){
    printf("\n");
    if(player->book->spell_equipped[0] ==NULL){
        printf("Aucun sort equipe\n");
    }
    for (int i = 0; player->book->spell_equipped[i] != NULL ; ++i) {

        printf(CYAN"ID : %d |  name : %s |  power : %d |  cost : %d | "RESET, i,
               player->book->spell_equipped[i]->name,
               player->book->spell_equipped[i]->value,
               player->book->spell_equipped[i]->mana_cost);

        print_spell_type(player->book->spell_equipped[i]->spell_type);

    }

}

void print_spell_stocked(Player *player) {
    printf("\n");
    Spell *current = player->book->spell_stock;

    while (current!=NULL){

        printf(CYAN"ID : %d |  name : %s |  power : %d |  cost : %d | "RESET,
               current->id,current->name,
               current->value,
               current->mana_cost);

        print_spell_type(current->spell_type);

        current= current->next;
    }

}

void print_spell_type(int type) {

    switch(type) {
        case HEAL:
            printf(MAGENTA"HEAL\n"RESET);
            break;

        case DAMAGE:
            printf(RED"DAMAGE\n"RESET);
            break;

        case SHIELD:
            printf(BLUE"SHIELD\n"RESET);
            break;

        case AOE:
            printf(RED"DAMAGE IN ZONE\n"RESET);
            break;

        case BUFF_SPEED:
            printf(YELLOW"SPEED BUFF\n"RESET);
            break;
    }

}
void display_spell_choice_sections(Player *player) {
    int choice;
    printf("\n\n    Spell\n\n");
    printf("Utiliser       (1)\n");
    printf("Equiper        (2)\n");
    printf("\n");
    printf("Quitter        (0)\n");
    choice = getch();
    choice -= 48;

    display_spell_section(player, choice);
}


void display_spell_use(Player *player, Spell *spell){
    int choice;
    switch(spell->spell_type) {
        case HEAL:
            spell_heal(player,spell);
            break;
        case DAMAGE:
            printf("Choisissez le monstre a frapper");
            choice = getch();
            choice -= 48;
            spell_damage(player,choice,spell);
            break;
        case SHIELD:
            spell_shield(player,spell);
            break;
        case AOE:
            spell_aoe(player,spell);
            break;
        case BUFF_SPEED:
            break;
    }
}
void display_spell_section(Player *player, int choice) {

    switch(choice) {
        case 0:
            return;

        case 1:
            print_spell_equipped(player);
            choice=getch();
            choice -= 48;

            display_spell_use(player,player->book->spell_equipped[choice]);
            player->attacks_left--;
            break;

        case 2:
            print_spell_stocked(player);
            int choice;
            choice=getch();
            choice -= 48;
            add_spell(player,get_spell_stocked(player,choice));
            print_spell_equipped(player);
            break;



        default:
            display_spell_choice_sections(player);
    }
}