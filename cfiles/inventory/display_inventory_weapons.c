//
// Created by louis on 04/10/2023.
//

#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "../../headers/inventory/display_inventory_weapons.h"
#include "../../headers/inventory/display_inventory.h"
#include "../../headers/includes/colors.h"
#include "../../headers/weapon/init_weapon.h"
#include "../../headers/utils.h"


void display_player_weapons(Player *player) {

    int i = 0;
    int inventoryWidth = 0;
    int choice;

    clear();

    if(player->inventory->weaponList[i] == NULL) {
        printf(RED"\nAucune arme dans l'inventaire\n\n"RESET);
        printf("Retour (pressez n'importe quelle touche)\n");
        int pass = getch();
        return;
    }

    while(player->inventory->weaponList[i] != NULL)
    {

        inventoryWidth = 40 + (int)strlen(player->inventory->weaponList[i]->name);

        printf("+");
        for(int j = 0; j < inventoryWidth; j++) {                                               // affichage de la ligne du haut
            printf("-");
        }
        printf("+\n");

        printf("| id : %d |  ", i);                                                      // affiche le numero de l'arme pour choisir celle à équiper

        switch(player->inventory->weaponList[i]->rarity) {
            case COMMON:
                printf(GREEN"%s  "RESET, player->inventory->weaponList[i]->name);
                break;
                // affiche le nom de l'arme avec la couleur selon sa rareté
            case RARE:
                printf(BLUE"%s  "RESET, player->inventory->weaponList[i]->name);
                break;

            case EPIC:
                printf(MAGENTA"%s  "RESET, player->inventory->weaponList[i]->name);
                break;

            case LEGENDARY:
                printf(YELLOW"%s  "RESET, player->inventory->weaponList[i]->name);
                break;
        }
        printf("|  ");


        printf("att : ");                                                                                                           // affiche l'attaque min et max de l'attaque
        printf(RED"%d-%d "RESET, player->inventory->weaponList[i]->min_strength, player->inventory->weaponList[i]->max_strength);
        printf("|  ");

        printf("mana : ");
        printf(BLUE "%d "RESET, player->inventory->weaponList[i]->mana_cost);                                                        // affiche le cout en mana de l'arme

        printf("\n");
        i++;
    }

    printf("+");
    for(int j = 0; j < inventoryWidth; j++) {                                                                                               // affiche la ligne du bas
        printf("-");
    }
    printf("+\n");


    printf("\n");
    printf("Equiper une arme (1)    Retour (2)     Fermer l'inventaire (3)\n");
    choice = getch() - 48;

    switch(choice) {

        case 1:                                                 // equipe l'arme choisie
            printf("Id de l'arme a equiper : ");
            choice = getch() - 48;
            equip_weapon(player, player->inventory->weaponList[choice]);
            printf("\n\n");
            printf("Arme equipee : ");
            display_weapon_stats(player->inventory->weaponList[choice]);
            display_inventory_choice_sections(player);
            break;

        case 2:
            display_inventory_choice_sections(player);
            break;

        case 3:
            return;

        default:
            display_player_weapons(player);
    }
}