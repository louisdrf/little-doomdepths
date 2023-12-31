//
// Created by louis on 22/10/2023.
//

#include <stdio.h>
#include "../../../headers/saves/create-save/create_save.h"
#include "../../../sqlite3/sqlite3.h"
#include "../../../headers/saves/create-save/save_inventory.h"
#include "../../../headers/saves/create-save/save_player.h"
#include "../../../headers/saves/create-save/save_player_spells.h"
#include "../../../headers/saves/db_connexion.h"
#include "../../../headers/saves/create-save/save_zones.h"
#include "../../../headers/includes/colors.h"
#include "../../../headers/saves/create-save/save_player_quests.h"
#include "../../../headers/utils.h"

#define DEBUG false

void create_save(Game *game, Player *player) {

    clear();
    printf(RED"\nSaving...\n"RESET);

    sqlite3 *conn = connect_to_db();

    char query[50];
    sprintf(query, "UPDATE Game SET hasSave=1 WHERE id=%d;", game->id);
    prepare_and_exec_query(&conn, query);

    save_player(player, &conn);

    save_inventory(player, &conn);

    save_player_quests(player, &conn);

    save_player_spells_book(player, &conn);

    save_zones(game, &conn);


    sqlite3_close(conn);
    printf(GREEN"\nGame correctly save.\n"RESET);
}





