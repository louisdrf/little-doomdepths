//
// Created by louis on 22/10/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "../../../headers/saves/create-save/save_player.h"
#include "../../../sqlite3/sqlite3.h"
#include "../../../headers/db_connexion.h"

#define DEBUG true

void save_player(Player *player, sqlite3** conn) {

    char query[300];

    if(conn != NULL) {

        sprintf(query, "UPDATE Game SET hasSave=1 WHERE id=%d;", player->id);
        prepare_and_exec_query(conn, query);
        if(!prepare_and_exec_query(conn, query)) {
            printf("\nFailed to prepare/execute query to update game hasSave.\n");
            exit(1);
        }


        sprintf(query, "UPDATE Player SET name='%s', lifepoints=%d, shield=%d, mana=%d, attacks_left=%d, gold=%d, turn=%d, current_level_id=%d, current_zone_id=%d, posX=%d, posY=%d WHERE id = %d;",
                player->name,
                player->lifepoints,
                player->shield,
                player->mana,
                player->attacks_left,
                player->gold,
                player->turn,
                player->current_level->id,
                player->current_zone->id,
                0, 0,
                player->id);
        printf("\nquery : %s", query);

        prepare_and_exec_query(conn, query);
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
