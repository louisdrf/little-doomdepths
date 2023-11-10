//
// Created by louis on 27/09/2023.
//

#include <conio.h>
#include "../../headers/inventory/inventory.h"
#include "../../headers/includes/structs.h"
#include "../../headers/includes/colors.h"
#include "../../headers/armor/init_armor.h"
#include "../../headers/weapon/init_weapon.h"
#include "../../headers/inventory/potion.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * adding an item in the player inventory
 * @param weapon
 * @param armor
 */
void add_item(Player *player, Weapon *weapon, Armor *armor) {

    int index;
    int place_in_weaponBag = NBOBJECTS_MAX - get_first_weapon_free_space(player);       // nombre de case libres dans le tableau d'armes
    int place_in_armorBag = NBOBJECTS_MAX - get_first_armor_free_space(player);         // nombre de case libres dans le tableau d'armures

    int inventory_left_size = (place_in_weaponBag + place_in_armorBag);

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


void remove_weapon_inventory(Player *player, Weapon *w) {

    for(int i = 0; i < NBOBJECTS_MAX; i++) {
        if(player->inventory->weaponList[i] != NULL) {
            if (strcmp(player->inventory->weaponList[i]->name, w->name) == 0) {
                player->inventory->weaponList[i] = NULL;
                return;
            }
        }
    }
}


void remove_armor_inventory(Player *player, Armor *a) {

    for(int i = 0; i < NBOBJECTS_MAX; i++) {
        if(player->inventory->armorList[i] != NULL) {
            if(strcmp(player->inventory->armorList[i]->name , a->name) == 0) {
                player->inventory->armorList[i] = NULL;
                return;
            }
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

