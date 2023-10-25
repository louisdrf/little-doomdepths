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

int main() {

    Game        *game;
    Player      *player;
    int choice;
    int save_id;        // choix de la sauvegarde

    display_init_menu();

    choice = getch();
    choice -= 48;

    switch(choice) {

        case 1: // new game
            save_id = display_save_choice();
            if(has_player_a_save(save_id) == 0) printf("\nAucune sauvegarde pour cette partie, lancement d'une nouvelle partie...\n.");
            else printf("\nChargement de la partie...\n");

            game = init_game(save_id);                                 // init la partie et les niveaux
            player = init_player(game);

            launch_loop(game, player);

            free_player(player);
            free_game(game);
            break;

        case 2: // exit
            printf("End.");
            break;

        default:
            system("cls");
            display_init_menu();
    }

    return EXIT_SUCCESS;
}
