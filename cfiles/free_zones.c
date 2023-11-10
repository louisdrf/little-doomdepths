//
// Created by louis on 10/11/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include "free_zones.h"
#include "../headers/includes/colors.h"

#define DEBUG false

void free_all_zones(Game *game) {

    for(int i = 0; i < NBZONES; i++) {
        free_zone(game, i);
#if DEBUG
        printf("zone %d correctly free\n", i);
#endif
    }

}



void free_zone(Game *game, int zone_id) {

#if DEBUG
    printf(YELLOW"ZONE %d\n\n"RESET, zone_id);
#endif

    if(game->zoneList[zone_id] == NULL) return;

    for(int i = 0; i < game->zoneList[zone_id]->height; i++) {
        for(int j = 0; j < game->zoneList[zone_id]->width; j++) {

            if(game->zoneList[zone_id]->levelList[i][j] != NULL) {
                free_level(game, zone_id, i, j);
            }
#if DEBUG
            printf(GREEN"zone Levels free\n\n"RESET);
#endif
        }
    }
    free(game->zoneList[zone_id]->name);
    free(game->zoneList[zone_id]);

#if DEBUG
    printf("All zone Levels free\n\n");
#endif
}


// + liberer le loot
void free_level(Game *game, int zone_id , int i, int j) {

    Monster *current = game->zoneList[zone_id]->levelList[i][j]->monsters;
    Monster *next;

    while (current != NULL) {
#if DEBUG
        printf("Desallocating monster\n");
#endif
        next = current->next;
        free(current->draw);
        free(current);
        current = next;
    }

#if DEBUG
    printf(RED"\nfree monsters done\n"RESET);
#endif

}