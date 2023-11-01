//
// Created by mokrane on 01/11/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../../headers/includes/structs.h"
#include "../../headers/weapon/init_weapon.h"
#include "../../headers/armor/init_armor.h"
#include "../../headers/init/init_store.h"


Store *create_store(Store *head, int index){
   // srand(time(NULL));
    int random =-1;
    //for(int i = 1; i < MAX_STORE_ITEMS ; i++){
        random = rand () %  2;
        printf("  index : %d  | random : %d  ",index,random);
        Store *newStore = malloc(sizeof(Store));
        if(newStore == NULL) {
#if DEBUG
            printf("Error while allocating memory for Store.\n");
                exit(1);
#endif
        }
        newStore->id = index;

        newStore->type = (random == 0) ? ARME : ARMURE;
        if (random == 0) {
            newStore->contenu.arme = randomWeapon();
            newStore->contenu.armure = NULL;
        }
        if(random == 1 ){
            newStore->contenu.armure = randomArmor();
            newStore->contenu.arme = NULL;
        }
        if(random !=0 && random != 1){
#if DEBUG
            printf("Random Error.\n");
                exit(1);
#endif
        }

        newStore->prix = rand() % 20;
        newStore->next = head;

        return newStore;
    //}


}
void free_store(Store *head){
    if(head!=NULL){
        free_store(head->next);
        free(head);
    }
}
/*
Store *initRandomEquipement(TypeStore type) {
    Store *equipement = malloc(sizeof(Store));

    if (equipement == NULL) {
#if DEBUG
        printf("Allocating memory for equipement failed.\n");
#endif
        exit(1);
    }
    equipement->id= rand();
    equipement->type = type;
    //equipement->nom = NULL;
    equipement->prix = 10;

    switch (type) {
        case ARME:
            equipement->contenu.arme = malloc(sizeof(Weapon));

            if (equipement->contenu.arme == NULL) {
#if DEBUG
                printf("Allocating memory for weapon failed.\n");
#endif
                exit(1);
            }

            equipement->contenu.arme->id = rand();


            equipement->contenu.arme=randomWeapon();

            break;

        case ARMURE:
            equipement->contenu.armure = malloc(sizeof(Armor));

            if (equipement->contenu.armure == NULL) {
#if DEBUG
                printf("Allocating memory for armor failed.\n");
#endif
                exit(1);
            }


            equipement->contenu.armure->id = rand();


            equipement->contenu.armure = randomArmor();

            break;

//        case OBJET_SPECIAL:

  //          break;


        default:
#if DEBUG
            printf("Invalid equipement type.\n");
#endif
            exit(1);
    }

    return equipement;
}

/*
void addWeaponToStore(store* store, Weapon* weapon) {
    if (store == NULL || weapon == NULL) {
        fprintf(stderr, "Invalid store or weapon.\n");
        return;
    }

    store* newStoreItem = malloc(sizeof(store));
    if (newStoreItem == NULL) {
        fprintf(stderr, "Failed to allocate memory for the store item.\n");
        exit(1);
    }

    newStoreItem->type = ARME;
    newStoreItem->contenu.arme = weapon;
    newStoreItem->next = store->next;
    store->next = newStoreItem;
}
*/

/*
// Fonction pour ajouter une arme au magasin
void addWeaponToStore(Store* store, Store* weaponStore) {
    if (store == NULL || weaponStore == NULL) {
#if DEBUG
        fprintf(stderr, "Invalid store or weaponStore.\n");
#endif
        return;
    }
    Store* newStoreItem = malloc(sizeof(Store));
    if (newStoreItem == NULL) {
        fprintf(stderr, "Failed to allocate memory for the store item.\n");
        exit(1);
    }
    weaponStore->next = store->next;
    store->next = weaponStore;
}
*/
