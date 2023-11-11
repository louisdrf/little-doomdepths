//
// Created by mokrane on 09/11/2023.
//

#include <stdio.h>
#include <conio.h>

#include "../../headers/includes/structs.h"
#include "../../headers/inventory/inventory.h"
#include "../../headers/monsters/display_dead_monster.h"
#include "../../headers/inventory/potion.h"
#include "../../headers/includes/colors.h"

void displayDeadMonstersItems(Player* player) {
    Monster *currentMonster = player->current_level->dead_monsters;
    int monsterIndex = 1;
    int choice;
    Monster *previousMonster = NULL;
    int numDisplayedMonsters = 1;

    while (currentMonster != NULL) {
        printf("%s************************************\n%s", RED, RESET);
        printf("%s*          DEAD MONSTERS           *%s\n", RED,RESET);
        printf(RED"************************************\n"RESET);
        printf("%s*%s Monster #%s%-23d *%s\n", RED, RESET,RED,currentMonster->id, RESET);
        printf("%s*%s Monster Type: %s%-18s *%s\n",RED,RESET, RED,monster_string[currentMonster->monster_type],RESET);
        if (currentMonster->monster_weapon != NULL) {
            dead_monster_weapon_stats_print(currentMonster->monster_weapon, false);
           }

        if (currentMonster->monster_armor != NULL) {
            dead_monster_armor_stats_print(currentMonster->monster_armor, false);
        }

        if (currentMonster->monster_manaPotion != NULL) {
            dead_monster_mana_potion_stats_print(currentMonster->monster_manaPotion, false);
        }

        if (currentMonster->monster_healthPotion != NULL) {
            dead_monster_health_potion_stats_print(currentMonster->monster_healthPotion, false);
        }
        printf("%s************************************\n%s", RED, RESET);
        printf("\n");
        if( currentMonster->monster_weapon != NULL ||
            currentMonster->monster_armor != NULL ||
            currentMonster->monster_manaPotion != NULL ||
            currentMonster->monster_healthPotion != NULL){
            if (numDisplayedMonsters == 1) {
                printf("looter (1)   Suivant (3)   retour (4)\n");
            } else if(currentMonster->next == NULL) {
                printf("looter (1)   precedent (2)   retour (4)\n");
            }else{
                printf("looter (1)   precedent (2)     Suivant (3)     retour (4)\n");

            }

        }else {  // Pour afficher les choix sans l'option "looter"

            if (numDisplayedMonsters == 1) {
                printf("Suivant (3)     retour (4)\n");
            } else if (currentMonster->next == NULL) {
                printf("precedent (2)   retour (4)\n");
            } else {
                printf("precedent (2)     Suivant (3)     retour (4)\n");
            }
        }


        choice = getch();
        choice -= 48;
        switch (choice) {
            case 1:
                //looter le monstre
                displayDeadMonsterItem(player,currentMonster,monsterIndex);
                break;
            case 2:
                // monstre precedent
                if (numDisplayedMonsters > 1) {
                    if (previousMonster != NULL) {
                        currentMonster = previousMonster;
                        previousMonster = NULL;
                        monsterIndex--;
                        numDisplayedMonsters--;
                    } else {
                        displayDeadMonstersItems(player);
#if DEBUG
                        printf("Previous Dead Monster is null.\n");
#endif

                    }
                }

                break;
            case 3 :
                // monstre suivant
                if (currentMonster->next != NULL) {
                    previousMonster = currentMonster;
                    currentMonster = currentMonster->next;
                    monsterIndex++;
                    numDisplayedMonsters++;
                } else {
                    displayDeadMonstersItems(player);
#if DEBUG
                    printf("Next Dead Monster is null.\n");
#endif

                }
                break;

            default:
                return;
        }
    }
}

