//
// Created by mokrane on 01/11/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "../../headers/includes/structs.h"
#include "../../headers/includes/colors.h"
void drawArmor(Armor *armor){
    switch (armor->rarity) {
        case COMMON :
            printf("\n\n");
            printf(GREEN"     |  |\n");
            printf(GREEN"  ___|  |___ \n");
            printf(GREEN" |          |\n");
            printf(GREEN" |          |\n");
            printf(GREEN" |__________|\n");
            printf(RESET"\n\n");
            break;
        case RARE :
            printf("\n\n");
            printf(BLUE"     |  |\n");
            printf(BLUE"  ___|  |___ \n");
            printf(BLUE" |          |\n");
            printf(BLUE" |          |\n");
            printf(BLUE" |__________|\n");
            printf(RESET"\n\n");
            break;
        case EPIC :
            printf("\n\n");
            printf(MAGENTA"     |  |\n");
            printf(MAGENTA"  ___|  |___ \n");
            printf(MAGENTA" |          |\n");
            printf(MAGENTA" |          |\n");
            printf(MAGENTA" |__________|\n");
            printf(RESET"\n\n");
            break;
        case LEGENDARY :
            printf("\n\n");
            printf(YELLOW"     |  |\n");
            printf(YELLOW"  ___|  |___ \n");
            printf(YELLOW" |          |\n");
            printf(YELLOW" |          |\n");
            printf(YELLOW" |__________|\n");
            printf(RESET"\n\n");
            break;
        default:
            break;
    }
}
