#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "../headers/game.h"
#include "../headers/includes/structs.h"
#include "../headers/display.h"
#include "../headers/player/player.h"
#include "../headers/loop.h"
#include "../headers/zones/display_zone.h"
#include "../headers/player/player_spell.h"
#include "../headers/player/has_player_a_save.h"
#include "../headers/saves/load-save/load_game.h"
#include "../headers/saves/load-save/load_player.h"
#include "../headers/includes/colors.h"

#define HAS_SAVE 0
#define LOAD_SAVE 1
#define DESTROY_SAVE 2

int main() {

    int choice;
    int save_id;        // choix de la sauvegarde

    display_init_menu();

    choice = getch();
    choice -= 48;

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
                        launch_new_game(save_id);
                    }
                }
            break;

        case 2: // exit
            printf("Bye.");
            break;

        default:
            system("cls");
            display_init_menu();
    }

    return EXIT_SUCCESS;
}
