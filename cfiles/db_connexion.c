//
// Created by louis on 25/10/2023.
//

#include <stdio.h>
#include <malloc.h>
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
