//
// Created by Benzekki Talal on 29/10/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../../headers/init/init_monster.h"
#include "../../headers/includes/structs.h"
#include "../../headers/includes/defines.h"
#include "../../headers/monsters/monster_sprite.h"
#include "../../headers/utils.h"

#define DEBUG false


/**
 * create a Monster * and add it to the linked list of Monster
 */
Monster *create_boss(Monster *head, int index) {

    Monster *new = malloc(sizeof(Monster));
    if(new == NULL) {
#if DEBUG
        printf("Error while allocating memory for monster.\n");
                exit(1);
#endif
    }

    new->id = index;

    new->lifepoints_max = (int)(random_int(BOSS_MIN_PV, BOSS_MAX_PV));
    while(new->lifepoints_max % 2 != 0) new->lifepoints_max = (int)(random_int(BOSS_MIN_PV, BOSS_MAX_PV));

    new->lifepoints = new->lifepoints_max;
    new->defense = (int)(random_int(BOSS_MIN_DEFENSE, BOSS_MAX_DEFENSE));
    new->min_strength = 14;
    new->max_strength = 18;
    new->attacks_by_turn = 1;
    new->attacks_left = new->attacks_by_turn;
    new->turn = false;
    new->monster_type = (int)(random_int(NB_BOSS_TYPE, NB_MONSTER_TYPE));
    new->isAlive = true;
    new->loot_gold = (int)(random_int(MAX_BOSS_GOLD_LOOT, MIN_BOSS_GOLD_LOOT));
    new->next = head;
    new->drawIndex = 0;
    char *sprite = return_monster_sprite(new->monster_type);
    new->draw = malloc(strlen(sprite) + 1);
    new->xp = (int)(random_int(MIN_BOSS_XP, MAX_BOSS_XP));

    strcpy(new->draw, sprite);


#if DEBUG
    printf("Monster %d initialized.\n", new->id);
#endif

    return new;

}
