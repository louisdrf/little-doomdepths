//
// Created by louis on 22/10/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "../../../headers/saves/create-save/save_player_spells.h"
#include "../../../sqlite3/sqlite3.h"
#include "../../../headers/db_connexion.h"

#define DEBUG false

void save_player_spells_book(Player *player, sqlite3** conn) {

    char query[500];
    int isEquipped = 0;

    sprintf(query, "delete from Spell where player_id=%d;", player->id);
    if(!prepare_and_exec_query(conn, query)) {
        printf("\nFailed to prepare/execute query to delete player spells.\n");
        exit(1);
    }

    Spell *current = player->book->spell_stock;

    while (current != NULL) {                  // sauvegarder les sorts dans le Book du joueur

        if(current == player->book->spell_equipped[0]
        || current == player->book->spell_equipped[1]
        || current == player->book->spell_equipped[2]) {
            isEquipped = 1;
        }

        sprintf(query, "insert into Spell(player_id, name, value, mana_cost, spell_type, isEquipped, spell_id)  values (%d, '%s', %d, %d, %d, %d, %d);",
                player->id,
                current->name,
                current->value,
                current->mana_cost,
                current->spell_type,
                isEquipped,
                current->id);

        if(!prepare_and_exec_query(conn, query)) {
            printf("\nFailed to prepare/execute query to update player data.\n");
            exit(1);
        }

        isEquipped = 0;
        current = current->next;
    }

#if DEBUG
    printf("\nInsert Spells done.");
#endif
}
