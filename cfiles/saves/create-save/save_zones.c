//
// Created by louis on 26/10/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "../../../headers/saves/create-save/save_zones.h"
#include "../../../headers/saves/db_connexion.h"

#define DEBUG false

void save_zones(Game *game, sqlite3** conn) {

    char query[500];
    int level_id = 0;

    // supprimer les zones avant de tout recréer
    sprintf(query, "DELETE FROM Zone WHERE player_id=%d;", game->id);
    if(!prepare_and_exec_query(conn, query)) {
        printf("\nFailed to prepare/execute query to delete all zones.\n");
        exit(1);
    }

    // supprimer les niveaux avant de tout recréer
    sprintf(query, "DELETE FROM Level WHERE player_id=%d;", game->id);
    if(!prepare_and_exec_query(conn, query)) {
        printf("\nFailed to prepare/execute query to delete all levels.\n");
        exit(1);
    }

    // supprimer les monstres avant de tout recréer
    sprintf(query, "DELETE FROM Monster WHERE player_id=%d;", game->id);
    if(!prepare_and_exec_query(conn, query)) {
        printf("\nFailed to prepare/execute query to delete all monsters.\n");
        exit(1);
    }

    for(int i = 0; i < NBZONES; i++) {
#if DEBUG
        printf("\ninsert zone %d", game->zoneList[i]->id);
#endif
            /////////// INSERT ZONE  //////////////
            sprintf(query, "INSERT INTO Zone(player_id, name, multiplicator, finished, difficulty, height, width, zone_id) values(%d, '%s', %lf, %d, %d, %d, %d, %d);",
                    game->id,
                    game->zoneList[i]->name,
                    game->zoneList[i]->multiplicator,
                    game->zoneList[i]->finished,
                    game->zoneList[i]->difficulty,
                    game->zoneList[i]->height,
                    game->zoneList[i]->width,
                    i
            );

            if(!prepare_and_exec_query(conn, query)) {
                printf("\nFailed to prepare/execute query to insert zone %d.\n", i);
                exit(1);
            }
            /////////////////////////////////////////////////////

            /////////// INSERT ZONE LEVELS //////////////
        for(int j = 0; j < game->zoneList[i]->height; j++) {
            for (int k = 0; k < game->zoneList[i]->width; k++) {

                if(game->zoneList[i]->levelList[j][k] != NULL) {
#if DEBUG
                    printf("\ninsert level %d-%d", j, k);
#endif


                    sprintf(query, "INSERT INTO Level(player_id, zone_id, nbMonsters, finished, height_index, width_index, level_type) values(%d, %d, %d, %d, %d, %d, %d);",
                            game->id,
                            game->zoneList[i]->id,
                            game->zoneList[i]->levelList[j][k]->nbMonsters,
                            game->zoneList[i]->levelList[j][k]->finished,
                            j, k,
                            game->zoneList[i]->map[i][j]
                    );
                    if(!prepare_and_exec_query(conn, query)) {
                        printf("\nFailed to prepare/execute query to insert all levels in zone %d.\n", game->zoneList[i]->id);
                        exit(1);
                    }

#if DEBUG
                    printf("\nInsert level done.");
#endif
                    /////////// INSERT LEVEL MONSTERS //////////////
#if DEBUG
                    printf("\nNb monsters level %d : %d", game->zoneList[i]->levelList[j][k]->id, game->zoneList[i]->levelList[j][k]->nbMonsters);
#endif

                    Monster *current = game->zoneList[i]->levelList[j][k]->monsters;
                    while(current != NULL)
                    {
#if DEBUG
                        printf("\ninsert monster %d", current->id);
#endif
                        sprintf(query, "INSERT INTO Monster(level_height_index, level_width_index, monster_type, lifepoints, lifepoints_max, min_strength, max_strength, defense, attacks_by_turn, attacks_left, turn, isAlive, loot_gold, player_id, zone_id, monster_id, xp) "
                                       "values(%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d);",
                                j , k,
                                current->monster_type,
                                current->lifepoints,
                                current->lifepoints_max,
                                current->min_strength,
                                current->max_strength,
                                current->defense,
                                current->attacks_by_turn,
                                current->attacks_left,
                                current->turn,
                                current->isAlive,
                                current->loot_gold,
                                game->id,
                                game->zoneList[i]->id,
                                current->id,
                                current->xp
                        );

                        if(!prepare_and_exec_query(conn, query)) {
                            printf("\nFailed to prepare/execute query to add monsters in level %d.\n", level_id);
                            exit(1);
                        }

                        current = current->next;
                    }

#if DEBUG
                    printf("\nInsert monsters done.");
#endif
                    level_id++;
                    ////////////////////////////////////////////////////////
                }
                else level_id++;


            }
        }
    }

#if DEBUG
    printf("Insert all Zones done.");
#endif
}