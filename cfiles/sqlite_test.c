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

    int rc = sqlite3_open("identifier.sqlite", &conn);

    if (rc != SQLITE_OK) {

        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(conn));
        sqlite3_close(conn);
    }

    fprintf(stdout, "Database opened successfully\n");



    error = sqlite3_prepare_v2(conn,
                               "select * from user",1000, &res, &tail);
         if (error != SQLITE_OK) {
        puts("We did not get any data!");
        exit(0);
        }

    while (sqlite3_step(res) == SQLITE_ROW) {
                          printf("%d|", sqlite3_column_int(res, 0));
                          printf("%s|", sqlite3_column_text(res, 1));
                          printf("%s|", sqlite3_column_text(res, 2));
                         printf("%s\n", sqlite3_column_text(res, 3));

                         rec_count++;
                 }

    puts("==========================");
    printf("We received %d records.\n", rec_count);

    sqlite3_finalize(res);
    sqlite3_close(conn);
}

