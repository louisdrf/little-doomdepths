//
// Created by louis on 10/11/2023.
//

#include <stdlib.h>
#include "free_zones.h"



void free_all_zones(Game *game) {
    for(int i = 0; i < NBZONES; i++) {

        free_zone(game, i);
#if DEBUG
        printf("zone %d correctly free\n", i);
#endif
    }
}


/*
 * typedef struct {

    int                     id;
    unsigned short          height;
    unsigned short          width;
    char*                   name;                                   // nom de la zone
    double                  multiplicator;                          // multiplicateur de la zone (xp, gold, monstres...)
    unsigned short          nbLevels;                               // nombre de niveaux/étages de la zone
    Level***                levelList;                              // tableau des niveaux de la zone
    bool                    finished;                               // true si tous les niveaux de la zone ont été terminés
    unsigned short          difficulty;                             // indicateur du niveau de difficulté de la zone (EASY, MODERATE, HARD)
    int**                   map;

} Zone;
 */
void free_zone(Game *game, int index) {
    if(game->zoneList[index] == NULL) return;

    for(int i = 0; i < game->zoneList[index]->height; i++) {
        for(int j = 0; j < game->zoneList[index]->width; j++) {
            free_levels(game, i, j);
        }
    }
    free(game->zoneList[index]->name);
}


void free_levels(Game *game, int i, int j) {

}