//
// Created by louis on 24/10/2023.
//

#include <stdio.h>
#include "../../headers/saves/save_levels.h"
#include "../../sqlite3/sqlite3.h"
#include "../../headers/includes/structs.h"


void save_game(Game *game, sqlite3** conn) {

    sqlite3_stmt *res;
    int req = 0;
    const char *tail;

    char query[50];
    sprintf(query, "INSERT INTO Game DEFAULT VALUES;");
    printf("query : %s", query);

    req = sqlite3_prepare_v2(*conn, query, -1, &res, &tail);
    if (req != SQLITE_OK) {
        fprintf(stderr, "Failed to execute SQL query to insert Game: %s\n", sqlite3_errmsg(*conn));
        sqlite3_close(*conn);
        return;
    }

    req = sqlite3_step(res); // Exécuter la requête préparée
    if (req != SQLITE_DONE) {
        fprintf(stderr, "Failed to execute SQL query: %s\n", sqlite3_errmsg(*conn));
        sqlite3_finalize(res); // Finaliser la requête
        sqlite3_close(*conn);
        return;
    }

    sqlite3_finalize(res); // Finaliser la requête
}