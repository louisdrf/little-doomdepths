//
// Created by louis on 25/10/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "../../headers/player/has_player_a_save.h"
#include "../../headers/db_connexion.h"


/*
 * check if the chosen game has already a save to load
 */
int has_player_a_save(int id) {

    sqlite3 *conn = connect_to_db();
    sqlite3_stmt *res;
    int req = 0;
    const char *tail;
    int hasSave = 0;

    char query[50];
    sprintf(query, "SELECT hasSave from Game WHERE id=%d;", id);

    req = sqlite3_prepare_v2(conn, query, -1, &res, &tail);
    if (req != SQLITE_OK) {
        fprintf(stderr, "Failed to execute SQL query to insert Game: %s\n", sqlite3_errmsg(conn));
        sqlite3_close(conn);
        exit(1);
    }

    req = sqlite3_step(res); // Execute the prepared query
    if (req == SQLITE_ROW) {
        hasSave = sqlite3_column_int(res, 0); // Retrieve the value from the result set
    } else if (req != SQLITE_DONE) {
        fprintf(stderr, "Failed to execute SQL query: %s\n", sqlite3_errmsg(conn));
    }

    sqlite3_finalize(res); // Finalize the query
    sqlite3_close(conn); // Close the connection

    return hasSave;
}