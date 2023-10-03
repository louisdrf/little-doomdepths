//
// Created by louis on 22/09/2023.
//
#include <stdio.h>
#include <conio.h>
#include "../headers/display.h"
#include "../headers/player/player.h"
#include "../headers/includes/colors.h"
#include "../headers/monsters/monster_sprite.h"
#include "../headers/monsters/monster_spritev2.h"

void display_init_menu() {
    printf(RED"                     ----Doomdepths----\n\n");
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
    printf("\n\n"RESET);
    printf("Play from last save (1)\n");
    printf("New game            (2)\n");
    printf("Exit                (3)\n\n");
}

void display_all(Player *player) {
    display_player_ath(player);
    print_monsters(player);
    display_monsters_alive(player->current_level->monsters);
    printf("\nexit (q)      inventory (i)\n");
}

void display_player(Player *player) {
    printf(RED"%s\n"RESET, player->draw);
}

void display_player_ath(Player *player) {

    display_player_health(player);
    display_player_mana(player);
    printf("Gold:     ");
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
        if(current->isAlive) {
            printf("monstre %d - type : %d (%d/%d)\n", current->id, current->monster_type, current->lifepoints, current->lifepoints_max);
        }
        current = current->next;
    }
}



int display_next_level_menu() {

    int playerEntry;

    printf("\n\n");
    printf(GREEN"____    ____  ______    __    __     ____    __    ____  ______   .__   __.     __  \n"
           "\\   \\  /   / /  __  \\  |  |  |  |    \\   \\  /  \\  /   / /  __  \\  |  \\ |  |    |  | \n"
           " \\   \\/   / |  |  |  | |  |  |  |     \\   \\/    \\/   / |  |  |  | |   \\|  |    |  | \n"
           "  \\_    _/  |  |  |  | |  |  |  |      \\            /  |  |  |  | |  . `  |    |  | \n"
           "    |  |    |  `--'  | |  `--'  |       \\    /\\    /   |  `--'  | |  |\\   |    |__| \n"
           "    |__|     \\______/   \\______/         \\__/  \\__/     \\______/  |__| \\__|    (__) \n"
           "                                                                                    "RESET);
    printf("\n\n");
    printf("Niveau suivant (1)        Quitter (0)\n\n-->  ");
    playerEntry = getch();
    playerEntry -= 48;                                  // décalage ASCII de la saisie pour obtenir la valeur numérique
    while(playerEntry != 1 && playerEntry != 0) {
        playerEntry = getch();
        playerEntry -= 48;
    }

    return playerEntry;
}

void display_lose() {

    printf("\n\n");
    printf(RED"____    ____  ______    __    __      __        ______        _______. _______     __  \n"
           "\\   \\  /   / /  __  \\  |  |  |  |    |  |      /  __  \\      /       ||   ____|   |  | \n"
           " \\   \\/   / |  |  |  | |  |  |  |    |  |     |  |  |  |    |   (----`|  |__      |  | \n"
           "  \\_    _/  |  |  |  | |  |  |  |    |  |     |  |  |  |     \\   \\    |   __|     |  | \n"
           "    |  |    |  `--'  | |  `--'  |    |  `----.|  `--'  | .----)   |   |  |____    |__| \n"
           "    |__|     \\______/   \\______/     |_______| \\______/  |_______/    |_______|   (__) \n"
           "                                                                                       "RESET);
}




