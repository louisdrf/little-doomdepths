//
// Created by louis on 08/10/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include "../../headers/zones/create_zone.h"
#include "../../headers/zones/generate_random_map.h"
#include "../../headers/init/init_level.h"


Zone *create_zone(Game *game, int id, double multiplicator) {

    Zone *zone = malloc(sizeof(Zone));
    Map *map = init_random_map_dimensions(0,0);

    int **tab = calloc(map->height, sizeof(int *));
    for (int a = 0; a < map->height; a++)
    {
        tab[a] = calloc(map->width, sizeof(int));
    }

    if(id == 0) {

        map = init_random_map_dimensions(0,0);

    } else {
        Zone *log_zone=game->zoneList[id-1];
        for(int i = 0; i < log_zone->height; i++) {
            for(int j = 0; j < log_zone->width; j++) {

                if(log_zone->map[i][j] == 2){
                    map = init_random_map_dimensions(i,j);
                }
            }
        }

    }
    if(map != NULL) {

            Level ***levelList = NULL;

            levelList = malloc(sizeof(Level *) * map->height);
            for (int i = 0; i < map->height; i++) {                              // allouer le tableau de niveaux
                levelList[i] = malloc(sizeof(Level *) * map->width);
            }

            int index = 0;

            for (int i = 0; i < map->height; i++) {
                for (int j = 0; j < map->width; j++) {

                    switch(map->map[i][j]) {
                        case 1:
                            levelList[i][j] = init_level(index, multiplicator);            // creer un niveau avec son id
                            break;

                        case 2:
                            levelList[i][j] = init_level_boss(index,multiplicator);            // creer un niveau avec son id
                            break;

                        default:
                            levelList[i][j] = NULL;
                            break;
                    }

                    index++;
                }
            }

            for(int i = 0; i < map->height; i++) {
                for(int j = 0; j < map->width; j++) {
                    tab[i][j] = map->map[i][j];
#if DEBUG
                    printf("%d ", tab[i][j]);
#endif
                }
#if DEBUG
                printf("\n");
#endif
            }
#if DEBUG
        printf("\n");
#endif

                if (levelList != NULL) {
                    zone->levelList = levelList;
                    zone->height = map->height;
                    zone->width = map->width;
                }

                zone->map = tab;

            for (int i = 0; i < map->height; i++) {
                free(map->map[i]);
            }
            free(map->map);
            free(map);


            if(zone->levelList != NULL) return zone;
            else {
                printf("Zone level list null\n");
                return NULL;
            }


    }
    else {
        printf("Map initializing failed.\n");
        return NULL;
    }

}
