//
// Created by louis on 24/09/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include "../../headers/monsters/monster.h"
#include "../../headers/includes/structs.h"

/**
 * return 1 if all monsters are dead, else return 0
 * @param player
 * @return
 */
int are_all_monsters_dead(Player *player) {

    int count = 0;
    Monster *current = player->current_level->monsters;

    while(current != NULL) {

        if(current->isAlive == false) {
            count++;
        }
        current = current->next;
    }

    if(count == player->current_level->nbMonsters) return 1;

    return 0;
}


/**
 * find the targeted monster through the actual player level monsters list
 * @param player
 * @param id
 * @return
 */
Monster *getTargetMonster(Player *player, int id) {

    Monster *current = player->current_level->monsters;

    while(current->id != id) {
        current = current->next;
    }

    return current;
}


int monsters_attack(Player *player) {

    Monster *current = player->current_level->monsters;
    int damages = 0;

    while(current != NULL) { // tous les monstres attaquent le joueur

        if(current->isAlive)
        {
                printf("monstre %d attaque.\n", current->id);

                while(current->attacks_left > 0)                                                // tant que le monstre peut jouer il attaque
                {
                    damages = rand() % current->max_strength + current->min_strength;           // degats du monstre au joueur

                    if( (player->lifepoints - damages) > 0) player->lifepoints -= damages;      // si l'attaque ne tue pas le joueur, elle se fait
                    else
                    {
                        player->isAlive = false;
                        return 1;
                    }
                    current->attacks_left--;
                }
                current->turn = false;                                                          // fin du tour du monstre
                current->attacks_left = current->attacks_by_turn;
                current = current->next;
        }
        else current = current->next;
    }
    player->turn = true;                                                                        // le joueur peut rejouer ensuite
    player->attacks_left = player->attacks_by_turn;
    return 0;
}