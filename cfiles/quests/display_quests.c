//
// Created by louis on 04/11/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "../../headers/quests/display_quests.h"
#include "../../headers/includes/colors.h"
#include "../../headers/includes/structs.h"
#include "../../headers/weapon/init_weapon.h"
#include "../../headers/armor/init_armor.h"
#include "../../headers/inventory/inventory.h"


void display_quests_menu(Player *player) {

    system("cls");
    int playerEntry;

    printf(GREEN"----- Quetes -----\n\n"RESET);
    printf(BLUE "Liste des quetes  (1)\n"RESET);
    printf(GREEN"Quetes terminees  (2)\n\n\n"RESET);
    printf(     "Retour            (3)\n");
    printf("-> ");

    playerEntry = getch() - 48;
    switch(playerEntry) {
        case 1:
            display_quests(player);
            break;

        case 2:
            display_done_quests(player);
            break;

        case 3:
            return;

        default:
            display_quests_menu(player);
    }
}

void display_quests(Player *player) {
    system("cls");
    int nbQuests = 0;

    Quest *current = player->questList;
    while(current != NULL) {

            printf("%s | terminee : ", current->description);
            if(current->finished == true) printf(GREEN"oui\n"RESET);
            else  printf(RED"non\n"RESET);

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

    system("cls");
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
        system("cls");
        printf(RED"Le numero saisi ne correspond a aucune quete.\n"RESET);
        printf("\nRetour (pressez n'importe quelle touche)\n->");
        int pause = getch();
        display_done_quests(player);
    }

    if (current->claimedRewards) {
        system("cls");
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

    system("cls");

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
                int pass = getch();
            }
            get_weapon_quest_reward(quest, player);
            int pass = getch();
            get_armor_quest_reward(quest, player);
            pass = getch();

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
        printf("\nAjouter a votre inventaire ? (1)     Equipper (2)\n");
        int choice = getch() -48;
        switch(choice) {
            case 1:
                add_item(player,quest->weaponReward, NULL);
                break;

            case 2: // ranger l'arme precedente dans l'inventaire et equipper la nouvelle arme
                add_item(player, player->current_weapon, NULL);
                player->current_weapon = quest->weaponReward;
                player->min_strength = quest->weaponReward->min_strength;
                player->max_strength = quest->weaponReward->max_strength;
                player->attacks_by_turn = quest->weaponReward->attacks_by_turn;
                break;

            default:
                get_quest_rewards(quest, player);
        }
    }
}



void get_armor_quest_reward(Quest *quest, Player *player) {

    if(quest->armorReward != NULL && !quest->claimedArmor) {
        display_armor_stats(quest->armorReward);
        printf("\nAjouter a votre inventaire ? (1)     Equipper (2)\n");
        int choice = getch() -48;
        switch(choice) {
            case 1:
                add_item(player,NULL, quest->armorReward);
                break;

            case 2: // ranger l'armure precedente dans l'inventaire et equipper la nouvelle armure
                add_item(player,NULL, quest->armorReward);
                player->current_armor = quest->armorReward;
                player->defense = quest->armorReward->defense;
                break;

            default:
                get_quest_rewards(quest, player);
        }
    }
}


