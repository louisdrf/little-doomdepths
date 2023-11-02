//
// Created by louis on 02/11/2023.
//

#include <stdio.h>
#include "../../headers/saves/destroy_save.h"
#include "../../sqlite3/sqlite3.h"
#include "../../headers/db_connexion.h"


void destroy_save(int save_id) {

    sqlite3 *conn = connect_to_db();
    char query[50];
    sprintf(query, "UPDATE Game SET hasSave=0 WHERE id=%d;", save_id);
    prepare_and_exec_query(&conn, query);
    sqlite3_close(conn);
}