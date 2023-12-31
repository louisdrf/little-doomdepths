//
// Created by louis on 05/10/2023.
//

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../headers/zones/generate_random_map.h"
#include "../../headers/utils.h"
#include "../../headers/zones/generate_random_cell.h"

#define DEBUG false

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

#define NB_RANDOM_CELLS_MAX 2

Map *init_random_map_dimensions(int x, int y) {

    Map *map = init_map();
    map->map[x][y] = LEVEL;

    int path_length = (int)((map->height * map->width) * 0.8);
    int level_count = 1;
    int nb_random_cells = 0;
    int direction;

    do {
            direction = random_int(0, 3);

            switch(direction) {
                case UP:
                    if(y > 0)
                        y--;
                    break;

                case DOWN:
                    if(y < (map->width - 1))
                        y++;
                    break;

                case LEFT:
                    if(x > 0)
                        x--;
                    break;

                case RIGHT:
                    if(x < (map->height - 1))
                        x++;
                    break;
            }

            if(map->map[x][y] == VOID) {
                map->map[x][y] = LEVEL;

                if(nb_random_cells != NB_RANDOM_CELLS_MAX) {
                    int random_cell = random_int(1, 3);
                    if(random_cell == 2) map->map[x][y] = RANDOM;       // 1 chance sur 3 de générer une case random
                    nb_random_cells++;
                }

                level_count++;
            }

            if(level_count == path_length)
                map->map[x][y] = BOSS;

    } while (level_count != path_length);


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


Map *init_map() {

    Map *map = malloc(sizeof(Map));

    map->height = random_int(NBLEVELX_MIN, NBLEVELX_MAX);
    map->width = random_int(NBLEVELX_MIN, NBLEVELX_MAX);;

    map->map = calloc(map->height, sizeof(int*));
    for (int i = 0; i < map->height; i++) {
        map->map[i] = calloc(map->width, sizeof(int));
    }

    if(map != NULL) return map;
    else {
        fprintf(stderr, "Allocating and init map dimensions failed\n");
        exit(1);
    }
}
