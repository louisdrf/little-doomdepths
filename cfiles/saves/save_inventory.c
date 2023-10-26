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
    sprintf(query, "UPDATE Inventory SET healthPotion=%d, manaPotion=%d WHERE player_id=%d;", healthPotion, manaPotion, player->id);
    printf("query : %s", query);

    req = sqlite3_prepare_v2(*conn, query, -1, &res, &tail);
    if (req != SQLITE_OK) {
        fprintf(stderr, "Failed to execute SQL query: %s\n", sqlite3_errmsg(*conn));
        sqlite3_close(*conn);
        return;
    }

    req = sqlite3_step(res); // Exécuter la requête préparée
    if (req != SQLITE_DONE) {
        fprintf(stderr, "Failed to execute SQL query to insert potions in inventory: %s\n", sqlite3_errmsg(*conn));
        sqlite3_finalize(res); // Finaliser la requête
        sqlite3_close(*conn);
        return;
    }

    sqlite3_finalize(res); // Finaliser la requête

    // vider l'inventaire du joueur avant de le remplir avec les nouveaux équipements
    sprintf(query, "DELETE * FROM Inventory WHERE player_id=%d;", player->id);

    int isWeaponEquipped = 0;
    int isArmorEquipped = 0;

    for(int i = 0; i < NBOBJECTS_MAX; i++)      // insérer les armes/armures dans l'inventaire du joueur
    {

        if(player->inventory->weaponList[i] != NULL) {
            if (player->inventory->weaponList[i] == player->current_weapon) isWeaponEquipped = 1;

                sprintf(query,
                        "insert into Weapon(inventory_id, weapon_name, min_strength, max_strength, attacks_by_turn, mana_cost, rarity, isEquipped)  values (%d, %s, %d, %d, %d, %d, %d, %d);",
                        player->id,
                        player->inventory->weaponList[i]->name,
                        player->inventory->weaponList[i]->min_strength,
                        player->inventory->weaponList[i]->max_strength,
                        player->inventory->weaponList[i]->attacks_by_turn,
                        player->inventory->weaponList[i]->mana_cost,
                        player->inventory->weaponList[i]->rarity,
                        isWeaponEquipped);

                req = sqlite3_prepare_v2(*conn, query, -1, &res, &tail);
                if (req != SQLITE_OK) {
                    fprintf(stderr, "Failed to execute SQL query to insert a weapon: %s\n", sqlite3_errmsg(*conn));
                    sqlite3_close(*conn);
                    return;
                }

            req = sqlite3_step(res); // Exécuter la requête préparée
            if (req != SQLITE_DONE) {
                fprintf(stderr, "Failed to execute SQL query to insert potions in inventory: %s\n", sqlite3_errmsg(*conn));
                sqlite3_finalize(res); // Finaliser la requête
                sqlite3_close(*conn);
                return;
            }

            sqlite3_finalize(res); // Finaliser la requête
            isWeaponEquipped = 0;
        }

        if(player->inventory->armorList[i] != NULL) {
                if(player->inventory->armorList[i] == player->current_armor) isArmorEquipped = 1;

                    sprintf(query,
                            "insert into Armor(inventory_id, armor_name, defense, rarity, isEquipped)  values (%d, %s, %d, %d, %d);",
                            player->id,
                            player->inventory->armorList[i]->name,
                            player->inventory->armorList[i]->defense,
                            player->inventory->armorList[i]->rarity,
                            isArmorEquipped);

                req = sqlite3_prepare_v2(*conn, query, -1, &res, &tail);
                if (req != SQLITE_OK) {
                    fprintf(stderr, "Failed to execute SQL query to insert an armor: %s\n", sqlite3_errmsg(*conn));
                    sqlite3_close(*conn);
                    return;
                }

                req = sqlite3_step(res); // Exécuter la requête préparée
                if (req != SQLITE_DONE) {
                    fprintf(stderr, "Failed to execute SQL query to insert potions in inventory: %s\n", sqlite3_errmsg(*conn));
                    sqlite3_finalize(res); // Finaliser la requête
                    sqlite3_close(*conn);
                    return;
                }

                sqlite3_finalize(res); // Finaliser la requête
                isArmorEquipped = 0;
        }
    }

    printf("Insert in inventory done.");
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