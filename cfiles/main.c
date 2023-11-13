#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "../headers/game.h"
#include "../headers/display.h"
#include "../headers/player/has_player_a_save.h"
#include "../headers/includes/colors.h"
#include "../headers/utils.h"

#define HAS_SAVE 0
#define LOAD_SAVE 1
#define DESTROY_SAVE 2

int main() {

    srand( time (NULL));

    int choice;
    int save_id;        // choix de la sauvegarde

    display_init_menu();

    choice = getch() - 48;

    switch(choice) {

        case 1: // new game
            save_id = display_save_choice();

            if(has_player_a_save(save_id) == HAS_SAVE) launch_new_game(save_id);
            else
                {
                    if(display_play_or_destroy_save(save_id) == LOAD_SAVE)
                    {
                        load_saved_game(save_id);
                    }
                    else if(display_play_or_destroy_save(save_id) == DESTROY_SAVE) {
                        printf(RED"\nGame %d correctly destroyed."RESET, save_id);
                        return EXIT_SUCCESS;
                    }
                }
            break;

        case 2: // exit
            printf("Bye.");
            break;

        default:
            clear();
            display_init_menu();
    }

    return EXIT_SUCCESS;
}
