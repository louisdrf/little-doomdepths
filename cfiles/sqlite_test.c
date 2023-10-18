//
// Created by louis on 16/10/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "sqlite_test.h"
#include "../sqlite3/sqlite3.h"

void init_connexion() {

    sqlite3 *conn;
    sqlite3_stmt    *res;
    char *err_msg = 0;
    int error = 0;
    int rec_count = 0;
    const char *tail;

    int rc = sqlite3_open("../identifier.sqlite", &conn);

    if (rc != SQLITE_OK) {

        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(conn));
        sqlite3_close(conn);
    }

    fprintf(stdout, "Database opened successfully\n");



    const char *sql_query = "SELECT id, nom, prenom, mail FROM user";
    error = sqlite3_prepare_v2(conn, sql_query, -1, &res, &tail);
    if (error != SQLITE_OK) {
        fprintf(stderr, "Failed to execute SQL query: %s\n", sqlite3_errmsg(conn));
        sqlite3_close(conn);
        return;
    }

    while (sqlite3_step(res) == SQLITE_ROW) {
        int id = sqlite3_column_int(res, 0);
        const unsigned char *nom = sqlite3_column_text(res, 1);
        const unsigned char *prenom = sqlite3_column_text(res, 2);
        const unsigned char *mail = sqlite3_column_text(res, 3);
        printf("Id: %d, nom: %s, prenom: %s, Mail: %s\n", id, nom, prenom, mail);
        rec_count++;
    }

    sqlite3_finalize(res);
    sqlite3_close(conn);
}

