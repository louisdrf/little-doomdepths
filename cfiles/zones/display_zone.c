//
// Created by louis on 10/10/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "../../headers/display.h"
#include "../../headers/zones/display_zone.h"
#include "../../headers/includes/structs.h"
#include "../../headers/includes/colors.h"
#include "../../headers/utils.h"

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

    char *stairs_cell[NBLINES] = {
            "*----------------*",
            "|    |________|| |",
            "|   |________| | |",
            "|  |________|  | |",
            "| |________|   | |",
            "||________|____| |",
            "*----------------*"
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
            "*----------------*",
            "|  ('_/-\\\\-._    |",
            "| /,|`--._,-^ |  |",
            "| \\_| |     | |  |",
            "|   |  `\\ /   |  |",
            "|    \\__| |__/   |",
            "*----------------*"
    };
    int playerEntry;
    int j = 0;
    int i = 0;
    clear();
    printf("\n");

    for (i = 0; i < player->current_zone->height; i++) {

        for (int line = 0; line < NBLINES; line++) { // 7 lignes dans level_cell ou void_cell
            for (j = 0; j < player->current_zone->width; j++) {
                if (player->current_zone->map[i][j] != VOID) {

                    if(player->current_level == player->current_zone->levelList[i][j])

                        printf("%s""%s""%s", BLUE, player_cell[line], RESET);

                    else if(player->current_zone->map[i][j] == BOSS)

                        printf("%s""%s""%s", GREEN, stairs_cell[line], RESET);

                    else {

                        if(player->current_zone->levelList[i][j]->finished == true)

                            printf( "%s""%s""%s", GREEN, level_cell[line], RESET);

                        else
                            printf("%s""%s""%s", RED, level_cell[line], RESET);
                    }

                } else {
                    printf("%s", void_cell[line]);
                }
            }
            printf("\n");
        }
    }

}

void display_player_all_zone(Player *player, Game *game) {

    display_player_zone(player, game);
    printf("Afficher toutes les zones (z)        Retour (q)\n-> ");
    int playerEntry = getch();
    switch(playerEntry) {
        case 'z':
            display_all_zones(player, game);
            break;

        case 'q':

            clear();
            //display_all(player);
            break;
            //return;

        default:
            display_player_all_zone(player, game);
    }

}



void display_all_zones(Player *player, Game *game) {

    clear();

    int playerEntry;

    printf(RED"Zone %d : %s\n\n"RESET, game->display_zones_index, game->zoneList[game->display_zones_index]->name);
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
            display_player_all_zone(player, game);
            break;

        case 'q':
            clear();
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
