//
// Created by mokrane on 07/10/2023.
//

#include <string.h>
#include <stdio.h>
#include <conio.h>
#include "../../headers/includes/colors.h"
#include "../../headers/level/display_level_loot_armors.h"
#include "../../headers/inventory/inventory.h"
#include "../../headers/level/display_level_loot.h"
/*
void display_level_loot_armors(Level *level,Player *player) {

    int k=0;
    int levelLootWidth = 0;
    int choice;

    //printf("level->loot_armor[i] = %p\n", (void*)level->loot_armor[i]);
                                                // check si il y a du loot dans le level*
    for(int i =0 ;i<MAX_LEVEL_LOOT_ITEM;i++){
        if(level->loot_armor[i]!= NULL ){
            k++;
        }
    }

    if( k == 0 ){
        printf(RED"\nAucune armure a looter\n\n"RESET);
                                                  // Affiche les armures lootable
    }else {
        for (int w = 0; w < k; w++) {
            if(level->loot_armor[w]!= NULL){
                //printf("apres le while\n");
                levelLootWidth = 40 + (int) strlen(level->loot_armor[w]->name);

                printf("+");
                for (int j = 0; j <
                                levelLootWidth; j++) {                                               // affichage de la ligne du haut
                    printf("-");
                }
                printf("+\n");

                printf("| id : %d |  ",
                       w);                                                      // affiche le numero de l'arme pour choisir celle à équiper

                switch (level->loot_armor[w]->rarity) {
                    case COMMON:
                        printf(GREEN"%s  "RESET, level->loot_armor[w]->name);
                        break;
                        // affiche le nom de l'arme avec la couleur selon sa rareté
                    case RARE:
                        printf(BLUE"%s  "RESET, level->loot_armor[w]->name);
                        break;

                    case EPIC:
                        printf(MAGENTA"%s  "RESET, level->loot_armor[w]->name);
                        break;

                    case LEGENDARY:
                        printf(YELLOW"%s  "RESET, level->loot_armor[w]->name);
                        break;
                }
                printf("|  ");


                printf("defense : ");                                                                                                           // affiche la defense de l'armure
                printf(BLUE"%d"RESET, level->loot_armor[w]->defense);

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
        printf("Equiper une armure (1)   ajouter a l'inventaire (2)     Retour (3)     Arreter de looter (4)\n");
        choice = getch();
        choice -= 48;

        switch(choice) {

            case 1:                                                 // equipe l'arme choisie
                printf("Id de l'armure a equiper : ");
                choice = getch();
                choice -= 48;
                player->current_armor = level->loot_armor[choice];
                printf("\n\n");
                printf("armure equipee : %s | %d \n\n", player->current_armor->name, player->current_armor->defense);
                level->loot_armor[choice]=NULL;
                display_level_loot_choice_sections(level,player);
                break;

            case 2:
                // ajoute l'arme choisie à l/inventaire
                printf("Id de l'arme a ajouter a votre inventaire : ");
                choice = getch();
                choice -= 48;
                int pos = -1;

                pos = get_first_armor_free_space(player);

                if(pos != -1){
                    player->inventory->armorList[pos] = level->loot_armor[choice];
                    printf("\n\n");
                    printf("armure ajoutee : %s | %d \n\n", player->inventory->armorList[pos]->name, player->inventory->armorList[pos]->defense);
                    level->loot_armor[choice]=NULL;

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
                display_level_loot_armors(level,player);
        }
    }


}*/