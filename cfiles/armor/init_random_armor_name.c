//
// Created by louis on 07/11/2023.
//

#include "../../headers/armor/init_random_armor_name.h"
#include "../../headers/rand.h"
#include "../../headers/armor/init_armor.h"


void set_random_armor_name(Armor *a) {

     char *commonArmorNames[5] = {"Armure en cuir renforcé", "Plastron de novice", "Tunique de recrue", "Gambison d'entraînement", "Veste de chasseur"};
     char *rareArmorNames[5] = {"Cotte d'anneaux du gardien", "Cuirasse du vétéran", "Armure de la garde royale", "Cotte de mailles forgée", "Plaques d'acier noble"};
     char *epicArmorNames[5] = {"Armure de l'ombre éternelle", "Armure céleste du protecteur", "Cuirasse du dragon écarlate", "Robe de l'archimage ancestral", "Armure du héros déchu"};
     char *legendaryArmorNames[5] = {"Plaques du conquérant immortel", "Armure du seigneur divin", "Tunique du champion légendaire", "Cotte de mailles de la destinée", "Armure de l'Avatar cosmique"};

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