//
// Created by mokrane on 01/11/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "../../headers/includes/structs.h"
#include "../../headers/includes/colors.h"

void drawWeapon(Weapon *weapon){
    switch (weapon->rarity) {
        case COMMON :
            printf("\n\n");
            printf(GREEN" ----|)>>>>>>>>>>\n");
            printf(RESET"\n\n");
            break;

        case RARE :
            printf("\n\n");
            printf(BLUE" ----|)>>>>>>>>>>-\n");
            printf(RESET"\n\n");
            break;

        case EPIC :
            printf("\n\n");
            printf(MAGENTA" ----|)>>>>>>>>>>-\n");
            printf(RESET"\n\n");
            break;

        case LEGENDARY :
            printf("\n\n");
            printf(YELLOW" ----|)>>>>>>>>>>-\n");
            printf(RESET"\n\n");
            break;
        default:
            break;
    }
}
