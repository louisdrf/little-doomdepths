//
// Created by louis on 02/11/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "../../headers/saves/destroy_save.h"
#include "../../sqlite3/sqlite3.h"
#include "../../headers/saves/db_connexion.h"


void destroy_save(int save_id) {

    sqlite3 *conn = connect_to_db();
    char query[100];

    sprintf(query, "UPDATE Game SET hasSave=0 WHERE id=%d;", save_id);
    if(!prepare_and_exec_query(&conn, query)) {
        printf("\nFailed to prepare/execute query to update game save to 0.\n");
        exit(1);
    }

    sprintf(query, "DELETE FROM Monster where player_id=%d;", save_id);
    if(!prepare_and_exec_query(&conn, query)) {
        printf("\nFailed to prepare/execute query to delete all monsters.\n");
        exit(1);
    }

    sprintf(query, "DELETE FROM Armor where inventory_id=%d;", save_id);
    if(!prepare_and_exec_query(&conn, query)) {
        printf("\nFailed to prepare/execute query to delete armors.\n");
        exit(1);
    }

    sprintf(query, "DELETE FROM Weapon where inventory_id=%d;", save_id);
    if(!prepare_and_exec_query(&conn, query)) {
        printf("\nFailed to prepare/execute query to delete weapons.\n");
        exit(1);
    }

    sprintf(query, "DELETE FROM Level where player_id=%d;", save_id);
    if(!prepare_and_exec_query(&conn, query)) {
        printf("\nFailed to prepare/execute query to delete levels.\n");
        exit(1);
    }

    sprintf(query, "DELETE FROM Zone where player_id=%d;", save_id);
    if(!prepare_and_exec_query(&conn, query)) {
        printf("\nFailed to prepare/execute query to delete zones.\n");
        exit(1);
    }

    sprintf(query, "DELETE FROM Quests where player_id=%d;", save_id);
    if(!prepare_and_exec_query(&conn, query)) {
        printf("\nFailed to prepare/execute query to delete quests.\n");
        exit(1);
    }

    sprintf(query, "DELETE FROM Spell where player_id=%d;", save_id);
    if(!prepare_and_exec_query(&conn, query)) {
        printf("\nFailed to prepare/execute query to delete spells.\n");
        exit(1);
    }

    sqlite3_close(conn);
}