//
// Created by louis on 04/11/2023.
//

#include <stdio.h>
#include <conio.h>
#include "../../headers/quests/display_quests.h"
#include "../../headers/includes/colors.h"
#include "../../headers/weapon/init_weapon.h"
#include "../../headers/armor/init_armor.h"
#include "../../headers/inventory/inventory.h"
#include "../../headers/player/player.h"
#include "../../headers/utils.h"


void display_quests_menu(Player *player) {

    clear();
    int playerEntry;

    printf(GREEN"----- Quetes -----\n\n"RESET);
    printf(BLUE "Liste des quetes  (1)\n"RESET);
    printf(GREEN"Quetes terminees  (2)\n\n\n"RESET);
    printf(     "Retour            (n'importe quelle touche)\n");
    printf("-> ");

    playerEntry = getch() - 48;
    switch(playerEntry) {
        case 1:
            display_quests(player);
            break;

        case 2:
            display_done_quests(player);
            break;

        default:
            return;
    }
}

void display_quests(Player *player) {
    clear();
    int nbQuests = 0;

    Quest *current = player->questList;
    while(current != NULL) {

            printf("%s | ", current->description);
            if(current->finished == true) printf(GREEN"terminee\n"RESET);
            else  printf(RED"non terminee\n"RESET);

        nbQuests++;
        current = current->next;
    }

    if(nbQuests == 0) {
        printf("Aucune quete en cours.\n");
    }

    printf("\nRetour (pressez n'importe quelle touche)\n->");
    int pass = getch();
    display_quests_menu(player);
}

void display_done_quests(Player *player) {

    clear();
    int playerEntry;
    int nbQuests = 0;

    Quest *current = player->questList;

    while(current != NULL) {

        if(current->finished == true) {
            printf("%d : %s | Recompenses recuperees : ",current->id, current->description);
            if(!current->claimedRewards) printf(RED"non\n"RESET);
            else printf(GREEN"oui\n"RESET);
            nbQuests++;
        }
        current = current->next;
    }

    if(nbQuests == 0) {
        printf(RED"Aucune quete terminee pour l'instant.\n"RESET);
        printf("\nRetour (pressez n'importe quelle touche)\n->");
        int pause = getch();
        return;
    }
    else {
        printf(BLUE"\nRecuperer les recompenses (1)"RESET);
        printf(RED"        Retour (2)\n"RESET);
        printf("-> ");
        playerEntry = getch() - 48;
        switch(playerEntry) {

            case 1:
                printf("Numero de la quete : ");
                int quest_id = getch() - 48;
                display_quest_rewards(player, quest_id);
                return;


            default:
                return;
        }
    }
}


void display_quest_rewards(Player* player, int quest_id) {
    Quest *current = player->questList;
    bool questExists = false;

    while (current != NULL) {
        if (current->id == quest_id && current->finished) {
            questExists = true;
            break;
        }
        current = current->next;
    }

    if (!questExists) {
        clear();
        printf(RED"Le numero saisi ne correspond a aucune quete.\n"RESET);
        printf("\nRetour (pressez n'importe quelle touche)\n->");
        int pause = getch();
        return;
    }

    if (current->claimedRewards) {
        clear();
        printf(RED"Les recompenses pour cette quete ont deja ete recuperees.\n"RESET);
        printf("\nRetour (pressez n'importe quelle touche)\n->");
        int pause = getch();
        display_done_quests(player);
    }
    else {
        get_quest_rewards(current, player);
    }
}


void get_quest_rewards(Quest *quest, Player *player) {

    clear();

    printf(GREEN"Recompenses de la quete\n\n\n"RESET);

    if(quest->weaponReward != NULL && !quest->claimedWeapon) {
        display_weapon_stats(quest->weaponReward);
        printf("\n\n");
    }


    if(quest->armorReward != NULL && !quest->claimedArmor) {
        display_armor_stats(quest->armorReward);
        printf("\n\n");
    }


    if(quest->goldReward > 0 && !quest->claimedGold) {
        printf(YELLOW"Or : %d\n\n"RESET, quest->goldReward);
    }


    printf(GREEN"Recuperer les recompenses (r)      "RESET);
    printf(RED"Retour (q)\n"RESET);
    printf("-> ");

    int playerEntry = getch();
    switch(playerEntry) {
        case 'r':
            if(quest->goldReward > 0 && !quest->claimedGold) {
                printf(YELLOW"Vous recuperez %d d'or !\n\n"RESET, quest->goldReward);
                player->gold += quest->goldReward;
                quest->claimedGold = true;
                int pass = getch();
                clear();
            }
                printf(BLUE"Vous recuperez %d d'xp !\n\n"RESET, quest->xpReward);
                player->gold += quest->xpReward;
                int pass = getch();
                clear();
                player->currentXP += quest->xpReward;
                player->totalXP += quest->xpReward;
                if(player->currentXP >= player->nextLevelXP) {
                    if(player->levelXP != NB_PLAYER_LEVELS) {
                        next_xp_level(player);
                    }
                }

            get_weapon_quest_reward(quest, player);
            clear();
            printf("\n");
            get_armor_quest_reward(quest, player);
            printf("\n");

            if(quest->claimedArmor && quest->claimedWeapon && quest->claimedGold) {
                quest->claimedRewards = true;
            }

            break;

        case 'q':
            return;

        default:
            get_quest_rewards(quest, player);
    }
}


void get_weapon_quest_reward(Quest *quest, Player *player) {

    if(quest->weaponReward != NULL && !quest->claimedWeapon) {
        display_weapon_stats(quest->weaponReward);
        printf("\n\nAjouter a votre inventaire ? (1)     Equipper (2)        ");
        printf(BLUE"Ignorer (3)\n"RESET);
        int choice = getch() - 48;
        switch(choice) {
            case 1:
                add_item(player,quest->weaponReward, NULL);
                quest->claimedWeapon = true;
                break;

            case 2: // remplacer l'arme equipee
                if(player->current_weapon != NULL) {
                    remove_weapon_inventory(player, player->current_weapon);
                    add_item(player, player->current_weapon, NULL);
                }
                else add_item(player, quest->weaponReward, NULL);

                equip_weapon(player, quest->weaponReward);
                quest->claimedWeapon = true;
                break;

            case 3:
                break;

            default:
                get_quest_rewards(quest, player);
        }
    }
}



void get_armor_quest_reward(Quest *quest, Player *player) {

    if(quest->armorReward != NULL && !quest->claimedArmor) {
        display_armor_stats(quest->armorReward);
        printf("\n\nAjouter a votre inventaire ? (1)     Equipper (2)        ");
        printf(BLUE"Ignorer (3)\n"RESET);
        int choice = getch() - 48;
        switch(choice) {
            case 1:
                add_item(player,NULL, quest->armorReward);
                quest->claimedArmor = true;
                break;

            case 2: // ranger l'armure precedente dans l'inventaire et equipper la nouvelle armure
                if(player->current_armor != NULL) {
                    remove_armor_inventory(player, player->current_armor);
                    add_item(player, NULL, player->current_armor);
                }
                else add_item(player, NULL, quest->armorReward);

                player->current_armor = quest->armorReward;
                player->defense = quest->armorReward->defense;

                quest->claimedArmor = true;
                break;


            case 3:
                break;

            default:
                get_quest_rewards(quest, player);
        }
    }
}


