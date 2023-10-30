//
// Created by louis on 22/10/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "../../../headers/saves/create-save/create_save.h"
#include "../../../headers/includes/structs.h"
#include "../../../sqlite3/sqlite3.h"
#include "../../../headers/saves/create-save/save_inventory.h"
#include "../../../headers/saves/create-save/save_player.h"
#include "../../../headers/saves/create-save/save_player_spells.h"
#include "../../../headers/db_connexion.h"
#include "../../../headers/saves/create-save/save_zones.h"

void create_save(Game *game, Player *player) {

    sqlite3 *conn = connect_to_db();

    save_player(player, &conn);
    save_inventory(player, &conn);
    save_player_spells_book(player, &conn);
    save_zones(game, &conn);           // sauvegarde zones + leurs niveaux

    sqlite3_close(conn);
}

