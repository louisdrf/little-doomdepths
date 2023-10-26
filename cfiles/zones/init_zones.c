//
// Created by louis on 08/10/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../headers/zones/init_zones.h"
#include "../../headers/zones/create_zone.h"

#define DEBUG false


void init_zones(Game *game) {

    for(int i = 0; i < NBZONES; i++) {
        game->zoneList[i] = create_zone(game);
        game->zoneList[i]->id = i;
        game->zoneList[i]->finished = false;
        game->zoneList[i]->name = malloc(strlen("zone1") + 1);
        strcpy(game->zoneList[i]->name, "zone1");
        game->zoneList[i]->multiplicator = 1.5;
        #if DEBUG
                printf("zone %d cree\n", i);
        #endif
    }

}


void free_zones(Game *game) {
    for(int i = 0; i < NBZONES; i++) {
        free(game->zoneList[i]);
#if DEBUG
        printf("zone %d correctly free\n", i);
#endif
    }
}