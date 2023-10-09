//
// Created by louis on 08/10/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include "../../headers/zones/init_zones.h"
#include "../../headers/zones/create_zone.h"
#include "../../headers/zones/generate_random_map.h"
#include "../../headers/includes/structs.h"

#define DEBUG true


void init_zones(Game *game) {

    for(int i = 0; i < NBZONES; i++) {
        game->zoneList[i] = malloc(sizeof(Zone));
        if (game->zoneList[i] == NULL) {
            printf("Allocating memory for zone %d failed.\n", i);
            exit(1);
        }
        game->zoneList[i]->levelList = create_zone();
        game->zoneList[i]->id = i;
        printf("zone %d cree\n", i);
    }

}