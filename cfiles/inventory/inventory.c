//
// Created by louis on 27/09/2023.
//

#include <conio.h>
#include "../../headers/inventory/inventory.h"
#include "../../headers/includes/structs.h"
#include "../../headers/inventory/inventory_sections.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * adding an item in the player inventory
 * @param weapon
 * @param armor
 */
void add_item(Player *player, Weapon *weapon, Armor *armor) {

    int index = 0;
    int place_in_weaponBag = NBOBJECTS_MAX - get_first_weapon_free_space(player);       // nombre de case libres dans le tableau d'armes
    int place_in_armorBag = NBOBJECTS_MAX - get_first_armor_free_space(player);         // nombre de case libres dans le tableau d'armures
    int inventory_left_size = 0;                                        // taille totale de l'inventaire

    inventory_left_size = (place_in_weaponBag + place_in_armorBag);

    if(weapon != NULL) {
        index = get_first_weapon_free_space(player);

        if(inventory_left_size > NBOBJECTS_MAX)
        {
            player->inventory->weaponList[index] = weapon;          // on stocke l'arme dans la case libre si il y a de la place dans l'inventaire
        }
        else {
            printf("pas de place pour une arme de plus !\n");
        }
    }
    else if(armor != NULL)
    {
        index = get_first_armor_free_space(player);
        if(inventory_left_size > NBOBJECTS_MAX)
        {
            player->inventory->armorList[index] = armor;          // on stocke l'armure dans la case libre si il y a de la place dans l'inventaire
        }
        else {
            printf("pas de place pour une armure de plus !\n");
        }
    }

}


/**
 * get the index of the first free space in the weapon inventory to add the item
 * @param player
 * @return
 */
int get_first_weapon_free_space(Player *player) {

    int i = 0;
    while(player->inventory->weaponList[i] != NULL) {
        i++;
    }
    return i; // on retourne la case suivante
}

/**
 * get the index of the first free space in the weapon inventory to add the item
 * @param player
 * @return
 */
int get_first_armor_free_space(Player *player) {

    int i = 0;
    while(player->inventory->armorList[i] != NULL) {
        i++;
    }

    return i; // on retourne la case suivante
}