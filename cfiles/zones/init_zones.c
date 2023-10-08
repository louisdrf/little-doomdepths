//
// Created by louis on 08/10/2023.
//

#include <stdlib.h>
#include "../../headers/zones/init_zones.h"
#include "../../headers/zones/create_zone.h"
#include "../../headers/zones/generate_random_map.h"
#include "../../headers/includes/structs.h"


void init_zones(Game *game) {

    for(int i = 0; i <NBZONES; i++) {
        game->zoneList[i] = malloc(sizeof(Zone));
        game->zoneList[i]->levelList = create_zone();
    }

}