//
// Created by louis on 05/10/2023.
//

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../headers/zones/generate_random_map.h"
#include "../../headers/utils.h"
#include "../../headers/zones/generate_chests.h"

#define DEBUG false

/**
 * return a random dimensions tab full of 0
 */
Map *init_random_map_dimensions(int x, int y) {

    Map *map = malloc(sizeof(Map));

    map->height = random_int(NBLEVELX_MIN, NBLEVELX_MAX);
    map->width = random_int(NBLEVELX_MIN, NBLEVELX_MAX);;

    int path_length = (int)((map->height * map->width) * 0.8);

    map->map = calloc(map->height, sizeof(int*));
    for (int i = 0; i < map->height; i++) {
        map->map[i] = calloc(map->width, sizeof(int));
    }



    map->map[x][y] = 1;
    int k = 1;

    int attempts = 0;
    int max_attempts = 20;


    do {
        // Choisir une direction aléatoire (0: haut, 1: bas, 2: gauche, 3: droite)
        int direction = rand() % 4;

        if (direction == 0 && y > 0) {
            y--;
            if(map->map[x][y] == 0) {
                map->map[x][y] = 1;
                k++;
            }
        }
        else if (direction == 1 && y < (map->width - 1)) {
            y++;
            if(map->map[x][y] == 0) {
                map->map[x][y] = 1;
                k++;
            }
        }
        else if (direction == 2 && x > 0) {
            x--;
            if(map->map[x][y] == 0) {
                map->map[x][y] = 1;
                k++;
            }
        }
        else if (direction == 3 && x < (map->height - 1)) {
            x++;
            if(map->map[x][y] == 0) {
                map->map[x][y] = 1;
                k++;
            }
        }
        else {
            attempts++; // Incrémenter le compteur de tentatives infructueuses

            if (attempts > max_attempts) {
                // Si le nombre de tentatives dépasse le seuil, réinitialiser les coordonnées
                x = 0;
                y = 0;
                attempts = 0; // Réinitialiser le compteur de tentatives
            }
            continue;
        }
        if(k == path_length){
            map->map[x][y] = 2;
        }
    } while (k != path_length);


    generate_chests(map);


#if DEBUG
    for(int i = 0; i < map->height; i++) {
        for(int j = 0; j < map->width; j++) {
            printf("%d ", map->map[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
#endif


    if(map != NULL) return map;
    else {
        printf("Map null");
        return NULL;
    }

}
