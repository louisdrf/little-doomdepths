//
// Created by louis on 05/10/2023.
//

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../../headers/zones/generate_random_map.h"
#include "../../headers/zones/define_zones.h"


/**
 * return a random dimensions tab full of 0
 */
int **init_random_map_dimensions() {
    srand(time(NULL));

    int height = rand() % (NBLEVELX_MAX - NBLEVELX_MIN + 1) + NBLEVELX_MIN;
    int width = rand() % (NBLEVELX_MAX - NBLEVELX_MIN + 1) + NBLEVELX_MIN;

    int path_length = (int)((height * width) * 0.7);

    printf("longueur de chemin : %d\n", path_length);

    int **tab = calloc(height, sizeof(int *));
    for (int i = 0; i < height; i++) {
        tab[i] = calloc(width, sizeof(int));
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }

    int x = 0;
    int y = 0;

    printf("start x : %d , start y : %d\n", x, y);

    tab[x][y] = 1;
    int k = 1;

    int attempts = 0;
    int max_attempts = 20;


    do {
        // Choisir une direction aléatoire (0: haut, 1: bas, 2: gauche, 3: droite)
        int direction = rand() % 4;

        if (direction == 0 && y > 0) {
            y--;
            if(tab[x][y] == 0) {
                tab[x][y] = 1;
                k++;
            }
        }
        else if (direction == 1 && y < (width - 1)) {
            y++;
            if(tab[x][y] == 0) {
                tab[x][y] = 1;
                k++;
            }
        }
        else if (direction == 2 && x > 0) {
            x--;
            if(tab[x][y] == 0) {
                tab[x][y] = 1;
                k++;
            }
        }
        else if (direction == 3 && x < (height - 1)) {
            x++;
            if(tab[x][y] == 0) {
                tab[x][y] = 1;
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

    } while (k != path_length);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }

    printf("\n\nx : %d    y : %d     k : %d     path len : %d\n", x, y, k, path_length);



    return tab;
}
