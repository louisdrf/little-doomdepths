//
// Created by louis on 22/10/2023.
//

#include <stdio.h>
#include "../../headers/saves/save_player_spells.h"
#include "../../headers/includes/structs.h"
#include "../../sqlite3/sqlite3.h"


void save_player_spells(Player *player, sqlite3** conn) {

    sqlite3_stmt *res;
    int req = 0;
    const char *tail;

    for(int i = 0; i < NBSPELL_MAX; i++) {                  // sauvegarder les sorts équipés par le joueur
        if(player->book->spell_equipped[i] != NULL) {

            char query[500];
            sprintf(query, "insert into Spell(name, value, mana_cost, spell_type, isEquiped) values (%s, %d, %d, %d, %d);",
                    player->book->spell_equipped[i]->name, player->book->spell_equipped[i]->value,
                    player->book->spell_equipped[i]->mana_cost, player->book->spell_equipped[i]->spell_type, true);

            req = sqlite3_prepare_v2(*conn, query, -1, &res, &tail);
            if (req != SQLITE_OK) {
                fprintf(stderr, "Failed to execute SQL query to insert player equipped spell: %s\n", sqlite3_errmsg(*conn));
                sqlite3_close(*conn);
                return;
            }
        }
    }

}

void save_player_spells_book(Player *player, sqlite3** conn) {
    sqlite3_stmt *res;
    int req = 0;
    const char *tail;

    Spell *current = player->book->spell_stock;

    while (current != NULL) {                  // sauvegarder les sorts dans le Book du joueur

        char query[500];
        sprintf(query, "insert into Spell(name, value, mana_cost, spell_type, isEquiped)  values (%s, %d, %d, %d, %d);",
                current->name, current->value, current->mana_cost, current->spell_type, false);

        req = sqlite3_prepare_v2(*conn, query, -1, &res, &tail);
        if (req != SQLITE_OK) {
            fprintf(stderr, "Failed to execute SQL query to insert player book spell: %s\n", sqlite3_errmsg(*conn));
            sqlite3_close(*conn);
            return;
        }

        req = sqlite3_step(res); // Exécuter la requête préparée
        if (req != SQLITE_DONE) {
            fprintf(stderr, "Failed to execute SQL query: %s\n", sqlite3_errmsg(*conn));
            sqlite3_finalize(res); // Finaliser la requête
            sqlite3_close(*conn);
            return;
        }

        sqlite3_finalize(res); // Finaliser la requête

            current = current->next;

    }
}

/*
 * CREATE TABLE Spell (
   id INTEGER PRIMARY KEY,
   book_id INTEGER,
   player_id INTEGER,
   next_spell_id INTEGER,
   name TEXT,
   value INTEGER,
   mana_cost INTEGER,
   spell_type INTEGER,
   isEquiped BOOLEAN,
   FOREIGN KEY (book_id) REFERENCES Book(id),
   FOREIGN KEY (player_id) REFERENCES Player(id)
);

CREATE TABLE Book (
   id INTEGER PRIMARY KEY,
   player_id INTEGER,
   spell_stock_id INTEGER,
   FOREIGN KEY (spell_stock_id) REFERENCES Spell(id),
   FOREIGN KEY (player_id) REFERENCES Player(id)
);
 */