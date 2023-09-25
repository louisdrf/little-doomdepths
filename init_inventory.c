//
// Created by mokrane on 25/09/2023.
//
#include <stdlib.h>
#include "init_inventory.h"
#include "structs.h"

#define DEBUG false

void init_inventory(Player *player)
{
    player->inventory = malloc(sizeof (Inventory) + (NBOBJECTS_MAX * sizeof(Armor)) + (NBOBJECTS_MAX * sizeof(Weapon)));
    player->inventory->armorList = malloc((NBOBJECTS_MAX * sizeof(Armor)));
    player->inventory->weaponList = malloc((NBOBJECTS_MAX * sizeof(Weapon)));

    if(player->inventory == NULL || player->inventory->armorList == NULL || player->inventory->weaponList == NULL)
    {
        #if DEBUG
                printf("Allocating memory for inventory failed.\n");
        #endif
        exit(1);
    }

    player->inventory->limObjects = NBOBJECTS_MAX;

#if DEBUG
    printf("Inventory correctly initialized.\n");
#endif

}