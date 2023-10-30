//
// Created by louis on 28/10/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../../headers/saves/load-save/load_levels.h"
#include "../../../sqlite3/sqlite3.h"
#include "../../../headers/db_connexion.h"
#include "../../../headers/saves/load-save/load_level_monsters.h"

void load_levels(Game *game, int zone_id) {

    sqlite3 *conn = connect_to_db();
    sqlite3_stmt *res;
    const char *tail;
    char query[200];

    game->zoneList[zone_id]->levelList = malloc(sizeof(Level *) * game->zoneList[zone_id]->height);
    for (int i = 0; i < game->zoneList[zone_id]->height; i++) {                                                 // allouer le tableau de niveaux pour la zone
        game->zoneList[zone_id]->levelList[i] = malloc(sizeof(Level *) * game->zoneList[zone_id]->width);
    }


    int level_id = 0;

    for(int i = 0; i < game->zoneList[zone_id]->height; i++) {
        for(int j = 0; j < game->zoneList[zone_id]->width; j++) {
            sprintf(query, "SELECT * FROM Level WHERE player_id=%d AND zone_id=%d AND height_index=%d AND width_index=%d", game->id, zone_id, i, j); // on recupere le niveau pour la zone[i][j]

            //printf("query : %s", query);
            int error = sqlite3_prepare_v2(conn, query, -1, &res, &tail);
            if (error != SQLITE_OK) {
                fprintf(stderr, "Failed to execute SQL query to select level %d %d for zone %d: %s\n", i, j, zone_id, sqlite3_errmsg(conn));
                sqlite3_close(conn);
                return;
            }

            if(sqlite3_step(res) == SQLITE_ROW) {
                game->zoneList[zone_id]->levelList[i][j] = malloc(sizeof(Level));

                // Récupérer les données du niveau
                game->zoneList[zone_id]->levelList[i][j]->nbMonsters = sqlite3_column_int(res, 2);   // nombre de monstres dans le niveau
                game->zoneList[zone_id]->levelList[i][j]->finished = sqlite3_column_int(res, 3);     // niveau terminé ou non
                game->zoneList[zone_id]->levelList[i][j]->id = level_id;
                game->zoneList[zone_id]->levelList[i][j]->in_zone_id = sqlite3_column_int(res, 7); // emplacement du niveau dans la zone

                load_level_monsters(game->zoneList[zone_id]->levelList[i][j], game->id, zone_id);
                level_id++;
            }
            else {
                game->zoneList[zone_id]->levelList[i][j] = NULL;
            }
        }
    }
    sqlite3_finalize(res); // Finaliser la requête

    //printf("\nNiveaux de la zone recuperes.\n");

}


