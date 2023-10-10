//
// Created by louis on 10/10/2023.
//

#include "../../headers/zones/display_zone.h"
#include "../../headers/includes/structs.h"


void display_player_zone(Player *player) {

    char *void_cell = "     \n"
                      "     \n"
                      "     \n";
    char *level_cell = "-----\n"
                       "|    |\n"
                       "|    |\n"
                       "-----\n";

    for(int i = 0; i < player->current_zone->height; i++) {
        for(int j = 0; j < player->current_zone->width; j++) {

        }
    }
}
