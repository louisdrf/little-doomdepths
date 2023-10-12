//
// Created by louis on 10/10/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../headers/zones/display_zone.h"
#include "../../headers/includes/structs.h"
#include "../../headers/includes/colors.h"


void display_player_zone(Player *player) {

    char *void_cell[7] = {
            "                   ",
            "                   ",
            "                   ",
            "                   ",
            "                   ",
            "                   ",
            "                   "
    };

    char *level_cell[7] = {
            "*----------------*",
            "|    .-\"\"\"-.     |",
            "|   /       \\    |",
            "|   ](_\\ /_)[    |",
            "|   `-. N ,-'    |",
            "|     \\\\|//      |",
            "*----------------*"
    };

    char *player_cell[7] = {
            "*-----------------*",
            "|  ('_/-\\\\-._     |",
            "| /,|`--._,-^ |   |",
            "| \\_| |     | |   |",
            "|   |  `\\ /   |   |",
            "|    \\__| |__/    |",
            "*-----------------*"
    };





    int j = 0;
    int i = 0;

    for (i = 0; i < player->current_zone->height; i++) {

        for (int line = 0; line < 7; line++) { // 7 lignes dans level_cell ou void_cell
            for (j = 0; j < player->current_zone->width; j++) {
                if (player->current_zone->levelList[i][j] != NULL) {

                        if(player->current_zone->levelList[i][j] == player->current_level) {        // afficher en rouge le niveau où se situe le joueur
                            printf(BLUE"%s"RESET, player_cell[line]);
                        }
                        else printf(RED"%s"RESET, level_cell[line]);

                } else {
                    printf("%s", void_cell[line]);
                }
            }
            printf("\n");
        }
    }

}
