//
// Created by louis on 22/09/2023.
//

#ifndef DOOM_STRUCTS_H
#define DOOM_STRUCTS_H
#include <stdbool.h>

typedef struct {

    unsigned short      lifepoints;         // pv restants
    unsigned short      lifepoints_max;     // pv max
    unsigned short      mana;               // mana restant
    unsigned short      mana_max;           // mana max
    unsigned short      min_strength;
    unsigned short      max_strength;
    unsigned short               defense;
    unsigned short      attacks_by_turn;
    bool                isAlive;
    bool                turn; // indique si cest au tour du joueur de jouer
    char *              draw;

} Player;




typedef struct Monster Monster;

struct Monster {

    unsigned short                 id;
    unsigned short                 monster_type;       //  type de monstre
    unsigned short                 lifepoints;         // pv restants
    unsigned short                 lifepoints_max;     // pv max
    unsigned short                 min_strength;       // attaque min
    unsigned short                 max_strength;       // attaque max
    unsigned short                 defense;
    unsigned short                 attacks_by_turn;    // nombre d'attaques par tour de jeu
    bool                turn;               // indique si cest au tour du monstre de jouer
    bool                isAlive;            // indique si le monstre a été tué ou non
    char *              draw;               // chaine de caractère de dessin du monstre
    struct Monster*     next;

};



typedef struct {

    unsigned short         nbMonsters;         // nb de monstres de la partie
    Monster                *monsters;           // liste chainée de monstres
    bool                   isRunning;          // bool d'état de la partie

} Game;

#endif //DOOM_STRUCTS_H
