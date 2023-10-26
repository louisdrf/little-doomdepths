//
// Created by louis on 25/10/2023.
//

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "../headers/db_connexion.h"
#include "../sqlite3/sqlite3.h"

#define DEBUG false

sqlite3* connect_to_db() {

    sqlite3 *conn = malloc(sizeof(sqlite3*));

    int rc = sqlite3_open("../identifier.sqlite", &conn);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(conn));
        sqlite3_close(conn);
    }

#if DEBUG
    printf("Database opened successfully.\n");
#endif

    return conn;
}



bool prepare_and_exec_query(sqlite3 **conn, char *query) {

    sqlite3_stmt *res;
    int req = 0;
    const char *tail;

    req = sqlite3_prepare_v2(*conn, query, -1, &res, &tail);
    if (req != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare SQL query: %s\n", sqlite3_errmsg(*conn));
        sqlite3_close(*conn);
        return false;
    }

    req = sqlite3_step(res); // Exécuter la requête préparée
    if (req != SQLITE_DONE) {
        fprintf(stderr, "Failed to execute SQL query: %s\n", sqlite3_errmsg(*conn));
        sqlite3_finalize(res); // Finaliser la requête
        sqlite3_close(*conn);
        return false;
    }

    sqlite3_finalize(res); // Finaliser la requête
    return true;
}
