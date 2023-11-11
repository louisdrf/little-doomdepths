//
// Created by mokrane on 08/11/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "../../headers/includes/structs.h"



void addMonsterToDeadList(Level* level, Monster* monster) {
    Monster* newMonsterNode = malloc(sizeof(Monster));
    if (newMonsterNode == NULL) {
#if DEBUG
        printf("Erreur d'allocation mémoire pour le nouveau monstre mort.\n");
#endif
        return;
    }

    memcpy(newMonsterNode, monster, sizeof(Monster));

    newMonsterNode->next = NULL;

    if (level->dead_monsters == NULL) {
        level->dead_monsters = newMonsterNode;
    } else {
        Monster* current = level->dead_monsters;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newMonsterNode;
    }
}
bool isMonsterInDeadList(Level* level, Monster* monsterToCheck) {
    Monster* currentMonster = level->dead_monsters;
    while (currentMonster != NULL) {
        if (currentMonster->id == monsterToCheck->id) {
            return true; // Le monstre est dans la litse des mosntres morts
        }
        currentMonster = currentMonster->next;
    }
    return false; // Le monstre n'est pas dans la liste des monstres morts
}