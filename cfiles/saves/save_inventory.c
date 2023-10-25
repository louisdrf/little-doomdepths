//
// Created by louis on 22/10/2023.
//

#include <stdio.h>
#include "../../headers/saves/save_inventory.h"
#include "../../headers/includes/structs.h"
#include "../../sqlite3/sqlite3.h"

void save_inventory(Player *player, sqlite3** conn) {

    sqlite3_stmt *res;
    int req = 0;
    const char *tail;

    bool healthPotion = (player->inventory->healthPotion == NULL) ? false : true;       // est ce que le joueur a une potion en inventaire
    bool manaPotion = (player->inventory->manaPotion == NULL) ? false : true;

    char query[500];
    sprintf(query, "insert into Inventory(healthPotion, manaPotion)  values (%d, %d);", healthPotion, manaPotion);
    printf("query : %s", query);

    req = sqlite3_prepare_v2(*conn, query, -1, &res, &tail);
    if (req != SQLITE_OK) {
        fprintf(stderr, "Failed to execute SQL query: %s\n", sqlite3_errmsg(*conn));
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

    for(int i = 0; i < NBOBJECTS_MAX; i++) {
        if(player->inventory->weaponList[i] != NULL) {
            sprintf(query, "insert into Weapon(id, weapon_name, min_strength, max_strength, attacks_by_turn, mana_cost, rarity)  values (%d, %s, %d, %d, %d, %d, %d);",
                    player->inventory->weaponList[i]->id,
                    player->inventory->weaponList[i]->name,
                    player->inventory->weaponList[i]->min_strength,
                    player->inventory->weaponList[i]->max_strength,
                    player->inventory->weaponList[i]->attacks_by_turn,
                    player->inventory->weaponList[i]->mana_cost,
                    player->inventory->weaponList[i]->rarity);

            req = sqlite3_prepare_v2(*conn, query, -1, &res, &tail);
            if (req != SQLITE_OK) {
                fprintf(stderr, "Failed to execute SQL query to insert a weapon: %s\n", sqlite3_errmsg(*conn));
                sqlite3_close(*conn);
                return;
            }
        }
        if(player->inventory->armorList[i] != NULL) {
            sprintf(query, "insert into Armor(id, armor_name, defense, rarity)  values (%d, %s, %d, %d);",
                    player->inventory->armorList[i]->id,
                    player->inventory->armorList[i]->name,
                    player->inventory->armorList[i]->defense,
                    player->inventory->armorList[i]->rarity);

            req = sqlite3_prepare_v2(*conn, query, -1, &res, &tail);
            if (req != SQLITE_OK) {
                fprintf(stderr, "Failed to execute SQL query to insert an armor: %s\n", sqlite3_errmsg(*conn));
                sqlite3_close(*conn);
                return;
            }
        }
    }

    printf("Insert inventory done.");
}

/*
 * CREATE TABLE Inventory (
   id INTEGER PRIMARY KEY,
   player_id INTEGER,
   healthPotion BOOLEAN,
   manaPotion BOOLEAN,
   FOREIGN KEY (player_id) REFERENCES Player(id)
);

 CREATE TABLE Armor (
 id INTEGER PRIMARY KEY,
   inventory_id INTEGER,
   player_id INTEGER,
   armor_name VARCHAR(70),
   defense INTEGER NOT NULL,
   rarity INTEGER NOT NULL,
   FOREIGN KEY (inventory_id) REFERENCES Inventory(id),
   FOREIGN KEY (player_id) REFERENCES Player(id)
);


CREATE TABLE Weapon (
   id INTEGER PRIMARY KEY,
   inventory_id INTEGER,
   player_id INTEGER,
   weapon_name VARCHAR(70),
   min_strength INTEGER NOT NULL,
   max_strength INTEGER NOT NULL,
   attacks_by_turn INTEGER NOT NULL,
   mana_cost INTEGER,
   rarity INTEGER NOT NULL,
   FOREIGN KEY (inventory_id) REFERENCES Inventory(id),
   FOREIGN KEY (player_id) REFERENCES Player(id)
);
 */