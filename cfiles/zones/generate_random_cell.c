//
// Created by louis on 14/11/2023.
//

#include "../../headers/zones/generate_random_cell.h"
#include "../../headers/utils.h"
#include "../../headers/init/init_level.h"

void generate_random_cell(Map *map) {

    int randomPosX = random_int(0, map->width - 1);
    int randomPosY = random_int(0, map->height - 1);

        while(map->map[randomPosX][randomPosY] != VOID)
        {
            randomPosX = random_int(0, map->width - 1);
            randomPosY = random_int(0, map->height - 1);
        }

    map->map[randomPosX][randomPosY] = RANDOM;
}


Level *generate_random_level_type(int id, double multiplicator) {

    Level *level = NULL;
    int level_type = random_int(CHEST, SHOP);

    switch(level_type) {

        case CHEST:
            level = init_level_chest(id, multiplicator, CHEST);
            break;

        case SHOP:
            //level = init_level_shop();
            break;

        default:
            free(level);
            generate_random_level_type(id, multiplicator);
    }

    return level;
}

