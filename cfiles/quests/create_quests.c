//
// Created by louis on 04/11/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../headers/quests/create_quests.h"
#include "../../headers/includes/structs.h"

/*
 * struct Quest {

    int                    id;
    char*                  description;
    int                    goldReward;
    Weapon                *weaponReward;
    Armor                 *armorReward;
    bool                   claimedReward;
    struct Quest*          next;
    bool                   finished;

};
 */
Quest *create_quests() {

    Quest* questList = NULL;

    // Création de quêtes
        Quest *quest1 = malloc(sizeof(Quest));
        quest1->id = 1;
        quest1->description = malloc(strlen("Kill 10 monsters") + 1);
        strcpy(quest1->description, "Kill 10 monsters");
        quest1->claimedReward = false;
        quest1->goldReward = 0;
        quest1->armorReward = NULL;
        quest1->weaponReward = NULL;

        quest1->next = questList;
        quest1->finished = false;

        /////////////////////////////////////////////////////////////////////////////////////
        Quest  *quest2 = malloc(sizeof(Quest));
        quest2->id = 2;
        quest2->description = malloc(strlen("Reach second zone") + 1);
        strcpy(quest2->description, "Reach second zone");
        quest2->claimedReward = false;
        quest2->goldReward = 0;
        quest2->armorReward = NULL;
        quest2->weaponReward = NULL;

        quest2->next = quest1;
        quest2->finished = false;
        questList = quest2;

    /////////////////////////////////////////////////////////////////////////////////////

return questList;

}


void free_quest_list(Quest *questList) {
    Quest *current = questList;
    Quest *next;

    while (current != NULL) {
        printf("Desallocating quest : %s\n", current->description);
        next = current->next;
        free(current->description);
        free(current);
        current = next;
    }
}