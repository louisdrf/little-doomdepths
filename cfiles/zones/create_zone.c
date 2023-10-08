//
// Created by louis on 08/10/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include "../../headers/zones/create_zone.h"
#include "../../headers/zones/generate_random_map.h"
#include "../../headers/includes/structs.h"
#include "../../headers/init/init_level.h"


Level ***create_zone() {

    Map *map = init_random_map_dimensions();

    Level ***levelList = NULL;

    levelList = malloc(sizeof(Level*) * map->height);
    for (int i = 0; i < map->height; i++) {                              // allouer le tableau de niveaux
        levelList[i] = malloc(sizeof(Level*) * map->width);
    }

    for(int i = 0; i < map->height; i++) {
        for(int j = 0; j < map->width; j++) {

            if(map->map[i][j] == 1) {
                levelList[i][j] = init_level((i+j));            // creer un niveau avec son id
            }
            else {
                levelList[i][j] = NULL;
            }
        }
    }

    for (int i = 0; i < map->height; i++) {
        free(map->map[i]);
    }
    free(map);

    return levelList;

}
