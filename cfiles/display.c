//
// Created by louis on 22/09/2023.
//
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "../headers/display.h"
#include "../headers/includes/colors.h"
#include "../headers/monsters/monster_sprite.h"
#include "../headers/saves/destroy_save.h"

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
    printf(GREEN"Play    (1)\n"RESET);
    printf(RED"Exit    (2)\n\n"RESET);
}

/*
 * player choose the save to play in
 * return the game id
 */
int display_save_choice() {

    int choice;
    printf(RED"-------SAVE CHOICE-------\n\n"RESET);
    printf(MAGENTA"SAVE 1\n");
    printf("SAVE 2\n");
    printf("SAVE 3\n\n"RESET);
    printf("your choice -> ");
    choice = getch() - 48;

    if(choice == 1 || choice == 2 || choice == 3) {
        return choice;
    }
    else display_save_choice();
}


int display_play_or_destroy_save(int save_id) {

    int playerEntry;
    system("cls");

    printf(GREEN"\nPlay (1)      "RESET);
    printf(RED"Delete save (2)\n"RESET);
    printf("-> ");

    playerEntry = getch() - 48;
    switch(playerEntry) {
        case 1:
            return 1; // on charge la partie normalement

        case 2:
            destroy_save(save_id);
            return 2;

        default:
            display_play_or_destroy_save(save_id);
    }
}



void display_all(Player *player) {
    display_player_ath(player);
    print_monsters(player);
    display_monsters_alive(player->current_level->monsters);
    printf(CYAN"\nequipments (e)      inventory (i)      spell (s)      stats (c)     loot(l)\n"
                        "quests     (j)      map       (m)      save  (x)      exit  (q)\n"RESET);
}

void display_player(Player *player) {
    printf(RED"%s\n"RESET, player->draw);
}

void display_player_ath(Player *player) {

    display_player_health(player);
    display_player_mana(player);
    printf("\n");
    display_player_xp(player);
    printf("Gold:     ");
    printf(YELLOW "%d\n" RESET, player->gold);
    printf("Attacks left this turn:   %d\n\n", player->attacks_left);
    printf(MAGENTA"Zone:  %s\n", player->current_zone->name);
    printf("Level: %d"RESET, player->current_level->id);
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



void display_player_xp(Player *player) {

    printf("Current XP level : ");
    printf(BLUE"%d "RESET, player->levelXP);
    printf("        XP to next level : ");
    printf(BLUE"%d%%\n"RESET, (int) (player->currentXP / player->nextLevelXP) * 100);

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