void displayDeadMonsterItem(Player* player,Monster * deadMonster, int monsterIndex ) {
    Monster *currentMonster = deadMonster;
    int choice;
    if (currentMonster != NULL) {
        printf("%s************************************\n%s", RED, RESET);
        printf("%s*          DEAD MONSTER            *%s\n", RED, RESET);
        printf("%s************************************\n%s", RED, RESET);
        printf("%s*%s Monster #%s%-23d *%s\n", RED, RESET, RED, currentMonster->id, RESET);
        printf("%s*%s Monster Type: %s%-18s *%s\n", RED, RESET, RED, monster_string[currentMonster->monster_type],
               RESET);
// Display correspondant à une arme
        if (currentMonster->monster_weapon != NULL && currentMonster->monster_armor == NULL &&
            currentMonster->monster_manaPotion == NULL && currentMonster->monster_healthPotion == NULL) {
            dead_monster_weapon_stats_print(currentMonster->monster_weapon, true);
            printf("%s************************************\n%s", RED, RESET);
            printf("\n");
            printf("equiper (1)   ajouter a l'inventaire (2)    retour (3)\n");
            choice = player_choice();
            monster_weapon_player_choice(player,currentMonster,choice);
        }
//  display correspondant à une armure
        if (currentMonster->monster_weapon == NULL && currentMonster->monster_armor != NULL &&
            currentMonster->monster_manaPotion == NULL && currentMonster->monster_healthPotion == NULL) {
            dead_monster_armor_stats_print(currentMonster->monster_armor, true);
            printf("%s************************************\n%s", RED, RESET);

            printf("\n");
            printf("equiper (1)   ajouter a l'inventaire (2)    retour (3)\n");
            choice = player_choice();
            monster_armor_player_choice(player,currentMonster,choice);
        }
    // display correspondant à la potion de mana
        if (currentMonster->monster_weapon == NULL && currentMonster->monster_armor == NULL &&
            currentMonster->monster_manaPotion != NULL && currentMonster->monster_healthPotion == NULL) {
            dead_monster_mana_potion_stats_print(currentMonster->monster_manaPotion, true);
            printf("%s************************************\n%s", RED, RESET);
            printf("\n");
            printf("utiliser ? (1)   ajouter a l'inventaire (2)    retour (3)\n");
            choice = player_choice();
            monster_ManaPotion_player_choice(player,currentMonster,choice);
        }
        // display correspondant à la potion de santé
        if (currentMonster->monster_weapon == NULL && currentMonster->monster_armor == NULL &&
            currentMonster->monster_manaPotion == NULL && currentMonster->monster_healthPotion != NULL) {
            dead_monster_health_potion_stats_print(currentMonster->monster_healthPotion, true);
            printf("%s************************************\n%s", RED, RESET);
            printf("\n");
            printf("utiliser ? (1)   ajouter a l'inventaire (2)    retour (3)\n");
            choice = player_choice();
            monster_HealthPotion_player_choice(player,currentMonster,choice);
        }

        if (currentMonster->monster_weapon != NULL && currentMonster->monster_armor == NULL) {

            if (currentMonster->monster_manaPotion == NULL && currentMonster->monster_healthPotion != NULL) {
                const char *color = get_rarity_color(currentMonster->monster_weapon->rarity);
                printf("%s*%s Monster Weapon:  %s(1)             *%s\n", RED, RESET, RED, RESET);
                printf("%s*%s    Name: %s%-23s%s %s*%s\n", RED,RESET,color,currentMonster->monster_weapon->name,RESET,RED,RESET);
                printf("%s*%s Monster Potion:   %s(2)            *%s\n", RED, RESET, RED, RESET);
                printf("%s*%s    Name: %s%-23s *%s\n", RED, RESET,RED,currentMonster->monster_healthPotion->name, RESET);
                printf("%s*************%sRetour (3)%s*************\n%s", RED, RESET,RED,RESET);
                printf("%s************************************\n%s", RED, RESET);
                printf("\n");
                choice = player_choice();
                switch (choice) {
                    case 1: // weapon
                        printf("%s************************************\n%s", RED, RESET);
                        dead_monster_weapon_stats_print(currentMonster->monster_weapon, true);
                        printf("%s************************************\n%s", RED, RESET);
                        printf("equiper (1)   ajouter a l'inventaire (2)    retour (3)\n");
                        choice = player_choice();
                        monster_weapon_player_choice(player,currentMonster,choice);
                        break;
                    case 2: //Potion
                        printf("%s************************************\n%s", RED, RESET);
                        dead_monster_health_potion_stats_print(currentMonster->monster_healthPotion, true);
                        printf("%s************************************\n%s", RED, RESET);
                        printf("utiliser ? (1)   ajouter a l'inventaire (2)    retour (3)\n");
                        choice = player_choice();
                        monster_HealthPotion_player_choice(player,currentMonster,choice);
                        break;
                    case 3:
                        return;
                    default:
                        break;

                }
            } else if (currentMonster->monster_manaPotion != NULL && currentMonster->monster_healthPotion == NULL) {
                const char *color = get_rarity_color(currentMonster->monster_weapon->rarity);
                printf("%s*%s Monster Weapon:  %s(1)             *%s\n", RED, RESET, RED, RESET);
                printf("%s*%s    Name: %s%-23s%s %s*%s\n", RED,RESET,color,currentMonster->monster_weapon->name,RESET,RED,RESET);
                printf("%s*%s Monster Potion:  %s(2)             *%s\n", RED, RESET, RED, RESET);
                printf("%s*%s    Name: %s%-23s%s %s*%s\n", RED, RESET, BLUE, currentMonster->monster_manaPotion->name,
                       RESET, RED, RESET);
                printf("%s*************%sRetour (3)%s*************\n%s", RED, RESET,RED,RESET);
                printf("%s************************************\n%s", RED, RESET);
                printf("\n");
                choice = player_choice();
                switch (choice) {
                    case 1: // weapon
                        printf("%s************************************\n%s", RED, RESET);
                        dead_monster_weapon_stats_print(currentMonster->monster_weapon, true);
                        printf("%s************************************\n%s", RED, RESET);
                        printf("equiper (1)   ajouter a l'inventaire (2)    retour (3)\n");
                        choice = player_choice();
                        monster_weapon_player_choice(player,currentMonster,choice);
                        break;
                    case 2: //Potion
                        dead_monster_mana_potion_stats_print(currentMonster->monster_manaPotion, true);
                        printf("%s************************************\n%s", RED, RESET);

                        printf("utiliser ? (1)   ajouter a l'inventaire (2)    retour (3)\n");
                        choice = player_choice();
                        monster_ManaPotion_player_choice(player,currentMonster,choice);
                        break;
                    case 3:
                        return;
                    default:
                        break;
                }
            }
        } else if (currentMonster->monster_weapon == NULL && currentMonster->monster_armor != NULL) {

            if (currentMonster->monster_manaPotion == NULL && currentMonster->monster_healthPotion != NULL) {
                const char *color = get_rarity_color(currentMonster->monster_armor->rarity);
                printf("%s*%s Monster Armor:  %s(1)              *%s\n", RED, RESET, RED, RESET);
                printf("%s*%s    Name: %s%-23s%s %s*%s\n", RED,RESET,color,currentMonster->monster_armor->name,RESET,RED,RESET);
                printf("%s*%s Monster Potion: %s(2)              *%s\n", RED, RESET, RED, RESET);
                printf("%s*%s    Name: %s%-23s *%s\n", RED, RESET, RED,currentMonster->monster_healthPotion->name, RESET);
                printf("%s*************%sRetour (3)%s*************\n%s", RED, RESET,RED,RESET);
                printf("%s************************************\n%s", RED, RESET);
                printf("\n");
                choice = player_choice();
                switch (choice) {
                    case 1: // armor
                        printf("%s************************************\n%s", RED, RESET);
                        dead_monster_armor_stats_print(currentMonster->monster_armor, true);
                        printf("%s************************************\n%s", RED, RESET);

                        printf("equiper (1)   ajouter a l'inventaire (2)    retour (3)\n");
                        choice = player_choice();
                        monster_armor_player_choice(player,currentMonster,choice);
                        break;
                    case 2: //Potion
                        printf("%s************************************\n%s", RED, RESET);
                        dead_monster_health_potion_stats_print(currentMonster->monster_healthPotion, true);
                        printf("%s************************************\n%s", RED, RESET);
                        printf("utiliser ? (1)   ajouter a l'inventaire (2)    retour (3)\n");
                        choice = player_choice();
                        monster_HealthPotion_player_choice(player,currentMonster,choice);
                        break;
                    case 3:
                        return;
                    default:
                        break;
                }

            } else if (currentMonster->monster_manaPotion != NULL && currentMonster->monster_healthPotion == NULL) {
                const char *color = get_rarity_color(currentMonster->monster_armor->rarity);
                printf("%s*%s Monster Armor: %s(1)               *%s\n", RED, RESET, RED, RESET);
                printf("%s*%s    Name: %s%-23s%s %s*%s\n", RED,RESET,color,currentMonster->monster_armor->name,RESET,RED,RESET);            printf("%s*%s Looted Potion: %s(2)               *%s\n", RED, RESET, RED, RESET);
                printf("%s*%s    Name: %s%-23s%s %s*%s\n", RED, RESET, BLUE, currentMonster->monster_manaPotion->name,
                       RESET, RED, RESET);
                printf("%s************************************\n%s", RED, RESET);
                printf("%s*************%sRetour (3)%s*************\n%s", RED, RESET,RED,RESET);
                printf("\n");
                choice = player_choice();
                switch (choice) {
                    case 1: // armor
                        printf("%s************************************\n%s", RED, RESET);
                        dead_monster_armor_stats_print(currentMonster->monster_armor, true);
                        printf("%s************************************\n%s", RED, RESET);
                        printf("equiper (1)   ajouter a l'inventaire (2)    retour (3)\n");
                        choice = player_choice();
                        monster_armor_player_choice(player,currentMonster,choice);
                        break;
                    case 2: //Potion
                        printf("%s************************************\n%s", RED, RESET);
                        dead_monster_mana_potion_stats_print(currentMonster->monster_manaPotion, true);
                        printf("%s************************************\n%s", RED, RESET);
                        printf("utiliser ? (1)   ajouter a l'inventaire (2)    retour (3)\n");
                        choice = player_choice();
                        monster_ManaPotion_player_choice(player,currentMonster,choice);
                        break;
                    case 3:
                        return;
                    default:
                        break;

                }
            }

        }
    }else{
#if DEBUG
        printf("Error on dead monster.\n");
                exit(1);
#endif
    }
}



