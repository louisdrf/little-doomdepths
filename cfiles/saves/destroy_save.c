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

    sprintf(query, "DELETE FROM Monster where player_id=%d;", save_id);
    prepare_and_exec_query(&conn, query);

    sprintf(query, "DELETE FROM Armor where inventory_id=%d;", save_id);
    prepare_and_exec_query(&conn, query);

    sprintf(query, "DELETE FROM Weapon where inventory_id=%d;", save_id);
    prepare_and_exec_query(&conn, query);

    sprintf(query, "DELETE FROM Level where player_id=%d;", save_id);
    prepare_and_exec_query(&conn, query);

    sprintf(query, "DELETE FROM Zone where player_id=%d;", save_id);
    prepare_and_exec_query(&conn, query);

    sprintf(query, "DELETE FROM Quests where player_id=%d;", save_id);
    prepare_and_exec_query(&conn, query);

    sprintf(query, "DELETE FROM Spell where player_id=%d;", save_id);
    prepare_and_exec_query(&conn, query);

    sqlite3_close(conn);
}