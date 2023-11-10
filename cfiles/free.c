//
// Created by louis on 10/11/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include "../headers/free.h"
#include "../headers/inventory/potion.h"

#define DEBUG true

////////////////////////////////////////// FREE PLAYER ///////////////////////////////////////

void free_player(Player *player) {

    free_inventory(player);

    free(player->draw);
    free(player->name);
#if DEBUG
    printf("free name & draw\n");
#endif

    player->current_zone = NULL;
    player->current_level = NULL;
    printf("free player level and zone\n");

    for(int i = 0; i < NBSPELL_MAX; i++) {
        if(player->book->spell_equipped[i] != NULL) {
            free(player->book->spell_equipped[i]);
        }
    }
#if DEBUG
    printf("free spell equipped\n");
#endif

    free_quest_list(player->questList);
    free_spell_list(player->book->spell_stock);
    free(player->book);

    free(player);

#if DEBUG
    printf("\nplayer correctly free\n");
#endif
}

////////////////////////////////////////// FREE INVENTORY ///////////////////////////////////////


void free_inventory(Player *player) {

    for (int i = 0; i < player->inventory->limObjects; i++) {
        if (player->inventory->weaponList[i] != NULL) {
            printf("arme %p\n", player->inventory->weaponList[i]);
            free_weapon(player->inventory->weaponList[i]);
            free(player->inventory->weaponList[i]);
        }
        else {
            printf("null arme %p\n", player->inventory->armorList[i]);
        }

        if (player->inventory->armorList[i] != NULL) {
            printf("armure %p\n", player->inventory->armorList[i]);
            free_armor(player->inventory->armorList[i]);
            free(player->inventory->armorList[i]);
        }
        else {
            printf("null armure %p\n", player->inventory->armorList[i]);
        }
    }

        destroy_potion(player->inventory->healthPotion);
        destroy_potion(player->inventory->manaPotion);

    free(player->inventory);

#if DEBUG
    printf("\nplayer inventory correctly free\n");
#endif
}

////////////////////////////////////////// FREE WEAPON ///////////////////////////////////////

void free_weapon(Weapon *w) {
    if (w == NULL) {
        return;
    }
    if (w->name != NULL) {
        free(w->name);
    }
    free(w);
}

////////////////////////////////////////// FREE ARMOR ///////////////////////////////////////

void free_armor(Armor *a) {
    if (a == NULL) {
        return;
    }
    if (a->name != NULL) {
        free(a->name);
    }
    free(a);
}


////////////////////////////////////////// FREE QUEST ///////////////////////////////////////

void free_quest_list(Quest *questList) {
    Quest *current = questList;
    Quest *next;

    while (current != NULL) {
        printf("Desallocating quest : %s\n", current->description);
        next = current->next;
        free(current->description);
        free(current);
        current = next;
    }

#if DEBUG
    printf("free player quests done\n");
#endif
}

////////////////////////////////////////// FREE SPELLS ///////////////////////////////////////

void free_spell_list(Spell *spellList) {

    Spell *current = spellList;
    Spell *next;

    while (current != NULL) {
        printf("Desallocating spell : %s\n", current->name);
        next = current->next;
        free(current->name);
        free(current);
        current = next;
    }

#if DEBUG
    printf("free spells done\n");
#endif
}

////////////////////////////////////////// FREE POTIONS ///////////////////////////////////////


void destroy_potion(Potion* potion) {
    if (potion != NULL) {
        free(potion->name);
        free(potion->sprite);
        free(potion);
    }
}