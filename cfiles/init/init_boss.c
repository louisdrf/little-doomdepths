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

    new->lifepoints_max = rand() % BOSS_MAX_PV + BOSS_MIN_PV;
    while(new->lifepoints_max % 2 != 0) new->lifepoints_max = rand() % BOSS_MAX_PV + BOSS_MIN_PV;

    new->lifepoints = new->lifepoints_max;
    new->defense = rand() % BOSS_MAX_DEFENSE + BOSS_MIN_DEFENSE;
    new->min_strength = 2;
    new->max_strength = 6;
    new->attacks_by_turn = 1;
    new->attacks_left = new->attacks_by_turn;
    new->turn = false;
    new->monster_type = rand() % NB_BOSS_TYPE +NB_MONSTER_TYPE;
    new->isAlive = true;
    new->loot_gold = rand() % MAX_BOSS_GOLD_LOOT + MIN_BOSS_GOLD_LOOT;
    new->next = head;
    new->drawIndex = 0;
    char *sprite = return_monster_sprite(new->monster_type);
    new->draw = malloc(strlen(sprite) + 1);

    strcpy(new->draw, sprite);


#if DEBUG
    printf("Monster %d initialized.\n", new->id);
#endif

    return new;

}
