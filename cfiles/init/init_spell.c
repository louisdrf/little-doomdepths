//
// Created by Benzekki Talal on 09/10/2023.
//
#include "../../headers/includes/structs.h"
#include "../../headers/init/init_spell.h"
#include "../../headers/spell/display_spell.h"
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define DEBUG false

Spell *create_random_spell(Spell *head, int index) {

    Spell *new = malloc(sizeof(Spell));
    if(new == NULL) {
#if DEBUG
        printf("Error while allocating memory for spell.\n");
                exit(1);
#endif
    }

    new->id=index;
    new->value=rand() % VALUE_SPELL_MAX + 1;
    new->mana_cost=rand() % SPELL_COST_MAX + 1;
    new->spell_type=rand() % NB_SPELL_TYPE;
    new->name= name_spell(new->spell_type);
    new->next = head;

#if DEBUG
    printf("Spell %d initialized.\n", new->id);
#endif

    return new;

}

Spell *create_spell(Spell *head, int index, int power, int mana_cost, int spell_type, char *name) {

    Spell *new = malloc(sizeof(Spell));

    if(new == NULL) {
#if DEBUG
        printf("Error while allocating memory for spell.\n");
        exit(1);
#endif
    }

    new->id = index;
    new->value = power;
    new->mana_cost = mana_cost;
    new->spell_type = spell_type;
    new->name = malloc(strlen(name) + 1);
    strcpy(new->name , name);
    new->next = head;

#if DEBUG
    printf("Spell %d initialized.\n", new->id);
#endif

    return new;
}


void player_new_spell(Player *player) {

    Spell *new = NULL;

    switch(player->levelXP) {
        case 5:
            new = create_spell(player->book->spell_stock, (player->nbSpells + 1), 4, 5, HEAL, "Vague curative");
            player->book->spell_stock = new;
            player->nbSpells++;
            break;

        case 10:
            new = create_spell(player->book->spell_stock, (player->nbSpells + 1), 8, 6, DAMAGE, "Eclair fulgurant");
            player->book->spell_stock = new;
            player->nbSpells++;
            break;

        case 15:
            new = create_spell(player->book->spell_stock, (player->nbSpells + 1), 10, 7, SHIELD, "Barriere protectrice");
            player->book->spell_stock = new;
            player->nbSpells++;
            break;

        case 20:
            new = create_spell(player->book->spell_stock, (player->nbSpells + 1), 10, 9, DAMAGE, "Flammes devorantes");
            player->book->spell_stock = new;
            player->nbSpells++;
            break;

        case 25:
            new = create_spell(player->book->spell_stock, (player->nbSpells + 1), 10, 10, AOE, "Explosion sismique");
            player->book->spell_stock = new;
            player->nbSpells++;
            break;

        case 30:
            new = create_spell(player->book->spell_stock, (player->nbSpells + 1), 10, 12, HEAL, "Eclat de guerison");
            player->book->spell_stock = new;
            player->nbSpells++;
            break;

        case 35:
            new = create_spell(player->book->spell_stock, (player->nbSpells + 1), 12, 10, SHIELD, "Rempart magique");
            player->book->spell_stock = new;
            player->nbSpells++;
            break;

        case 40:
            new = create_spell(player->book->spell_stock, (player->nbSpells + 1), 15, 10, AOE, "Trou noir du destructeur de mondes");
            player->book->spell_stock = new;
            player->nbSpells++;
            break;

        case 45:
            new = create_spell(player->book->spell_stock, (player->nbSpells + 1), 12, 8, DAMAGE, "Tempete de lames");
            player->book->spell_stock = new;
            player->nbSpells++;
            break;

        case 50:
            new = create_spell(player->book->spell_stock, (player->nbSpells + 1), 15, 10, SHIELD, "Bouclier de guerrier de la destinee");
            player->book->spell_stock = new;
            player->nbSpells++;
            break;
    }
}


Book *init_book()
{
    Book *book = malloc( sizeof(Book));
    for(int i = 0; i < NBSPELL_MAX; i++) {
        book->spell_equipped[i] = NULL;
    }

    if(book == NULL)
    {
#if DEBUG
        printf("Allocating memory for book failed.\n");
#endif
        exit(1);
    }
#if DEBUG
    printf("Book correctly initialized.\n");
#endif

    return book;
}