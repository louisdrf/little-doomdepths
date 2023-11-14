//
// Created by louis on 14/11/2023.
//

#include <stdio.h>
#include "../../headers/zones/generate_chests.h"
#include "../../headers/utils.h"

#define DEBUG false

void generate_chests(Map *map) {

    int chestPosX = random_int(0, map->width - 1);
    int chestPosY = random_int(0, map->height - 1);

        while(map->map[chestPosX][chestPosY] != VOID)
        {
            chestPosX = random_int(0, map->width - 1);
            chestPosY = random_int(0, map->height - 1);
        }

        map->map[chestPosX][chestPosY] = CHEST;
}

