//
// Created by louis on 08/10/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include "../../headers/zones/create_zone.h"
#include "../../headers/zones/generate_random_map.h"
#include "../../headers/init/init_level.h"


Zone *create_zone(Game *game) {

    Zone *zone = malloc(sizeof(Zone));

    Map *map = init_random_map_dimensions();
    if(map != NULL) {

            Level ***levelList = NULL;

            levelList = malloc(sizeof(Level *) * map->height);
            for (int i = 0; i < map->height; i++) {                              // allouer le tableau de niveaux
                levelList[i] = malloc(sizeof(Level *) * map->width);
            }

            int index = 0;

            for (int i = 0; i < map->height; i++) {
                for (int j = 0; j < map->width; j++) {
                    if (map->map[i][j] == 1) {
                        levelList[i][j] = init_level(index);            // creer un niveau avec son id
                        index++;
                    } else {
                        levelList[i][j] = NULL;
                    }
                }
            }

                if (levelList != NULL) {
                    zone->levelList = levelList;
                    zone->height = map->height;
                    zone->width = map->width;
                }

            for (int i = 0; i < map->height; i++) {
                free(map->map[i]);
            }
            free(map->map);
            free(map);


            if(zone->levelList != NULL) return zone;
            else return NULL;


    }
    else {
        printf("Map initializing failed.\n");
        return NULL;
    }

}
