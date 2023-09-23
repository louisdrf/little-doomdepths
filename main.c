#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "structs.h"
#include "display.h"
#include "player.h"

int main() {

    Game        *game;
    Player      *player;

    display_init_menu();

    game = init_game();
    player = init_player();

    display_player_ath(player);
    display_player(player);
    display_monsters_alive(game->monsters);



    free_player(player);
    free_game(game);

    return EXIT_SUCCESS;
}
