//
// Created by louis on 04/10/2023.
//

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../headers/inventory/display_inventory_potions.h"
#include "../../headers/includes/structs.h"
#include "../../headers/inventory/potion.h"
#include "../../headers/includes/colors.h"



void display_player_potions(Player *player)
{

    if(player->inventory->manaPotion != NULL && player->inventory->healthPotion != NULL)            // si le joueur a une potion de chaque
    {
        both_potions_in_inventory(player);
    }
    else if(player->inventory->manaPotion != NULL && player->inventory->healthPotion == NULL)       // si le joueur a une potion de mana uniquement
    {
        inventory_only_mana_potion(player);
    }
    else if(player->inventory->healthPotion != NULL && player->inventory->manaPotion == NULL)       // si le joueur a une potion de vie uniquement
    {
        inventory_only_health_potion(player);
    }
    else {
        printf("\nAucune potion dans l'inventaire.\n");
        getch();
        return;
    }
}

void display_both_potions() {
    printf("+-------------------------------------------+\n");
    printf("| ");
    printf(RED"potion de vie    (1)  "RESET);
    printf("| ");
    printf(BLUE"potion de mana  (2)  \n"RESET);
    printf("+-------------------------------------------+\n");

    printf("\n");
    printf("Quitter (4)\n");
}

void display_mana_potion() {
    printf("+-----------------------------+\n");
    printf("| ");
    printf(BLUE"potion de mana      (1)  \n"RESET);
    printf("|");
    printf("+-----------------------------+\n");

    printf("\n");
    printf("Quitter (4)\n");
}

void display_health_potion() {
    printf("+-----------------------------+\n");
    printf("| ");
    printf(RED"potion de vie        (1)  \n"RESET);
    printf("|");
    printf("+-----------------------------+\n");

    printf("\n");
    printf("Quitter (4)\n");
}

void both_potions_in_inventory(Player *player) {
    display_both_potions();

    int choice = getch();
    choice -= 48;
    switch(choice) {
        case 1:                                             // pour la potion de vie
            printf("utiliser ? (1)     retour (2)\n");
            printf("->");
            choice = getch();
            choice -= 48;
            switch(choice)
            {
                case 1: // utiliser la potion
                    use_potion(player, 2);
                    player->inventory->healthPotion = NULL;
                    return;

                case 2: // retour
                    both_potions_in_inventory(player);
            }
            break;

        case 2:                                             // pour la potion de mana
            printf("utiliser ? (1)     retour (2)\n");
            printf("->");
            choice = getch();
            choice -= 48;
            switch(choice)
            {
                case 1: // utiliser la potion
                    use_potion(player, 1);
                    player->inventory->manaPotion = NULL;
                    return;

                case 2: // retour
                    both_potions_in_inventory(player);
            }
            break;

        case 4:
            return;

        default:
            both_potions_in_inventory(player);
    }
}

void inventory_only_health_potion(Player *player) {
    display_health_potion();

    int choice = getch();
    choice -= 48;
    switch(choice) {
        case 1:
            printf("utiliser ? (1)     retour (2)\n");
            printf("->");
            choice = getch();
            choice -= 48;
            switch(choice)
            {
                case 1: // utiliser la potion
                    use_potion(player, 2);
                    player->inventory->healthPotion = NULL;
                    return;

                case 2: // retour
                    display_health_potion();

                default:
                    display_health_potion();
            }
            break;

        case 4:
            return;

        default:
            display_health_potion();
    }
}

void inventory_only_mana_potion(Player *player) {
    display_mana_potion();

    int choice = getch();
    choice -= 48;
    switch(choice) {
        case 1:
            printf("utiliser ? (1)     retour (2)\n");
            printf("->");
            choice = getch();
            choice -= 48;
            switch(choice)
            {
                case 1: // utiliser la potion
                    use_potion(player, 1);
                    return;

                case 2: // retour
                    display_mana_potion();

                default:
                    display_mana_potion();
            }
            break;

        case 4:
            return;

        default:
            display_mana_potion();
    }
}