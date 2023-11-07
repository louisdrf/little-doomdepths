//
// Created by louis on 01/11/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../headers/saves/load-save/load_player_spells.h"
#include "../../../sqlite3/sqlite3.h"
#include "../../../headers/init/init_spell.h"

#define DEBUG false

void load_player_spells(Player *player, sqlite3 **conn) {


    sqlite3_stmt *res;
    const char *tail;
    char query[50];

    sprintf(query, "SELECT * FROM Spell WHERE player_id=%d;", player->id);

    int error = sqlite3_prepare_v2(*conn, query, -1, &res, &tail);
    if (error != SQLITE_OK) {
        fprintf(stderr, "Failed to execute SQL query to select spells: %s\n", sqlite3_errmsg(*conn));
        sqlite3_close(*conn);
        return;
    }

    int i = 0;
    player->book = init_book();
    player->book->spell_stock = NULL;

    while(sqlite3_step(res) == SQLITE_ROW) {
       Spell *spell = malloc(sizeof(Spell));

       spell->name = malloc(strlen(sqlite3_column_text(res, 2)) + 1);
       strcpy(spell->name, sqlite3_column_text(res, 2));

       spell->value = sqlite3_column_int(res, 3);
       spell->mana_cost = sqlite3_column_int(res, 4);
       spell->spell_type = sqlite3_column_int(res, 5);
       int isEquipped = sqlite3_column_int(res, 6);
       spell->id = sqlite3_column_int(res, 7);

       if(isEquipped) {
           player->book->spell_equipped[i] = spell;
           i++;
       }

        spell->next = player->book->spell_stock;
        player->book->spell_stock = spell;

    }
#if DEBUG
    printf("\nSpells loaded well.\n");
#endif

    sqlite3_finalize(res);
}