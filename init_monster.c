//
// Created by louis on 23/09/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "init_monster.h"
#include "structs.h"
#include "defines.h"

#define DEBUG false


/**
 * create a Monster * and add it to the linked list of Monster
 */
Monster *create_monster(Monster *head, int index) {

    Monster *new = malloc(sizeof(Monster));
    if(new == NULL) {
        #if DEBUG
                printf("Error while allocating memory for monster.\n");
                exit(1);
        #endif
    }

    new->id = index;

    new->lifepoints_max = rand() % MONSTER_MAX_PV + MONSTER_MIN_PV;
    while(new->lifepoints_max % 2 != 0) new->lifepoints_max = rand() % MONSTER_MAX_PV + MONSTER_MIN_PV;

    new->lifepoints = new->lifepoints_max;
    new->defense = rand() % MONSTER_MAX_DEFENSE + MONSTER_MIN_DEFENSE;
    new->min_strength = 2;
    new->max_strength = 6;
    new->attacks_by_turn = 1;
    new->attacks_left = new->attacks_by_turn;
    new->turn = false;
    new->draw = NULL;
    new->monster_type = rand() % 3 + 1;

    new->next = head;

#if DEBUG
    printf("Monster %d initialized.\n", new->id);
#endif

    return new;

}

/**
 * free all the list of monster
 * @param head
 */
void free_monster(Monster *head)
{
    if (head != NULL)
    {
        free_monster(head->next);
        free(head);
    }
}
