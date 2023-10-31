//
// Created by louis on 23/09/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../../headers/init/init_monster.h"
#include "../../headers/includes/structs.h"
#include "../../headers/includes/defines.h"
#include "../../headers/monsters/monster_sprite.h"
#include "../../headers/weapon/init_weapon.h"
#include "../../headers/armor/init_armor.h"

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
    new->monster_type = rand() % NB_MONSTER_TYPE;
    new->isAlive = true;
    new->loot_gold = rand() % MAX_GOLD_LOOT + MIN_GOLD_LOOT;
    new->next = head;
    new->drawIndex = 0;
    new->monster_weapon = NULL;
    new->monster_armor = NULL;
    Weapon *weapon1 = init_weapon("Monster_Loot_epee1", 2, 8, 18, 4, RARE);
    Armor *armor1 = init_armor("Monster_Loot_armure1", 10, RARE);

    new->monster_weapon = weapon1;
    new->monster_armor = armor1;
    char *sprite = return_monster_sprite(new->monster_type);
    new->draw = malloc(strlen(sprite) + 1);
    strcpy(new->draw, sprite);


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
        free(head->draw);
        free_monster(head->next);
        free(head);
    }
}
