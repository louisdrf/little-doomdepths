//
// Created by mokrane on 25/09/2023.
//
#include <stdlib.h>
#include <stdio.h>
#include "../../headers/init/init_inventory.h"
#include "../../headers/includes/structs.h"
#include "../../headers/includes/defines.h"

#define DEBUG true

Inventory *init_inventory()
{
    Inventory *inventory = malloc( sizeof(Inventory));

    if(inventory == NULL)
    {
        #if DEBUG
                printf("Allocating memory for inventory failed.\n");
        #endif
        exit(1);
    }

    inventory->limObjects = NBOBJECTS_MAX;

#if DEBUG
    printf("Inventory correctly initialized.\n");
#endif

    return inventory;
}