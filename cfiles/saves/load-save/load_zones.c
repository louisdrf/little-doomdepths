//
// Created by louis on 28/10/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../../headers/saves/load-save/load_zones.h"
#include "../../../sqlite3/sqlite3.h"
#include "../../../headers/saves/db_connexion.h"
#include "../../../headers/saves/load-save/load_levels.h"

#define DEBUG false

void load_zones(Game *game, sqlite3 **conn) {

    sqlite3_stmt *res; // Variable pour stocker le résultat de la requête
    const char *tail;
    char query[300];

        sprintf(query, "SELECT * FROM Zone WHERE player_id=%d", game->id); // on recupere les zones pour la partie en cours

        int error = sqlite3_prepare_v2(*conn, query, -1, &res, &tail);
        if (error != SQLITE_OK) {
            fprintf(stderr, "Failed to execute SQL query to select zones: %s\n", sqlite3_errmsg(*conn));
            sqlite3_close(*conn);
            return;
        }

        int i = 0;

        // reconstuire la zone avec les données récupérées
        while (sqlite3_step(res) == SQLITE_ROW) {
            game->zoneList[i] = malloc(sizeof(Zone));
            game->zoneList[i]->name = malloc(strlen(sqlite3_column_text(res, 2)) + 1); // nom de la zone
            strcpy(game->zoneList[i]->name, sqlite3_column_text(res, 2));

            game->zoneList[i]->multiplicator = sqlite3_column_double(res, 3);   // multiplicateur de la zone
            game->zoneList[i]->finished = sqlite3_column_int(res, 4);           // zone terminée ou non
            game->zoneList[i]->difficulty = sqlite3_column_int(res, 5);         // niveau de difficulté
            game->zoneList[i]->height = sqlite3_column_int(res, 6);
            game->zoneList[i]->width = sqlite3_column_int(res, 7);
            game->zoneList[i]->id = sqlite3_column_int(res, 8);

            load_levels(game, i, conn);
            i++;
        }

        sqlite3_finalize(res); // Finaliser la requête

#if DEBUG
     for(i = 0; i < NBZONES; i++) {
         printf("Zone %d : %s -> multiplicateur: %lf, finie: %d, diff: %d, height: %d, width: %d\n", i,
                game->zoneList[i]->name,
                game->zoneList[i]->multiplicator,
                game->zoneList[i]->finished,
                game->zoneList[i]->difficulty,
                game->zoneList[i]->height,
                game->zoneList[i]->width);
     }
#endif
}