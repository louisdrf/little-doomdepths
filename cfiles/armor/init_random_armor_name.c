//
// Created by louis on 07/11/2023.
//

#include "../../headers/armor/init_random_armor_name.h"
#include "../../headers/armor/init_armor.h"
#include "../../headers/utils.h"


void set_random_armor_name(Armor *a) {

     char *commonArmorNames[5] = {"Armure en cuir renforce", "Plastron de novice", "Tunique de recrue", "Gambison de novice", "Veste de chasseur"};
     char *rareArmorNames[5] = {"Plastron du gardien", "Cuirasse du veteran", "Armure de la garde royale", "Cotte de mailles forgee", "Plaques en acier noble"};
     char *epicArmorNames[5] = {"Armure de glace", "Armure celeste du protecteur", "Cuirasse du dragon ecarlate", "Robe de mage ancestral", "Armure du heros dechu"};
     char *legendaryArmorNames[5] = {"Plaques du conquerant immortel", "Armure du seigneur divin", "Tunique du champion legendaire", "Cotte de mailles de la destinee", "Armure  de champion cosmique"};

    char *randomName;

    switch (a->rarity) {
        case COMMON:
            randomName = commonArmorNames[rand() % 5];
            break;
        case RARE:
            randomName = rareArmorNames[rand() % 5];
            break;
        case EPIC:
            randomName = epicArmorNames[rand() % 5];
            break;
        case LEGENDARY:
            randomName = legendaryArmorNames[rand() % 5];
            break;
    }

    setArmorName(a, randomName);
}