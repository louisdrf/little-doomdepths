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
        attribute_zone_data(game, i);
        #if DEBUG
                printf("zone %d cree\n", i);
        #endif
    }

}

void attribute_zone_data(Game *game, int id) {

    switch(id) {
        case 0:
            game->zoneList[id]->name = malloc(strlen("Foret enchantee") + 1);
            strcpy(game->zoneList[id]->name, "Foret enchantee");
            game->zoneList[id]->multiplicator = 1.;
            game->zoneList[id]->difficulty = 1;
            break;

        case 1:
            game->zoneList[id]->name = malloc(strlen("Foret profonde") + 1);
            strcpy(game->zoneList[id]->name, "Foret profonde");
            game->zoneList[id]->multiplicator = 1.5;
            game->zoneList[id]->difficulty = 1;
            break;

        case 2:
            game->zoneList[id]->name = malloc(strlen("Terres desacrees") + 1);
            strcpy(game->zoneList[id]->name, "Terres desacrees");
            game->zoneList[id]->multiplicator = 2.;
            game->zoneList[id]->difficulty = 2;
            break;

        case 3:
            game->zoneList[id]->name = malloc(strlen("Zone volcanique") + 1);
            strcpy(game->zoneList[id]->name, "Zone volcanique");
            game->zoneList[id]->multiplicator = 2.;
            game->zoneList[id]->difficulty = 2;
            break;

        case 4:
            game->zoneList[id]->name = malloc(strlen("Sommet du volcan") + 1);
            strcpy(game->zoneList[id]->name, "Sommet du volcan");
            game->zoneList[id]->multiplicator = 2.5;
            game->zoneList[id]->difficulty = 3;
            break;

        default:
            break;
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