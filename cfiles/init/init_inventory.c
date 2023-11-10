//
// Created by mokrane on 25/09/2023.
// modified by Louis
//
#include <stdlib.h>
#include "../../headers/init/init_inventory.h"


#define DEBUG false

Inventory *init_inventory()
{
    Inventory *inventory = malloc( sizeof(Inventory));
    for(int i = 0; i < NBOBJECTS_MAX; i++) {
        inventory->weaponList[i] = NULL;
        inventory->armorList[i] = NULL;
    }

    if(inventory == NULL)
    {
        #if DEBUG
                printf("Allocating memory for inventory failed.\n");
        #endif
        exit(1);
    }

    inventory->manaPotion = NULL;
    inventory->healthPotion = NULL;

    inventory->limObjects = NBOBJECTS_MAX;

#if DEBUG
    printf("Inventory correctly initialized.\n");
#endif

    return inventory;
}
