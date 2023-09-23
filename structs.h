//
// Created by louis on 22/09/2023.
//

#ifndef DOOM_STRUCTS_H
#define DOOM_STRUCTS_H
#include <stdbool.h>

typedef struct {

    unsigned short      lifepoints;
    unsigned short      mana;
    unsigned short      min_strength;
    unsigned short      max_strength;
    short               defense;
    unsigned int        attacks_by_turn;
    bool                isAlive;
    bool                turn; // indique si cest au tour du joueur de jouer
    char *              draw;

} Player;



typedef struct {

    char        *picture; // chaine de caractère de dessin du monstre
    int         lifepoints;
    int         min_strength; // attaque min
    int         max_strength; // attaque max
    int         defense;
    int         attacks_by_turn; // nombre d'attaques par tour de jeu
    bool        turn; // indique si cest au tour du monstre de jouer
    char *      draw;

} Monster;



typedef struct {

    int         nbMonsters; // nb de monstres de la partie
    Monster    **monsters; // tableau de pointeurs vers les monstres
    bool        isRunning; // bool d'état de la partie

} Game;

#endif //DOOM_STRUCTS_H
