//
// Created by louis on 26/10/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "../../../headers/saves/create-save/save_zones.h"
#include "../../../headers/db_connexion.h"

#define DEBUG true

void save_zones(Game *game, sqlite3** conn) {

    char query[500];
    int level_id = 0;

    // supprimer les zones avant de tout recréer
    sprintf(query, "DELETE FROM Zone WHERE player_id=%d;", game->id);
    if(!prepare_and_exec_query(conn, query)) {
        printf("\nFailed to prepare/execute query to delete all zones.\n");
        exit(1);
    }

    for(int i = 0; i < NBZONES; i++) {

        printf("\ninsert zone %d", game->zoneList[i]->id);

            /////////// INSERT ZONE  //////////////
            sprintf(query, "INSERT INTO Zone(player_id, name, multiplicator, finished, difficulty, height, width) values(%d, '%s', %lf, %d, %d, %d, %d);",
                    game->id,
                    game->zoneList[i]->name,
                    game->zoneList[i]->multiplicator,
                    game->zoneList[i]->finished,
                    game->zoneList[i]->difficulty,
                    game->zoneList[i]->height,
                    game->zoneList[i]->width
            );

            if(!prepare_and_exec_query(conn, query)) {
                printf("\nFailed to prepare/execute query to insert zone %d.\n", game->zoneList[i]->id);
                exit(1);
            }
            /////////////////////////////////////////////////////


        // supprimer les niveaux de la zone avant de tout recréer
        sprintf(query, "DELETE FROM Level WHERE zone_id=%d AND player_id=%d;", game->zoneList[i]->id, game->id);
        if(!prepare_and_exec_query(conn, query)) {
            printf("\nFailed to prepare/execute query to delete all levels in zone %d.\n", game->zoneList[i]->id);
            exit(1);
        }

            /////////// INSERT ZONE LEVELS //////////////
        for(int j = 0; j < game->zoneList[i]->height; j++) {
            for (int k = 0; k < game->zoneList[i]->width; k++) {

                if(game->zoneList[i]->levelList[j][k] != NULL) {

                    printf("\ninsert level %d-%d", j, k);

                    sprintf(query, "INSERT INTO Level(player_id, zone_id, nbMonsters, finished, height_index, width_index) values(%d, %d, %d, %d, %d, %d);",
                            game->id,
                            game->zoneList[i]->id,
                            game->zoneList[i]->levelList[j][k]->nbMonsters,
                            game->zoneList[i]->levelList[j][k]->finished,
                            j, k
                    );
                    if(!prepare_and_exec_query(conn, query)) {
                        printf("\nFailed to prepare/execute query to insert all levels in zone %d.\n", game->zoneList[i]->id);
                        exit(1);
                    }

#if DEBUG
                    printf("\nInsert level done.");
#endif

                    // supprimer les monstres du niveau avant de tout recréer
                    sprintf(query, "DELETE FROM Monster WHERE level_id=%d AND player_id=%d AND zone_id=%d;", level_id, game->id, game->zoneList[i]->id);
                    if(!prepare_and_exec_query(conn, query)) {
                        printf("\nFailed to prepare/execute query to delete all monsters in level %d.\n", level_id);
                        exit(1);
                    }

                    /////////// INSERT LEVEL MONSTERS //////////////
                    printf("\nNb monsters level %d : %d", game->zoneList[i]->levelList[j][k]->id, game->zoneList[i]->levelList[j][k]->nbMonsters);

                    Monster *current = game->zoneList[i]->levelList[j][k]->monsters;
                    while(current != NULL)
                    {
                        printf("\ninsert monster %d", current->id);
                        sprintf(query, "INSERT INTO Monster(level_id, monster_type, lifepoints, lifepoints_max, min_strength, max_strength, defense, attacks_by_turn, attacks_left, turn, isAlive, loot_gold, player_id, zone_id, monster_id) "
                                       "values(%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d);",
                                game->zoneList[i]->levelList[j][k]->in_zone_id,
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
                                current->id
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