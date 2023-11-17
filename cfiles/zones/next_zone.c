//
// Created by louis on 15/11/2023.
//

#include "../../headers/zones/next_zone.h"

void next_zone_updates(Player *player, Game *game) {

    player->current_zone->map[player->currentX][player->currentY] = FINISHED;
    player->current_zone = game->zoneList[player->current_zone->id + 1];
    player->current_level = player->current_zone->levelList[player->currentX][player->currentY];
}