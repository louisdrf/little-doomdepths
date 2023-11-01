//
// Created by mokrane on 01/11/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../headers/includes/structs.h"

void displayStoreEquipment(Store *equipment) {
    Store *current = equipment;
    printf("************************************\n");
    printf("*          Store Details           *\n");
    printf("************************************\n");
while(current != NULL){
    printf("* ID: %-25d    *\n", current->id);
    printf("* Type: %-23s    *\n", (current->type == ARME) ? "Weapon" : "Armor");
    printf("* Price: %-21d     *\n", current->prix);
    current = current->next; // Passer à l'élément suivant dans le magasin
}
    printf("************************************\n");

}

