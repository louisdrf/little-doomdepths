//
// Created by louis on 16/10/2023.
//

#include <stdio.h>
#include "sqlite_test.h"
#include "../sqlite3/sqlite3.h"

void init_connexion() {

    sqlite3 *db;
    char *err_msg = 0;

    int rc = sqlite3_open("identifier.sqlite", &db);

    if (rc != SQLITE_OK) {

        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
    }

    fprintf(stdout, "Database opened successfully\n");
    sqlite3_close(db);
}