//
// Created by louis on 07/11/2023.
//

#include "../../headers/weapon/init_random_weapon_name.h"
#include "../../headers/weapon/init_weapon.h"
#include "../../headers/utils.h"

void set_random_weapon_name(Weapon *w) {

    char *commonWeaponNames[5] = {"Lame de fer", "Dague aceree", "Glaive en acier", "Epee courte du chasseur", "Sabre emousse"};
    char *rareWeaponNames[5] = {"Lame de la garde royale", "Hache de guerre aiguisee", "Rapiere forgee", "Epee longue de guerrier", "Marteau de la justice"};
    char *epicWeaponNames[5] = {"Katana de glace", "Faux celeste du protecteur", "Hallebarde du dragon ecarlate", "Baton de mage ancestral", "Masse du heros dechu"};
    char *legendaryWeaponNames[5] = {"Lame du conquerant immortel", "Epee du seigneur divin", "Frappe du champion legendaire", "Lame de la destinee", "Furie cosmique"};

    char *randomName;

    switch (w->rarity) {
        case COMMON:
            randomName = commonWeaponNames[rand() % 5];
            break;
        case RARE:
            randomName = rareWeaponNames[rand() % 5];
            break;
        case EPIC:
            randomName = epicWeaponNames[rand() % 5];
            break;
        case LEGENDARY:
            randomName = legendaryWeaponNames[rand() % 5];
            break;
    }

    setWeaponName(w, randomName);
}