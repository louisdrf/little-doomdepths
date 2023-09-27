//
// Created by louis on 24/09/2023.
//

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../headers/player/player_attack.h"
#include "../../headers/monsters/monster.h"
#include "../../headers/includes/structs.h"


void player_attack(Player *player, int idMonster) {

    srand(time(NULL));

    int current_attack_strength = rand() % (player->max_strength) + (player->min_strength); // dégats aléatoires

    Monster *target = getTargetMonster(player, idMonster);
    if(target == NULL) {
        printf("Monster targeting failed.\n");
        exit(1);
    }
    // calculate_damages();

    if((target->lifepoints) - current_attack_strength <= 0) {
        target->lifepoints = 0;
        target->isAlive = false;
        player->gold += target->loot_gold;
    }
    else target->lifepoints -= current_attack_strength;

    player->attacks_left--;
    if(player->attacks_left == 0) player->turn = false;
}