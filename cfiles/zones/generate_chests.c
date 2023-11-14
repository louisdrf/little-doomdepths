//
// Created by louis on 14/11/2023.
//

#include "../../headers/zones/generate_chests.h"
#include "../../headers/utils.h"


void generate_chests(Map *map) {

    int nbChests = random_int(1, 2);
    int chestPosX = random_int(0, map->width);
    int chestPosY = random_int(0, map->height);

    for(int i = 0; i < nbChests; i++) {

        while(map->map[chestPosX][chestPosY] != VOID && map->map[chestPosX][chestPosY] != CHEST)
        {
            chestPosX = random_int(0, map->width);
            chestPosY = random_int(0, map->height);
        }
        map->map[chestPosX][chestPosY] = CHEST;
    }
}
