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
#include "../../headers/inventory/potion.h"
#define DEBUG false


/**
 * create a Monster * and add it to the linked list of Monster
 */
Monster *create_monster(Monster *head, int index) {
    srand(time(NULL));
    int mRandPotion = -1;
    int mRandWoA = -1;
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
    mRandWoA = rand() % 3+ 1;
    if(mRandWoA != -1 ) {
        if(mRandWoA == 1 ){
            new->monster_weapon = randomWeapon(); // rand() weapon generate by rarity.
            if(new->monster_weapon == NULL){
#if DEBUG
                printf("Erreur lors de la création de l'arme du monstre\n");
#endif
            }
        }
        if(mRandWoA == 2 ){
            new->monster_armor = randomArmor();  // rand() armor generate by rarity.
            if(new->monster_armor == NULL){
#if DEBUG
                printf("Erreur lors de la création de l'armure du monstre\n");
#endif
            }
        }
        if (mRandWoA != 1 && mRandWoA != 2 ){
            new->monster_weapon = NULL;
            new->monster_armor = NULL;
        }

    }else{
#if DEBUG
        printf("Erreur lors de l'operation rand() pour cree l'arme et l'armure d'un monstre'.\n");
#endif
    }

    new->monster_healthPotion = NULL;
    new->monster_manaPotion = NULL;
    mRandPotion = rand() % 3 + 1;
    if(mRandPotion != -1){
        char* sprite = " mmm\n"
                       " |-|\n"
                       "(   )\n"
                       "|   |\n"
                       "|   |\n"
                       "|___|";

        if(mRandPotion == 1) {
            Potion *healthPotion = createPotion("Potion de vie", sprite, 30, 0);
            if (healthPotion != NULL) {
                new->monster_healthPotion = healthPotion;
            } else {
#if DEBUG
                printf("Erreur lors de la création de la potion de vie d'un monstre.\n");
#endif

            }
        }
        if(mRandPotion == 2){
            Potion *manaPotion = createPotion("Potion de mana", sprite, 0, 30);
            if (manaPotion != NULL){
                new->monster_manaPotion = manaPotion;
            }else{
#if DEBUG
                printf("Erreur lors de la création de la potion de mana d'un monstre.\n");
#endif
            }
        }
        if(mRandPotion != 1 && mRandPotion != 2){
            new->monster_healthPotion = NULL;
            new->monster_manaPotion = NULL;
        }
    }else {
#if DEBUG
        printf("Erreur lors de l'operation rand() pour cree la Potion d'un monstre'.\n");
#endif
    }
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
