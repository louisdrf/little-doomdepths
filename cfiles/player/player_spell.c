//
// Created by Benzekki Talal on 03/10/2023.
//
#include "../../headers/includes/structs.h"
#include "../../headers/player/player_spell.h"
#include "../../headers/monsters/monster.h"
#include "../../headers/includes/colors.h"
#include "../../headers/utils.h"
#include <conio.h>
#include <stdio.h>

Spell *get_spell_stocked(Player *player,int choice) {

    printf("\n");
    Spell *current = player->book->spell_stock;
    Spell *result=NULL;
    while (current!=NULL){

        if(current->id==choice){
            result= current;
        }
        current= current->next;
    }
    if(result!=NULL){
        return result;
    } else{
        printf("Ce spell n'existe pas");
        return NULL;
    }
}



void add_spell(Player *player, Spell *spell) {

    int index = 0;
    int place_in_book = NBSPELL_MAX - get_first_spell_free_space(player);       // nombre de case libres dans la roue de sort


    if(spell != NULL) {
        index = get_first_spell_free_space(player);

        if(place_in_book >0)
        {
            player->book->spell_equipped[index] = spell;          // on rajoute le sort dans la roue de sort si il y a de la place
        }
        else {
            printf("plus de place, veuillez retirer un sort !\n");
        }
    }
}


int get_first_spell_free_space(Player *player) {

    int i = 0;
    while(player->book->spell_equipped[i] != NULL) {
        i++;
    }
    return i; // on retourne la case suivante
}


void spell_damage(Player *player, int idMonster, Spell *spell) {

    if((player->mana - spell->mana_cost) < 0) {
        clear();
        printf(RED"Vous n'avez pas assez de mana pour utiliser ce sort.\n\n"RESET);
        printf("Pressez n'importe quelle touche...\n");
        getch();
        return;
    }

    Monster *target = getTargetMonster(player, idMonster);
    if((target->lifepoints) - (spell->value * 5) <= 0) {
        target->lifepoints = 0;
        target->isAlive = false;
        player->gold += target->loot_gold;
    }
    else target->lifepoints -= (spell->value * 5);

    player->mana -= spell->mana_cost;
    player->attacks_left--;
    if(player->attacks_left == 0) player->turn = false;
}


void spell_aoe(Player *player,Spell *spell) {

    if((player->mana - spell->mana_cost) < 0) {
        clear();
        printf(RED"Vous n'avez pas assez de mana pour utiliser ce sort.\n\n"RESET);
        printf("Pressez n'importe quelle touche...\n");
        getch();
        return;
    }

    Monster *current = player->current_level->monsters;
    int i = 0;
    while (current != NULL && i<NBMONSTERS_MAX) {
        if(current->isAlive) {
            if((current->lifepoints) - (spell->value * 3) <= 0) {
                current->lifepoints = 0;
                current->isAlive = false;
                player->gold += current->loot_gold;
            }
            else current->lifepoints -= (spell->value * 3);
            //printf("Vous infligez %d points de degats a %s (%d/%d)\n", spell->value*5, monster_string[current->monster_type], current->lifepoints, current->lifepoints_max);
            i++;
        }
        current = current->next;
    }
    player->mana -= spell->mana_cost;
    player->attacks_left--;
    if(player->attacks_left == 0) player->turn = false;
}


void spell_heal(Player *player, Spell *spell) {

    if(player->lifepoints == player->lifepoints_max) {
        clear();
        printf(RED"Vos points de vie sont deja au maximum.\n\n"RESET);
        printf("Pressez n'importe quelle touche...\n");
        getch();
        return;
    }
    if((player->mana - spell->mana_cost) < 0) {
        clear();
        printf(RED"Vous n'avez pas assez de mana pour utiliser ce sort.\n\n"RESET);
        printf("Pressez n'importe quelle touche...\n");
        getch();
        return;
    }

    if((player->lifepoints + (spell->value * 5)) > player->lifepoints_max) player->lifepoints = player->lifepoints_max;
    else player->lifepoints += (spell->value * 5);

    player->mana -= spell->mana_cost;
    player->attacks_left--;
    if(player->attacks_left == 0) player->turn = false;
}


void spell_shield(Player *player,Spell *spell) {
    if(player->shield > (spell->value * 3)) {
        printf("\nVous ne pouvez pas posseder un  bouclier plus puissant avec ce sort.\n");
    } else {
        player->shield=spell->value * 3;
        printf("\nVous aver cree un bouclier de %d points de protection.\n",spell->value * 3);
    }

    player->mana-=spell->mana_cost;
    player->attacks_left--;
    if(player->attacks_left == 0) player->turn = false;
}


