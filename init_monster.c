//
// Created by louis on 23/09/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "init_monster.h"
#include "structs.h"
#include "defines.h"

#define DEBUG true
/**
 * create a Monster * and add it to the linked list of Monster
 */
Monster *create_monster(Monster *head, int index) {

    srand(time(NULL));

    Monster *new = malloc(sizeof(Monster));
    if(new == NULL) {
#if DEBUG
        printf("Error while allocating memory for monster.\n");
        exit(1);
#endif
    }

    new->id = index;
    new->lifepoints = rand() % MONSTER_MAX_PV + MONSTER_MIN_PV;
    new->defense = rand() % MONSTER_MAX_DEFENSE + MONSTER_MIN_DEFENSE;
    new->min_strength = 10;
    new->max_strength = 20;
    new->attacks_by_turn = 1;
    new->turn = false;
    new->draw = NULL;
    new->monster_type = rand() % 3 + 1;

    new->next = head;

#if DEBUG
    printf("Monster %d initialized.\n", new->id);
#endif

    return new;

}


void free_monster(Monster *head)
{
    if (head != NULL)
    {
        free_monster(head->next);
        free(head);
    }
}
