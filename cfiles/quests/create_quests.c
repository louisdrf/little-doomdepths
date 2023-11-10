//
// Created by louis on 04/11/2023.
//

#include <stdlib.h>
#include <string.h>
#include "../../headers/quests/create_quests.h"
#include "../../headers/armor/init_armor.h"
#include "../../headers/weapon/init_weapon.h"
#include "../../headers/includes/quests_defines.h"


Quest *create_quests() {

    Quest* questList = NULL;

        Quest *quest1 = init_quest(questList, KILL_10_MONSTERS, "Tuer 10 monstres", true, true, 20, 200);

    /////////////////////////////////////////////////////////////////////////////////////////

        Quest  *quest2 = init_quest(quest1, REACH_SECOND_LEVEL, "Explorer le niveau 2 de la premiere zone", true, false, 0, 100);

    /////////////////////////////////////////////////////////////////////////////////////

        Quest  *quest3 = init_quest(quest2, FINISH_TWO_QUESTS, "Terminer deux quetes", false, true, 50, 100);

    /////////////////////////////////////////////////////////////////////////////////////////

        Quest  *quest4 = init_quest(quest3, FINISH_5_LEVELS, "Terminer 5 niveaux", true, true, 50, 150);

    /////////////////////////////////////////////////////////////////////////////////////////

    questList = quest4;

return questList;
}


Quest *init_quest(Quest *head, int id, char *description, bool armorReward, bool weaponReward, int goldReward, int xp) {

    Quest *q = malloc(sizeof(Quest));

    q->id = id;
    q->xpReward = xp;
    q->finished = false;

    q->description = malloc(strlen(description) + 1);
    strcpy(q->description, description);
    q->displayedAlert = false;
    q->claimedRewards = false;

    q->goldReward = goldReward;
    if(goldReward > 0) q->claimedGold = false;
    else q->claimedGold = true;


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


