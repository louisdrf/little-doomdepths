//
// Created by louis on 04/11/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../headers/quests/create_quests.h"
#include "../../headers/includes/structs.h"
#include "../../headers/armor/init_armor.h"
#include "../../headers/weapon/init_weapon.h"
#include "../../headers/includes/quests_defines.h"


Quest *create_quests() {

    Quest* questList = NULL;

    // Création de quêtes
        Quest *quest1 = malloc(sizeof(Quest));
        init_quest(questList, int id, char *description, bool armorReward, bool weaponReward, int goldReward);

        quest1->id = KILL_10_MONSTERS;
        quest1->description = malloc(strlen("Tuer 10 monstres") + 1);
        strcpy(quest1->description, "Tuer 10 monstres");
        quest1->displayedAlert = false;
        quest1->claimedRewards = false;
        quest1->claimedGold = false;
        quest1->claimedArmor = false;
        quest1->claimedWeapon = false;
        quest1->goldReward = 20;
        quest1->armorReward = randomArmor();
        quest1->weaponReward = randomWeapon();

        quest1->next = questList;
        quest1->finished = false;

    /////////////////////////////////////////////////////////////////////////////////////////

        Quest  *quest2 = malloc(sizeof(Quest));
        quest2->id = REACH_SECOND_LEVEL;
        quest2->description = malloc(strlen("Explorer le niveau 2 de la premiere zone") + 1);
        strcpy(quest2->description, "Explorer le niveau 2 de la premiere zone");
        quest2->displayedAlert = false;
        quest2->claimedRewards = false;
        quest2->claimedGold = true;
        quest2->claimedArmor = false;
        quest2->claimedWeapon = true;

        quest2->goldReward = 0;
        quest2->armorReward = randomArmor();
        quest2->weaponReward = NULL;

        quest2->next = quest1;
        quest2->finished = false;

    /////////////////////////////////////////////////////////////////////////////////////

        Quest  *quest3 = malloc(sizeof(Quest));
        quest3->id = FINISH_TWO_QUESTS;
        quest3->description = malloc(strlen("Terminer une quete") + 1);
        strcpy(quest3->description, "Terminer une quete");
        quest3->displayedAlert = false;
        quest3->claimedRewards = false;
        quest3->claimedGold = false;
        quest3->claimedArmor = true;
        quest3->claimedWeapon = false;

        quest3->goldReward = 50;
        quest3->armorReward = NULL;
        quest3->weaponReward = randomWeapon();

        quest3->next = quest2;
        quest3->finished = false;

    /////////////////////////////////////////////////////////////////////////////////////////
        Quest  *quest4 = malloc(sizeof(Quest));
        quest4->id = FINISH_TWO_QUESTS;
        quest4->description = malloc(strlen("Terminer 5 niveaux") + 1);
        strcpy(quest4->description, "Terminer 5 niveaux");
        quest4->displayedAlert = false;
        quest4->claimedRewards = false;
        quest4->claimedGold = false;
        quest4->claimedArmor = false;
        quest4->claimedWeapon = false;

        quest4->goldReward = 50;
        quest4->armorReward = randomArmor();
        quest4->weaponReward = randomWeapon();

        quest4->next = quest3;
        quest4->finished = false;

    /////////////////////////////////////////////////////////////////////////////////////////

    questList = quest4;

return questList;

}


Quest *init_quest(Quest *head, int id, char *description, bool armorReward, bool weaponReward, int goldReward) {

    Quest *q = malloc(sizeof(Quest));

    q->id = id;
    q->finished = false;

    q->description = malloc(strlen(description) + 1);
    strcpy(q->description, description);
    q->displayedAlert = false;
    q->claimedRewards = false;

    q->goldReward = goldReward;
    if(goldReward > 0) q->claimedGold = true;
    else q->claimedGold = false;

    if(armorReward) {
        q->claimedArmor = false;
        q->armorReward = randomArmor();
    }
    else {
        q->claimedArmor = true;
        q->armorReward = NULL;
    }

    if(weaponReward) {
        q->claimedWeapon = false;
        q->weaponReward = randomWeapon();
    }
    else {
        q->claimedWeapon = true;
        q->weaponReward = NULL;
    }

    q->next = head;

    return q;

}


void free_quest_list(Quest *questList) {
    Quest *current = questList;
    Quest *next;

    while (current != NULL) {
        //printf("Desallocating quest : %s\n", current->description);
        next = current->next;
        free(current->description);
        free(current);
        current = next;
    }
}