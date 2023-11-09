//
// Created by louis on 07/11/2023.
//

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "../../../headers/saves/load-save/load_player_quests.h"

#define DEBUG false

void load_player_quests(Player *player, sqlite3 **conn) {

    sqlite3_stmt *res;
    const char *tail;
    char query[50];

    sprintf(query, "SELECT * FROM Quests WHERE player_id=%d ORDER BY quest_id;", player->id);

    int error = sqlite3_prepare_v2(*conn, query, -1, &res, &tail);
    if (error != SQLITE_OK) {
        fprintf(stderr, "Failed to execute SQL query to select quests: %s\n", sqlite3_errmsg(*conn));
        sqlite3_close(*conn);
        return;
    }

    int i = 1;
    player->questList = NULL;

    while(sqlite3_step(res) == SQLITE_ROW) {
        Quest *quest = malloc(sizeof(Quest));

        quest->description = malloc(strlen(sqlite3_column_text(res, 3)) + 1);
        strcpy(quest->description, sqlite3_column_text(res, 3));

        quest->id = i;
        quest->goldReward = sqlite3_column_int(res, 4);
        quest->claimedRewards = sqlite3_column_int(res, 5);
        quest->finished = sqlite3_column_int(res, 6);
        quest->displayedAlert = sqlite3_column_int(res, 7);
        quest->claimedGold = sqlite3_column_int(res, 8);
        quest->claimedWeapon = sqlite3_column_int(res, 9);
        quest->claimedArmor = sqlite3_column_int(res, 10);
        quest->xpReward = sqlite3_column_int(res, 11);

        load_quest_weapon(quest, player->id, conn);
        load_quest_armor(quest, player->id, conn);

        i++;
        quest->next = player->questList;
        player->questList = quest;

    }
#if DEBUG
    printf("\nQuests loaded well.\n");
#endif

    sqlite3_finalize(res);
}


void load_quest_weapon(Quest *quest, int player_id, sqlite3 **conn) {

    sqlite3_stmt *res;
    const char *tail;
    char query[100];

    sprintf(query, "SELECT * FROM Weapon WHERE inventory_id=%d AND quest_id=%d;", player_id, quest->id);

    int error = sqlite3_prepare_v2(*conn, query, -1, &res, &tail);
    if (error != SQLITE_OK) {
        fprintf(stderr, "Failed to execute SQL query to select quest %d weapon: %s\n", quest->id, sqlite3_errmsg(*conn));
        sqlite3_close(*conn);
        return;
    }

    if(sqlite3_step(res) == SQLITE_ROW) {
        Weapon *w = malloc(sizeof(Weapon));

        w->name = malloc(strlen(sqlite3_column_text(res, 2)) + 1);
        strcpy(w->name, sqlite3_column_text(res, 2));

        w->min_strength = sqlite3_column_int(res, 3);
        w->max_strength = sqlite3_column_int(res, 4);
        w->attacks_by_turn = sqlite3_column_int(res, 5);
        w->mana_cost = sqlite3_column_int(res, 6);
        w->rarity = sqlite3_column_int(res, 7);

        quest->weaponReward = w;
    }
    else {
        quest->weaponReward = NULL;
    }
#if DEBUG
    printf("\nQuest %d weapon loaded well.\n", quest->id);
#endif

    sqlite3_finalize(res);
}



void load_quest_armor(Quest *quest, int player_id, sqlite3 **conn) {

    sqlite3_stmt *res;
    const char *tail;
    char query[100];

    sprintf(query, "SELECT * FROM Armor WHERE inventory_id=%d AND quest_id=%d;", player_id, quest->id);

    int error = sqlite3_prepare_v2(*conn, query, -1, &res, &tail);
    if (error != SQLITE_OK) {
        fprintf(stderr, "Failed to execute SQL query to select quest %d armor: %s\n", quest->id, sqlite3_errmsg(*conn));
        sqlite3_close(*conn);
        return;
    }

    if(sqlite3_step(res) == SQLITE_ROW) {
        Armor *a = malloc(sizeof(Armor));

        a->name = malloc(strlen(sqlite3_column_text(res, 2)) + 1);
        strcpy(a->name, sqlite3_column_text(res, 2));

        a->defense = sqlite3_column_int(res, 3);
        a->rarity = sqlite3_column_int(res, 4);

        quest->armorReward = a;
    }
    else {
        quest->armorReward = NULL;
    }
#if DEBUG
    printf("\nQuest %d armor loaded well.\n", quest->id);
#endif

    sqlite3_finalize(res);
}