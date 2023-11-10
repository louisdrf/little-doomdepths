//
// Created by Benzekki Talal on 09/10/2023.
//
#include "../../headers/includes/structs.h"
#include "../../headers/init/init_spell.h"
#include "../../headers/spell/display_spell.h"
#include "../../headers/monsters/monster.h"
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
Spell *create_spell(Spell *head, int index) {

    Spell *new = malloc(sizeof(Spell));
    if(new == NULL) {
#if DEBUG
        printf("Error while allocating memory for monster.\n");
                exit(1);
#endif
    }

    new->id=index;
    new->value=rand() % VALUE_SPELL_MAX + 1;
    new->mana_cost=rand() % SPELL_COST_MAX + 1;
    new->spell_type=rand() % NB_SPELL_TYPE;
    new->name= name_spell(new->spell_type);
    new->next= head;

#if DEBUG
    printf("Spell %d initialized.\n", new->id);
#endif

    return new;

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
    printf("Inventory correctly initialized.\n");
#endif

    return book;
}