int player_choice(){
    int choice;
    choice = getch();
    choice -= 48;
    while (choice != 1 && choice != 2 && choice != 3) {
        choice = getch();
        choice -= 48;
    }
    return choice;
}
void dead_monster_weapon_stats_print(Weapon *weapon ,bool more){
    if (weapon != NULL) {
        const char *color = get_rarity_color(weapon->rarity);

        printf("%s*%s Monster Weapon:                  %s*%s\n",RED,RESET,RED,RESET);
        printf("%s*%s    Name: %s%-23s%s %s*%s\n", RED,RESET,color,weapon->name,RESET,RED,RESET);
        if(more){
            printf("%s*%s    Attack: %s%-2d%s-%s%-18d%s %s*%s\n", RED, RESET, RED, weapon->min_strength, RESET, GREEN, weapon->max_strength, RESET, RED, RESET);
            printf("%s*%s    Mana: %s%-23d%s %s*%s\n",RED,RESET,BLUE, weapon->mana_cost,RESET,RED,RESET);
            printf("%s*%s    Attack by turn: %s%-13d%s %s*%s\n",RED,RESET,RED, weapon->attacks_by_turn,RESET,RED,RESET);
        }
    }
}
void dead_monster_armor_stats_print(Armor *armor,bool more){
    if (armor != NULL) {
        const char *color = get_rarity_color(armor->rarity);
        printf("%s*%s Monster Armor:                   %s*%s\n",RED,RESET,RED,RESET);
        printf("%s*%s    Name: %s%-23s%s %s*%s\n", RED,RESET,color,armor->name,RESET,RED,RESET);
        if(more){
            printf("%s*%s    Defense: %s%-20d%s %s*%s\n",RED,RESET,GREEN, armor->defense,RESET,RED,RESET);
        }
    }
}
void dead_monster_health_potion_stats_print(Potion *healthpotion,bool more){
    if (healthpotion != NULL) {
        printf("%s*%s Monster Potion:                  %s*%s\n",RED,RESET,RED,RESET);
        printf("%s*%s    Name: %s%-23s *%s\n", RED,RESET,RED,healthpotion->name,RESET);
        if(more){
            printf("%s*%s    Health: %s%-21d%s %s*%s\n",RED,RESET,RED, healthpotion->healthValue,RESET,RED,RESET);

    }
    }
}
void dead_monster_mana_potion_stats_print(Potion *manapotion,bool more){
    if (manapotion != NULL) {
        printf("%s*%s Monster Potion:                  %s*%s\n",RED,RESET,RED,RESET);
        printf("%s*%s    Name: %s%-23s%s %s*%s\n", RED,RESET,BLUE,manapotion->name,RESET,RED,RESET);
        if(more){
            printf("%s*%s    Mana: %s%-23d%s %s*%s\n",RED,RESET,BLUE, manapotion->manaValue,RESET,RED,RESET);

        }
    }
}

