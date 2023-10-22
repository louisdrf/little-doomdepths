//
// Created by louis on 22/10/2023.
//

#include <stdio.h>
#include "../../headers/saves/save_player_spells.h"
#include "../../headers/includes/structs.h"
#include "../../sqlite3/sqlite3.h"


void save_player_spells(Player *player, sqlite3** conn) {

    sqlite3_stmt *res;
    int error = 0;
    const char *tail;

    for(int i = 0; i < NBSPELL_MAX; i++) {      // sauvegarder les sorts équipés par le joueur
        char query[500];
        sprintf(query, "insert into Spell(id, book_id, player_id, name, value, mana_cost, spell_type)  values (%d, %d, %d, %s, %d, %d, %d);",
                player->book->spell_equipped[i]->id, player->book->id, player->id,
                player->book->spell_equipped[i]->name, player->book->spell_equipped[i]->value,
                player->book->spell_equipped[i]->mana_cost, player->book->spell_equipped[i]->spell_type);

        error = sqlite3_prepare_v2(*conn, query, -1, &res, &tail);
        if (error != SQLITE_OK) {
            fprintf(stderr, "Failed to execute SQL query to insert player: %s\n", sqlite3_errmsg(*conn));
            sqlite3_close(*conn);
            return;
        }
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
   FOREIGN KEY (book_id) REFERENCES Book(id),
   FOREIGN KEY (player_id) REFERENCES Player(id)
);

CREATE TABLE Book (
   id INTEGER PRIMARY KEY,
   player_id INTEGER,
   spell_equipped_1_id INTEGER,
   spell_equipped_2_id INTEGER,
   spell_equipped_3_id INTEGER,
   spell_stock_id INTEGER,
   FOREIGN KEY (spell_equipped_1_id) REFERENCES Spell(id),
   FOREIGN KEY (spell_equipped_2_id) REFERENCES Spell(id),
   FOREIGN KEY (spell_equipped_3_id) REFERENCES Spell(id),
   FOREIGN KEY (spell_stock_id) REFERENCES Spell(id),
   FOREIGN KEY (player_id) REFERENCES Player(id)
);
 */