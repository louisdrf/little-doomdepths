//
// Created by louis on 10/10/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../headers/zones/display_zone.h"
#include "../../headers/includes/structs.h"


void display_player_zone(Player *player) {

    char *void_cell[4] = {
            "      ",
            "      ",
            "      ",
            "      "
    };

    char *level_cell[4] = {
            " ____ ",
            "|    |",
            "|    |",
            " ---- "
    };

    int j = 0;
    int i = 0;

    for (i = 0; i < player->current_zone->height; i++) {

        for (int line = 0; line < 4; line++) { // 4 lignes dans level_cell ou void_cell
            for (j = 0; j < player->current_zone->width; j++) {
                if (player->current_zone->levelList[i][j] != NULL) {
                    printf("%s", level_cell[line]);
                } else {
                    printf("%s", void_cell[line]);
                }
            }
            if(line != 3) printf("\n");
        }
    }

}
