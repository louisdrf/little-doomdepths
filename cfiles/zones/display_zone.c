//
// Created by louis on 10/10/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "../../headers/zones/display_zone.h"
#include "../../headers/includes/structs.h"
#include "../../headers/includes/colors.h"

#define NBLINES 7

void display_player_zone(Player *player, Game *game) {

    char *void_cell[NBLINES] = {
            "                  ",
            "                  ",
            "                  ",
            "                  ",
            "                  ",
            "                  ",
            "                  "
    };

    char *level_cell[NBLINES] = {
            "*----------------*",
            "|    .-\"\"\"-.     |",
            "|   /       \\    |",
            "|   ](_\\ /_)[    |",
            "|   `-. N ,-'    |",
            "|     \\\\|//      |",
            "*----------------*"
    };

    char *player_cell[NBLINES] = {
            "*-----------------*",
            "|  ('_/-\\\\-._     |",
            "| /,|`--._,-^ |   |",
            "| \\_| |     | |   |",
            "|   |  `\\ /   |   |",
            "|    \\__| |__/    |",
            "*-----------------*"
    };


    printf("\n");

    for (int i = 0; i < player->current_zone->height; i++) {

        for (int line = 0; line < NBLINES; line++) { // 7 lignes dans level_cell ou void_cell
            for (int j = 0; j < player->current_zone->width; j++) {
                if (player->current_zone->levelList[i][j] != NULL) {

                        if(player->current_level == player->current_zone->levelList[i][j]) {        // afficher en rouge le niveau où se situe le joueur
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


void display_all_zones(Player *player, Game *game) {

    system("cls");

    int playerEntry;

    printf("Zone %d : \n\n", game->display_zones_index);
    display_zone(game->zoneList[game->display_zones_index]);
    printf("\n\nZone precedente (<)          Zone suivante (>)\nZone actuelle (z)            Quitter (q)\n");
    printf("-> ");

    playerEntry = getch();

    switch(playerEntry) {

        case 'K':   // K = '<'
            if(game->display_zones_index == 0) display_all_zones(player, game);
            else {
                game->display_zones_index--;
                display_all_zones(player, game);
            }
            break;

        case 'M': // M = '>'
            if(game->display_zones_index == NBZONES-1) display_all_zones(player, game);
            else {
                game->display_zones_index++;
                display_all_zones(player, game);
            }
            break;

        case 'z':
            display_player_zone(player, game);
            break;

        case 'q':
            game->display_zones_index = 0;
            return;

        default:
            display_all_zones(player, game);
    }
}

void display_zone(Zone *zone) {

    char *void_cell[NBLINES] = {
            "                  ",
            "                  ",
            "                  ",
            "                  ",
            "                  ",
            "                  ",
            "                  "
    };

    char *level_cell[NBLINES] = {
            "*----------------*",
            "|    .-\"\"\"-.     |",
            "|   /       \\    |",
            "|   ](_\\ /_)[    |",
            "|   `-. N ,-'    |",
            "|     \\\\|//      |",
            "*----------------*"
    };


    int i , j;

    printf("\n");

    for (i = 0; i < zone->height; i++) {

        for (int line = 0; line < NBLINES; line++) { // 7 lignes dans level_cell ou void_cell
            for (j = 0; j < zone->width; j++) {
                if (zone->levelList[i][j] != NULL)
                {
                     printf(RED"%s"RESET, level_cell[line]);
                }
                else {
                    printf("%s", void_cell[line]);
                }
            }
            printf("\n");
        }
    }

}
