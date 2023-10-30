//
// Created by louis on 22/09/2023.
//
#include <stdio.h>
#include <conio.h>
#include "../headers/display.h"
#include "../headers/includes/colors.h"
#include "../headers/monsters/monster_sprite.h"

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
    printf("Play    (1)\n");
    printf("Exit    (2)\n\n");
}

/*
 * player choose the save to play in
 * return the game id
 */
int display_save_choice() {

    int choice;
    printf(MAGENTA"-----Choix de la sauvegarde-----\n\n"RESET);
    printf("SAUVEGARDE 1\n");
    printf("SAUVEGARDE 2\n");
    printf("SAUVEGARDE 3\n\n");
    printf("votre choix -> ");
    choice = getch() - 48;

    if(choice == 1 || choice == 2 || choice == 3) return choice;
    else display_save_choice();
}



void display_all(Player *player) {
    display_player_ath(player);
    print_monsters(player);
    display_monsters_alive(player->current_level->monsters);
    printf("\nexit (q)      inventory (i)      map (m)      spell(s)      save(x)\n");
}


void display_player_ath(Player *player) {

    display_player_health(player);
    display_player_mana(player);
    printf("Gold:     ");
    printf(YELLOW "%d\n" RESET, player->gold);
    printf("Attacks left this turn:   %d\n\n", player->attacks_left);
    printf("Current level:            %d", player->current_level->id);
    printf("\n");

}


void display_player_health(Player *player) {

    int i = 0;
    int j = 0;

    printf("Health:   ");
    while(i < (player->lifepoints)/2) {
        printf(RED "#");
        i++;
    }
    while(i < 50) {
        printf("-");
        i++;
    }
    while(j < (player->shield)/2) {
        printf(YELLOW "#");
        j++;
    }
    printf( RESET "  %d/100", player->lifepoints);
    if(player->shield>0){
        printf( YELLOW "  + %d "RESET, player->shield);
    }
    printf("\n");

}



void display_player_mana(Player *player) {

    int i = 0;

    printf("Mana:     ");
    if(player->mana == 0) {
        while(i < 50) {
            printf("-");
            i++;
        }
        printf( RESET "  %d/100", player->mana);
        printf("\n");
        return;
    }

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
            printf("monstre %d - type : %s (%d/%d)\n", current->id, monster_string[current->monster_type], current->lifepoints, current->lifepoints_max);
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




