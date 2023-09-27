#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "../headers/game.h"
#include "../headers/includes/structs.h"
#include "../headers/display.h"
#include "../headers/player/player.h"
#include "../headers/loop.h"


int main() {

    Game        *game;
    Player      *player;
    int choice;

    display_init_menu();

    choice = getch();
    choice -= 48;


    switch(choice) {
        case 1: // play from last save
            printf("Load last game ?\n");
            break;

        case 2: // new game
            printf("Launching new game...\n\n");
            game = init_game();                             // init la partie et les niveaux
            player = init_player(game->levelList[0]);       // passer le niveau 0 en argument au joueur

            launch_loop(game, player);

            free_player(player);
            free_game(game);
            break;

        case 3: // exit
            printf("End.");
            break;

        default:
            break;
    }

    return EXIT_SUCCESS;
}
