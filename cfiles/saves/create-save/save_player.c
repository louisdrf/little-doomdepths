//
// Created by louis on 22/10/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "../../../headers/saves/create-save/save_player.h"
#include "../../../sqlite3/sqlite3.h"
#include "../../../headers/saves/db_connexion.h"

#define DEBUG false

void save_player(Player *player, sqlite3** conn) {

    char query[300];

    if(conn != NULL) {


        sprintf(query, "UPDATE Player SET name='%s', lifepoints=%d, lifepoints_max=%d, shield=%d, mana=%d, mana_max=%d, attacks_left=%d, gold=%d, turn=%d, current_level_id=%d, current_zone_id=%d, posX=%d, posY=%d, nbKill=%d, nbQuestDone=%d, nbLevelFinished=%d, levelXP=%d, totalXP=%d, currentXP=%d, nbSpells=%d WHERE id=%d;",
                player->name,
                player->lifepoints,
                player->lifepoints_max,
                player->shield,
                player->mana,
                player->mana_max,
                player->attacks_left,
                player->gold,
                player->turn,
                player->current_level->id,
                player->current_zone->id,
                player->currentX,
                player->currentY,
                player->nbKill,
                player->nbQuestDone,
                player->nbLevelFinished,
                player->levelXP,
                player->totalXP,
                player->currentXP,
                player->nbSpells,
                player->id);
#if DEBUG
        printf("\nquery : %s", query);
#endif

        if(!prepare_and_exec_query(conn, query)) {
            printf("\nFailed to prepare/execute query to update player data.\n");
            exit(1);
        }
    }

    else {
        printf("conn null");
        exit(1);
    }

#if DEBUG
    printf("\nUpdate player done.");
#endif

}

