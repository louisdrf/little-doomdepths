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
#include "../../headers/utils.h"
#include "../../headers/init/init_boss.h"


#define DEBUG false

/**
 * create a level with its own monsters list
 * @param id
 * @return
 */
Level *init_level(int id, double multiplicator, int type) {

    int randnbloot = 0;

    Level *level = malloc(sizeof(Level));
    if(level == NULL) {
        printf("Allocating memory for level failed.\n");
        exit(1);
    }

    level->id = id;
    level->finished = false;
    level->level_type = type;

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

#if DEBUG
    printf("Level %d correctly initialized.\n", level->id);
#endif

    return level;
}


Level *init_level_boss(int id, double multiplicator, int type) {

    // create a level
    Level *level = malloc(sizeof(Level));
    if(level == NULL) {
        printf("Allocating memory for level failed.\n");
        exit(1);
    }

    level->id = id;
    level->finished = 0;
    level->level_type = type;


    level->nbMonsters = 0;
    level->monsters = NULL;


#if DEBUG
    printf("Level chest %d correctly initialized.\n", level->id);
#endif

    return level;
}



Level *init_level_chest(int id, double multiplicator, int type) {
    //
    Level *level = malloc(sizeof(Level));
    if(level == NULL) {
        printf("Allocating memory for level failed.\n");
        exit(1);
    }

    int hasWeapon = random_int(0, 1);
    int hasArmor = random_int(0, 1);

    level->id = id;
    level->finished = 0;
    level->level_type = type;

    level->loot_gold = (int)(random_int(50, 100) * multiplicator);

    if(hasArmor == 0)
        level->loot_armor = randomArmor();
    else level->loot_armor = NULL;

    if(hasWeapon == 0)
        level->loot_weapon = randomWeapon();
    else level->loot_weapon = NULL;

    if(level == NULL)
        return NULL;

    return level;
}