const char *get_rarity_color(unsigned short rarity) {
    switch (rarity) {
        case COMMON:
        return GREEN;
        case RARE:
            return BLUE;
        case EPIC:
            return MAGENTA;
        case LEGENDARY:
            return YELLOW;
        default:
            return RESET;
    }
}

void monster_weapon_player_choice(Player *player, Monster *currentMonster, int choice){
    switch (choice) {
        case 1: // équiper une arme
            if (currentMonster->monster_weapon != NULL) {
                player->current_weapon = currentMonster->monster_weapon;
                printf("Arme equipee : %s | %d-%d | %d \n\n", player->current_weapon->name,
                       player->current_weapon->min_strength, player->current_weapon->max_strength,
                       player->current_weapon->mana_cost);
                currentMonster->monster_weapon = NULL;
            }
            break;

        case 2: // ajouter une arme a l'inventaire
            if (currentMonster->monster_weapon != NULL) {
                int pos = get_first_weapon_free_space(player);
                if (pos != -1) {
                    player->inventory->weaponList[pos] = currentMonster->monster_weapon;
                    printf("arme ajoutee : %s | %d-%d | %d \n\n",
                           player->inventory->weaponList[pos]->name,
                           player->inventory->weaponList[pos]->min_strength,
                           player->inventory->weaponList[pos]->max_strength,
                           player->inventory->weaponList[pos]->mana_cost);
                    currentMonster->monster_weapon = NULL;
                } else {
                    printf("Pas assez de place dans votre inventaire !");
                }
            }
            break;
        case 3 :
            return;
        default:
            break;
    }
}

