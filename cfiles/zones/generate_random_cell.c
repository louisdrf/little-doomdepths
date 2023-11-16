//
// Created by louis on 14/11/2023.
//

#include "../../headers/zones/generate_random_cell.h"
#include "../../headers/utils.h"

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


Level *generate_random_level_type() {

    Level *level = malloc(sizeof(Level));
    return level;
}

