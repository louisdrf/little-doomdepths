//
// Created by louis on 04/11/2023.
//

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "../../headers/player/display_player_stats.h"
#include "../../headers/includes/colors.h"

void display_player_stats(Player *player) {

    int playerEntry;
    system("cls");

    printf(BLUE"     %s     \n\n"RESET, player->name);
    printf(RED   "PV   : %d / %d\n"RESET, player->lifepoints, player->lifepoints_max);
    printf(BLUE  "MANA : %d / %d\n"RESET, player->mana, player->mana_max);
    printf(RED   "ATT  : %d-%d\n"RESET, player->min_strength, player->max_strength);
    printf(YELLOW"DEF  : %d\n\n"RESET, player->defense);
    printf(RED"Kills :           %d\n"RESET, player->nbKill);
    printf(GREEN"Finished quests : %d\n\n"RESET, player->nbQuestDone);
    printf(GREEN"Finished levels : %d\n\n"RESET, player->nbLevelFinished);

    printf("Retour (q)\n");
    printf("-> ");
    playerEntry = getch();

    switch(playerEntry) {
        case 'q':
            return;

        default:
            display_player_stats(player);
    }

}