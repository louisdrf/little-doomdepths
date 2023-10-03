//
// Created by louis on 02/10/2023.
//

#include <conio.h>
#include <stdio.h>
#include <string.h>
#include "../../headers/inventory/display_inventory.h"
#include "../../headers/includes/colors.h"


/**
 * display choice menu for inventory sections (weapons, armors, potions)
 * @param player
 */
void display_inventory_choice_sections(Player *player) {
    int choice;
    printf("\n\n    Inventaire\n\n");
    printf("Armes          (1)\n");
    printf("Armures        (2)\n");
    printf("Potions        (3)\n");
    printf("\n");
    printf("Quitter        (q)\n");
    choice = getch();
    choice -= 48;

    display_inventory_section(player, choice);
}


/**
 * display the selected section
 * @param player
 * @param choice
 */
void display_inventory_section(Player *player, int choice) {

    switch(choice) {

        case 1:
            display_player_weapons(player);
            break;

        case 2:
            display_player_armors(player);
            break;

        case 3:
            display_player_potions(player);
            break;

        case 'q':
            return;

        default:
            break;
    }
}


void display_player_weapons(Player *player) {

    int i = 0;
    int inventoryWidth = 0;
    int choice;

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
    choice = getch();
    choice -= 48;           // décalage ascii

    switch(choice) {

        case 1:                                                 // equipe l'arme choisie
            printf("Id de l'arme a equiper : ");
            choice = getch();
            choice -= 48;
            player->current_weapon = player->inventory->weaponList[choice];
            player->attacks_by_turn = player->inventory->weaponList[choice]->attacks_by_turn;
            printf("\n\n");
            printf("arme equipee : %s | %d-%d | %d \n\n", player->current_weapon->name, player->current_weapon->min_strength, player->current_weapon->max_strength, player->current_weapon->mana_cost);
            display_inventory_choice_sections(player);
            break;

        case 2:
            display_inventory_choice_sections(player);
            break;

        case 3:
            return;

        default:
            display_player_weapons(player);
            break;
    }
}


void display_player_armors(Player *player) {

    int i = 0;
    int inventoryWidth = 0;
    int choice;

    while(player->inventory->armorList[i] != NULL)
    {

        inventoryWidth = 30 + (int)strlen(player->inventory->armorList[i]->name);

        printf("+");
        for(int j = 0; j < inventoryWidth; j++) {                                               // affichage de la ligne du haut
            printf("-");
        }
        printf("+\n");

        printf("| id : %d |  ", i);                                                      // affiche le numero de l'armure pour choisir celle à équiper

        switch(player->inventory->armorList[i]->rarity) {
            case COMMON:
                printf(GREEN"%s  "RESET, player->inventory->armorList[i]->name);
                break;
                // affiche le nom de l'armure avec la couleur selon sa rareté
            case RARE:
                printf(BLUE"%s  "RESET, player->inventory->armorList[i]->name);
                break;

            case EPIC:
                printf(MAGENTA"%s  "RESET, player->inventory->armorList[i]->name);
                break;

            case LEGENDARY:
                printf(YELLOW"%s  "RESET, player->inventory->armorList[i]->name);
                break;
        }
        printf("|  ");


        printf("defense : ");                                                                                                           // affiche la defense de l'armure
        printf(BLUE"%d"RESET, player->inventory->armorList[i]->defense);

        printf("\n");
        i++;
    }

    printf("+");
    for(int j = 0; j < inventoryWidth; j++) {                                                                                                   // affiche la ligne du bas
        printf("-");
    }
    printf("+\n");


    printf("\n");
    printf("Equiper une armure (1)    Retour (2)    Fermer l'inventaire (2)\n");
    choice = getch();
    choice -= 48;           // décalage ascii

    switch(choice) {

        case 1:                                                 // equipe l'armure choisie
            printf("Id de l'armure a equiper : ");
            choice = getch();
            choice -= 48;
            player->current_armor = player->inventory->armorList[choice];
            printf("\n\n");
            printf("armure equipee : %s | %d \n\n", player->current_armor->name, player->current_armor->defense);
            display_inventory_choice_sections(player);
            break;

        case 2:
            display_inventory_choice_sections(player);
            break;

        case 3:
            return;

        default:
            display_player_armors(player);
            break;
    }
}

void display_player_potions(Player *player) {
    printf("potions");
}