//
// Created by louis on 24/10/2023.
//

#include <stdio.h>
#include "../../headers/saves/save_levels.h"
#include "../../sqlite3/sqlite3.h"
#include "../../headers/includes/structs.h"
#include "../../headers/db_connexion.h"


void save_levels(Zone *zone, sqlite3** conn) {

    sqlite3_stmt *res;
    int req = 0;
    const char *tail;

    char query[50];
    sprintf(query, "INSERT INTO Game DEFAULT VALUES;");
    printf("query : %s", query);

    if(!prepare_and_exec_query(conn, query)) {
        printf("\nFailed to prepare/execute query to update player data.\n");
        exit(1);
    }

    sqlite3_finalize(res); // Finaliser la requête
}