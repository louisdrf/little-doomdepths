//
// Created by louis on 08/10/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include "../../headers/zones/create_map_from_tab.h"
#include "../../headers/zones/generate_random_map.h"
#include "../../headers/includes/structs.h"
#include "../../headers/init/init_level.h"

/*
 * typedef struct {

    char*                   name;                                   // nom de la zone
    double                  multiplicator;                          // multiplicateur de la zone (xp, gold, monstres...)
    unsigned short          nbLevels;                               // nombre de niveaux/étages de la zone
    Level***                levelList;                              // tableaux à deux dimensions des niveaux de la zone
    bool                    finished;                               // true si tous les niveaux de la zone ont été terminés
    unsigned short          difficulty;                             // indicateur du niveau de difficulté de la zone (EASY, MODERATE, HARD)

} Zone;
 */
void create_map_from_tab(int **binary_map, int height, int width) {

    Level ***levelList = NULL;

    levelList = malloc(sizeof(Level*) * height);
    for (int i = 0; i < height; i++) {                              // allouer le tableau de niveaux
        levelList[i] = malloc(sizeof(Level*) * width);
    }

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {

            if(binary_map[i][j] == 1) {
                levelList[i][j] = init_level((i+j));            // creer un niveau avec son id
            }
            else {
                levelList[i][j] = NULL;
            }
        }
    }


    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {

            if(levelList[i][j] == NULL) {
                printf("null ");
            }
            else {
                printf("niveau ");
            }
        }
        printf("\n");
    }
}
