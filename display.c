//
// Created by louis on 22/09/2023.
//
#include <stdio.h>
#include "display.h"
#include "player.h"
#include "colors.h"


void display_init_menu() {
    printf("                     ----Doomdepths----\n\n");
    printf("                            ,-.                               \n"
           "       ___,---.__          /'|`\\          __,---,___          \n"
           "    ,-'    \\`    `-.____,-'  |  `-.____,-'    //    `-.       \n"
           "  ,'        |           ~'\\     /`~           |        `.      \n"
           " /      ___//              `. ,'          ,  , \\___      \\    \n"
           "|    ,-'   `-.__   _         |        ,    __,-'   `-.    |    \n"
           "|   /          /\\_  `   .    |    ,      _/\\          \\   |   \n"
           "\\  |           \\ \\`-.___ \\   |   / ___,-'/ /           |  /  \n"
           " \\  \\           | `._   `\\\\  |  //'   _,' |           /  /      \n"
           "  `-.\\         /'  _ `---'' , . ``---' _  `\\         /,-'     \n"
           "     ``       /     \\    ,='/ \\`=.    /     \\       ''          \n"
           "             |__   /|\\_,--.,-.--,--._/|\\   __|                  \n"
           "             /  `./  \\\\`\\ |  |  | /,//' \\,'  \\                  \n"
           "            /   /     ||--+--|--+-/-|     \\   \\                 \n"
           "           |   |     /'\\_\\_\\ | /_/_/`\\     |   |                \n"
           "            \\   \\__, \\_     `~'     _/ .__/   /            \n"
           "             `-._,-'   `-._______,-'   `-._,-'");
    printf("\n\n");
    printf("Play from last save (1)\n");
    printf("New game            (2)\n");
    printf("Exit                (3)\n\n");
}

void display_player(Player *player) {
    printf("%s\n", player->draw);
}

void display_player_ath(Player *player) {

    display_player_health(player);
    display_player_mana(player);
    printf("Gold:    " );
    printf(YELLOW "%d\n" RESET, player->gold);
    printf("Attacks left this turn:   %d\n\n", player->attacks_left);
    printf("Current level:            %d", player->current_level->id);
    printf("\n\n\n");

}

void display_player_health(Player *player) {

    int i = 0;

    printf("Health:   ");
    while(i < (player->lifepoints)/2) {
        printf(RED "#");
        i++;
    }
    while(i < 50) {
        printf("-");
        i++;
    }

    printf( RESET "  %d/100", player->lifepoints);
    printf("\n");

}


void display_player_mana(Player *player) {

    int i = 0;

    printf("Mana:     ");

        while(i < (player->mana)/2) {
            printf(BLUE "#");
            i++;
        }
        while(i < 50) {
                printf("-");
                i++;
        }


    printf( RESET "  %d/100", player->mana);
        printf("\n");
}


void display_monsters_alive(Monster *head) {

    Monster *current = head;

    while (current != NULL) {
        if(current->isAlive){
            printf("%d - type : %d (%d/%d)\n", current->id, current->monster_type, current->lifepoints, current->lifepoints_max);
        }
        current = current->next;
    }
};