//
// Created by louis on 22/10/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "../../../headers/saves/create-save/save_inventory.h"
#include "../../../sqlite3/sqlite3.h"
#include "../../../headers/db_connexion.h"

#define DEBUG true

void save_inventory(Player *player, sqlite3** conn) {

    char query[500];

    bool healthPotion = (player->inventory->healthPotion == NULL) ? false : true;       // est ce que le joueur a une potion en inventaire
    bool manaPotion = (player->inventory->manaPotion == NULL) ? false : true;

    /* ******** UPDATE INVENTORY POTIONS ********** */

            sprintf(query, "UPDATE Inventory SET healthPotion=%d, manaPotion=%d WHERE player_id=%d;", healthPotion, manaPotion, player->id);
            printf("\nquery : %s", query);
            if(!prepare_and_exec_query(conn, query)) {
                printf("\nFailed to prepare/execute query to update inventory potions.\n");
                exit(1);
            }

            ///////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////

    // vider l'inventaire du joueur avant de le remplir avec les nouveaux équipements
    sprintf(query, "DELETE FROM Weapon WHERE inventory_id=%d;", player->id);
    if(!prepare_and_exec_query(conn, query)) {
        printf("\nFailed to prepare/execute query to delete all weapons in player inventory.\n");
        exit(1);
    }
    sprintf(query, "DELETE FROM Armor WHERE inventory_id=%d;", player->id);
    if(!prepare_and_exec_query(conn, query)) {
        printf("\nFailed to prepare/execute query to delete all armors in player inventory.\n");
        exit(1);
    }

    int isWeaponEquipped = 0;
    int isArmorEquipped = 0;


    /////////////////////////////////////////////////////////////////
    /////////// INSERT ARMORS AND WEAPONS IN INVENTORY //////////////
    /////////////////////////////////////////////////////////////////

    for(int i = 0; i < NBOBJECTS_MAX; i++)      // insérer les armes/armures dans l'inventaire du joueur
    {

                if(player->inventory->weaponList[i] != NULL) {
                    if (player->inventory->weaponList[i] == player->current_weapon) isWeaponEquipped = 1;

                    /////////// INSERT WEAPONS IN INVENTORY //////////////

                        sprintf(query,
                                "insert into Weapon(inventory_id, weapon_name, min_strength, max_strength, attacks_by_turn, mana_cost, rarity, isEquipped)  values (%d, '%s', %d, %d, %d, %d, %d, %d);",
                                player->id,
                                player->inventory->weaponList[i]->name,
                                player->inventory->weaponList[i]->min_strength,
                                player->inventory->weaponList[i]->max_strength,
                                player->inventory->weaponList[i]->attacks_by_turn,
                                player->inventory->weaponList[i]->mana_cost,
                                player->inventory->weaponList[i]->rarity,
                                isWeaponEquipped);

                    if(!prepare_and_exec_query(conn, query)) {
                        printf("\nFailed to prepare/execute query to insert weapon in player inventory.\n");
                        exit(1);
                    }
                    isWeaponEquipped = 0;
                }

                /////////////////////////////////////////////////////////////////

                if(player->inventory->armorList[i] != NULL) {
                        if(player->inventory->armorList[i] == player->current_armor) isArmorEquipped = 1;

                    /////////// INSERT ARMORS IN INVENTORY //////////////

                            sprintf(query,
                                    "insert into Armor(inventory_id, armor_name, defense, rarity, isEquipped)  values (%d, '%s', %d, %d, %d);",
                                    player->id,
                                    player->inventory->armorList[i]->name,
                                    player->inventory->armorList[i]->defense,
                                    player->inventory->armorList[i]->rarity,
                                    isArmorEquipped);

                    if(!prepare_and_exec_query(conn, query)) {
                        printf("\nFailed to prepare/execute query to insert armor in player inventory.\n");
                        exit(1);
                    }
                        isArmorEquipped = 0;
                }
                /////////////////////////////////////////////////////////////////

    }
#if DEBUG
    printf("\nInsert in inventory done.");
#endif
}
