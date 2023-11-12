//
// Created by louis on 01/11/2023.
//

#include <stdio.h>
#include "../../../headers/saves/load-save/load_player_inventory.h"
#include "../../../headers/init/init_inventory.h"
#include "../../../headers/inventory/potion.h"
#include "../../../headers/weapon/init_weapon.h"
#include "../../../headers/armor/init_armor.h"


void load_player_inventory(Player *player, sqlite3 **conn) {

    sqlite3_stmt *res;
    const char *tail;
    char query[50];

    player->inventory = init_inventory();
    player->current_armor = NULL;
    player->current_weapon = NULL;

    sprintf(query, "SELECT * FROM Inventory WHERE player_id=%d;", player->id);

    int error = sqlite3_prepare_v2(*conn, query, -1, &res, &tail);
    if (error != SQLITE_OK) {
        fprintf(stderr, "Failed to execute SQL query to select inventory: %s\n", sqlite3_errmsg(*conn));
        sqlite3_close(*conn);
        return;
    }

    if(sqlite3_step(res) == SQLITE_ROW) {

        if(sqlite3_column_int(res, 2)) {
            give_player_potion(player, 2);      // potion de vie
        }
        if(sqlite3_column_int(res, 3)) {
            give_player_potion(player, 1);      // potion de mana
        }
    }
    sqlite3_finalize(res);

    load_player_inventory_weapons(player, conn);
    load_player_inventory_armors(player, conn);
}


void load_player_inventory_weapons(Player *player, sqlite3 **conn) {

    sqlite3_stmt *res;
    const char *tail;
    char query[100];

    sprintf(query, "SELECT * FROM Weapon WHERE inventory_id=%d AND isEquipped IS NOT NULL;", player->id);

    int error = sqlite3_prepare_v2(*conn, query, -1, &res, &tail);
    if (error != SQLITE_OK) {
        fprintf(stderr, "Failed to execute SQL query to select weapons: %s\n", sqlite3_errmsg(*conn));
        sqlite3_close(*conn);
        return;
    }

    int i = 0;
    while(sqlite3_step(res) == SQLITE_ROW) {
        char *weapon_name = (char *) sqlite3_column_text(res, 2);
        unsigned short min_strength = sqlite3_column_int(res, 3);
        unsigned short max_strength = sqlite3_column_int(res, 4);
        unsigned short attacks_by_turn = sqlite3_column_int(res, 5);
        unsigned short mana_cost = sqlite3_column_int(res, 6);
        unsigned short rarity = sqlite3_column_int(res, 7);
        unsigned short isEquipped = sqlite3_column_int(res, 8);

        player->inventory->weaponList[i] = init_weapon(weapon_name, attacks_by_turn, min_strength, max_strength, mana_cost, rarity);
        if(isEquipped) {
            equip_weapon(player, player->inventory->weaponList[i]);
        }

        i++;
    }
    sqlite3_finalize(res);
}


void load_player_inventory_armors(Player *player, sqlite3 **conn) {
    sqlite3_stmt *res;
    const char *tail;
    char query[100];

    sprintf(query, "SELECT * FROM Armor WHERE inventory_id=%d  AND isEquipped IS NOT NULL;", player->id);

    int error = sqlite3_prepare_v2(*conn, query, -1, &res, &tail);
    if (error != SQLITE_OK) {
        fprintf(stderr, "Failed to execute SQL query to select weapons: %s\n", sqlite3_errmsg(*conn));
        sqlite3_close(*conn);
        return;
    }

    int i = 0;
    while(sqlite3_step(res) == SQLITE_ROW) {
        char *armor_name = (char *) sqlite3_column_text(res, 2);
        unsigned short defense = sqlite3_column_int(res, 3);
        unsigned short rarity = sqlite3_column_int(res, 4);
        unsigned short isEquipped = sqlite3_column_int(res, 5);

        player->inventory->armorList[i] = init_armor(armor_name, defense, rarity);
        if(isEquipped) {
            player->current_armor = player->inventory->armorList[i];
            player->defense = player->current_armor->defense;
        }

        i++;
    }
    sqlite3_finalize(res);
}