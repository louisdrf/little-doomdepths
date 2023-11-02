//
// Created by louis on 24/09/2023.
//

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../headers/player/player_attack.h"
#include "../../headers/monsters/monster.h"
#include "../../headers/includes/structs.h"
#include "../../headers/includes/colors.h"

#define DEBUG false

bool player_attack(Player *player, int idMonster) {

    srand(time(NULL));

    int current_attack_strength;

    Monster *target = getTargetMonster(player, idMonster);
    if(target == NULL) {
    #if DEBUG
    printf("Monster targeting failed.\n");
    #endif
        return false;
    }

    if(player->current_weapon != NULL && (player->mana - player->current_weapon->mana_cost) >= 0) {
        current_attack_strength = rand() % (player->current_weapon->max_strength) + (player->current_weapon->min_strength);     // si le joueur a une arme équipée et suffisamment de mana pour attaquer
    }
    else {
        printf(RED"\nAttaque a mains nues ! \n"RESET);
        current_attack_strength = rand() % (player->max_strength) + (player->min_strength);                                     // sinon le joueur attaque à mains nues
    }

    if((target->lifepoints) - current_attack_strength <= 0) {
        target->lifepoints = 0;
        target->isAlive = false;
        player->gold += target->loot_gold;
    }
    else target->lifepoints -= current_attack_strength;

    player->attacks_left--;
    if(player->current_weapon != NULL) {
        if(player->mana - player->current_weapon->mana_cost >= 0) player->mana -= player->current_weapon->mana_cost;
        else player->mana = 0;
    }

    if(player->attacks_left == 0) player->turn = false;

    return true;
}