void monster_armor_player_choice(Player *player, Monster *currentMonster, int choice){
    switch (choice) {
        case 1: // équiper une armure
            if (currentMonster->monster_armor != NULL) {
                player->current_armor = currentMonster->monster_armor;
                currentMonster->monster_armor = NULL;
            }
            break;
        case 2: // ajouter une armure a l'inventaire
            if (currentMonster->monster_armor != NULL) {
                int pos = get_first_armor_free_space(player);
                if (pos != -1) {
                    player->inventory->armorList[pos] = currentMonster->monster_armor;
                    printf("armure ajoutee : %s | %d \n\n", player->inventory->armorList[pos]->name,
                           player->inventory->armorList[pos]->defense);
                    currentMonster->monster_armor = NULL;
                } else {
                    printf(RED"Pas assez de place dans votre inventaire !");
                }
            }
            break;
        case 3 :
            return;
        default:
            break;
    }
}

void monster_ManaPotion_player_choice(Player *player, Monster *currentMonster, int choice) {
    switch (choice) {
        case 1: // utiliser la potion
            use_potion(player, 1);
            currentMonster->monster_manaPotion = NULL;
            break;
        case 2: // stocker la potion
            give_player_potion(player, 1);
            currentMonster->monster_manaPotion = NULL;
            printf("\nPotion ajoutee a l'inventaire. (+30)\n");
            break;
        case 3: // retour
            return;
        default:
            break;
    }
}

void monster_HealthPotion_player_choice(Player *player, Monster *currentMonster, int choice) {
    switch (choice) {
        case 1: // utiliser la potion
            use_potion(player, 2);
            currentMonster->monster_healthPotion = NULL;
            break;
        case 2: // stocker la potion
            give_player_potion(player, 2);
            currentMonster->monster_healthPotion = NULL;
            printf("\nPotion ajoutee a l'inventaire. (+30)\n");
            break;
        case 3: // retour
            return;
        default:
            break;
    }

}