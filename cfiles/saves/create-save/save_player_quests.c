//
// Created by louis on 07/11/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include "../../../headers/saves/create-save/save_player_quests.h"
#include "../../../sqlite3/sqlite3.h"
#include "../../../headers/saves/db_connexion.h"


void save_player_quests(Player *player, sqlite3** conn) {

    char query[300];

    sprintf(query, "delete from Quests where player_id=%d;", player->id);
    if(!prepare_and_exec_query(conn, query)) {
        printf("\nFailed to prepare/execute query to delete player quests.\n");
        exit(1);
    }

    Quest *current = player->questList;

    while (current != NULL) {

        sprintf(query, "insert into Quests(player_id, quest_id, description, gold_reward, claimedRewards, finished, displayedAlert, claimedGold, claimedWeapon, claimedArmor, xp)  values (%d, %d, '%s', %d, %d, %d, %d, %d, %d, %d, %d);",
                player->id,
                current->id,
                current->description,
                current->goldReward,
                current->claimedRewards,
                current->finished,
                current->displayedAlert,
                current->claimedGold,
                current->claimedWeapon,
                current->claimedArmor,
                current->xpReward
                );

        if(!prepare_and_exec_query(conn, query)) {
            printf("\nFailed to prepare/execute query to insert quests.\n");
            exit(1);
        }

        if(current->weaponReward != NULL) {
            save_quest_weapon(player->id, current, conn);
        }
        if(current->armorReward != NULL) {
            save_quest_armor(player->id, current, conn);
        }


        current = current->next;
    }

#if DEBUG
    printf("\nInsert Quests done.");
#endif
}


void save_quest_weapon(int player_id, Quest *quest, sqlite3** conn) {

    char query[200];

    sprintf(query, "delete from Weapon where inventory_id=%d and quest_id=%d;", player_id, quest->id);
    if(!prepare_and_exec_query(conn, query)) {
        printf("\nFailed to prepare/execute query to delete quest %d weapon.\n", quest->id);
        exit(1);
    }

    sprintf(query,
            "insert into Weapon(inventory_id, weapon_name, min_strength, max_strength, attacks_by_turn, mana_cost, rarity, quest_id)  values (%d, '%s', %d, %d, %d, %d, %d, %d);",
            player_id,
            quest->weaponReward->name,
            quest->weaponReward->min_strength,
            quest->weaponReward->max_strength,
            quest->weaponReward->attacks_by_turn,
            quest->weaponReward->mana_cost,
            quest->weaponReward->rarity,
            quest->id
            );

        if(!prepare_and_exec_query(conn, query)) {
            printf("\nFailed to prepare/execute query to insert quest %d weapon.\n", quest->id);
            exit(1);
        }
}



void save_quest_armor(int player_id, Quest *quest, sqlite3** conn) {

    char query[200];

    sprintf(query, "delete from Armor where inventory_id=%d and quest_id=%d;", player_id, quest->id);
    if(!prepare_and_exec_query(conn, query)) {
        printf("\nFailed to prepare/execute query to delete quest %d armor.\n", quest->id);
        exit(1);
    }

    sprintf(query,
            "insert into Armor(inventory_id, armor_name, defense, rarity, quest_id)  values (%d, '%s', %d, %d, %d);",
            player_id,
            quest->armorReward->name,
            quest->armorReward->defense,
            quest->armorReward->rarity,
            quest->id);

    if(!prepare_and_exec_query(conn, query)) {
        printf("\nFailed to prepare/execute query to insert quest %d armor.\n", quest->id);
        exit(1);
    }
}