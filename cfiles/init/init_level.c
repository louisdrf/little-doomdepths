//
// Created by louis on 24/09/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include "../../headers/init/init_level.h"
#include "../../headers/init/init_monster.h"
#include "../../headers/inventory/potion.h"
#include "../../headers/weapon/init_weapon.h"
#include "../../headers/armor/init_armor.h"
#include "../../headers/rand.h"


#define DEBUG false

/**
 * create a level with its own monsters list
 * @param id
 * @return
 */
Level *init_level(int id, double multiplicator) {

    int randnbloot = 0;
    // create a level
    Level *level = malloc(sizeof(Level));
    if(level == NULL) {
        printf("Allocating memory for level failed.\n");
        exit(1);
    }

    level->id = id;
    level->finished = false;
    level->winMessage = false;

    // init the linked list of monsters for the level
    Monster *first_monster = NULL;
    level->nbMonsters = random_int(NBMONSTERS_MIN , NBMONSTERS_MAX); // nombre de monstres pour le niveau

    for(int j = 1; j < level->nbMonsters + 1; j++) {
        first_monster = create_monster(first_monster, j, multiplicator);
        #if DEBUG
                printf("Monster %d in level %d correctly added.\n", j, level->id);
        #endif
    }

    level->monsters = first_monster; // ajoute la tete de liste de monstres au niveau


    // Initialise le tableau loot_weapon avec des pointeurs NULL

    for(int i =0; i<MAX_LEVEL_LOOT_ITEM;i++){
        level->loot_weapon[i] = NULL;
        level->loot_armor[i] = NULL;
    }
    // random weapon/armor generation by level
randnbloot= rand() % (id + 1); // Generate a random number between 0 and 'id'.
//printf("level id : %d | randnbloot : %d\n",level->id, randnbloot);
for(int l = randnbloot; l > 0; l--){
    if(l % 2 == 0){
        add_loot_item(level, randomWeapon(), NULL);
    }else{
        add_loot_item(level, NULL,  randomArmor());
    }
}
#if DEBUG
printf("Level %d correctly initialized.\n", level->id);
#endif

    return level;
}

