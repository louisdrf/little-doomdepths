//
// Created by mokrane on 06/10/2023.
//
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include "../../headers/includes/colors.h"
#include "../../headers/level/display_level_loot_weapons.h"
#include "../../headers/weapon/init_weapon.h"
#include "../../headers/inventory/inventory.h"
#include "../../headers/level/display_level_loot.h"

/*
void display_level_loot_weapons(Level *level,Player *player) {

    int k=0;
    int levelLootWidth = 0;
    int choice;

    //printf("level->loot_weapon[i] = %p\n", (void*)level->loot_weapon[i]);

    for(int i =0 ;i<MAX_LEVEL_LOOT_ITEM;i++){              // check si il y a du loot dans le level*
        if(level->loot_weapon[i]!= NULL ){
            k++;
        }
    }

    if( k == 0 ){
        printf(RED"\nAucune arme a looter\n\n"RESET);
        // Affiche les armes lootable

    }else{
        for(int w =0; w<k ; w++){
            if(level->loot_weapon[w]!= NULL){
                //printf("apres le while");
                levelLootWidth = 40 + (int)strlen(level->loot_weapon[w]->name);

                printf("+");
                for(int j = 0; j < levelLootWidth; j++) {                                               // affichage de la ligne du haut
                    printf("-");
                }
                printf("+\n");

                printf("| id : %d |  ", w);                                                      // affiche le numero de l'arme pour choisir celle à équiper

                switch(level->loot_weapon[w]->rarity) {
                    case COMMON:
                        printf(GREEN"%s  "RESET, level->loot_weapon[w]->name);
                        break;
                        // affiche le nom de l'arme avec la couleur selon sa rareté
                    case RARE:
                        printf(BLUE"%s  "RESET, level->loot_weapon[w]->name);
                        break;

                    case EPIC:
                        printf(MAGENTA"%s  "RESET, level->loot_weapon[w]->name);
                        break;

                    case LEGENDARY:
                        printf(YELLOW"%s  "RESET, level->loot_weapon[w]->name);
                        break;
                }
                printf("|  ");


                printf("att : ");                                                                                                           // affiche l'attaque min et max de l'attaque
                printf(RED"%d-%d "RESET, level->loot_weapon[w]->min_strength, level->loot_weapon[w]->max_strength);
                printf("|  ");

                printf("mana : ");
                printf(BLUE "%d "RESET, level->loot_weapon[w]->mana_cost);                                                        // affiche le cout en mana de l'arme

                printf("\n");
            }else{
                k++;
            }

            }


        printf("+");
        for(int j = 0; j < levelLootWidth; j++) {                                                                                               // affiche la ligne du bas
            printf("-");
        }
        printf("+\n");


        printf("\n");
        printf("Equiper une arme (1)   ajouter a l'inventaire (2)     Retour (3)     Arreter de looter (4)\n");
        choice = getch();
        choice -= 48;

        switch(choice) {

            case 1:                                                 // equipe l'arme choisie
                printf("Id de l'arme a equiper : ");
                choice = getch();
                choice -= 48;
                player->current_weapon = level->loot_weapon[choice];
                player->attacks_by_turn = level->loot_weapon[choice]->attacks_by_turn;
                printf("\n\n");
                printf("arme equipee : %s | %d-%d | %d \n\n", player->current_weapon->name, player->current_weapon->min_strength, player->current_weapon->max_strength, player->current_weapon->mana_cost);
                level->loot_weapon[choice]=NULL;
                display_level_loot_choice_sections(level,player);
                break;

            case 2:
                // ajoute l'arme choisie à l/inventaire
                printf("Id de l'arme a ajouter a votre inventaire : ");
                choice = getch();
                choice -= 48;
                int pos = -1;

                pos = get_first_weapon_free_space(player);

                if(pos != -1){
                    player->inventory->weaponList[pos] = level->loot_weapon[choice];
                    player->inventory->weaponList[pos]->attacks_by_turn = level->loot_weapon[choice]->attacks_by_turn;
                    printf("\n\n");
                    printf("arme ajoutee : %s | %d-%d | %d \n\n", player->inventory->weaponList[pos]->name, player->inventory->weaponList[pos]->min_strength, player->inventory->weaponList[pos]->max_strength, player->inventory->weaponList[pos]->mana_cost);
                    level->loot_weapon[choice]=NULL;

                }else{
                    printf("Pas assez de place dans votre inventaire !");
                }

                display_level_loot_choice_sections(level,player);
                break;

            case 3:
                display_level_loot_choice_sections(level,player);
                break;

            case 4:
                return;

            default:
                display_level_loot_weapons(level,player);
        }

    }

}*/