//
// Created by louis on 22/09/2023.
//

#ifndef DOOM_STRUCTS_H
#define DOOM_STRUCTS_H
#include <stdbool.h>

enum rarity {

    COMMON,
    RARE,
    EPIC,
    LEGENDARY
};

typedef struct {

    unsigned int        defense;
    char*               name;
    unsigned short      rarity;

} Armor;


typedef struct {

    char*                   name;
    unsigned short          min_strength;
    unsigned short          max_strength;
    unsigned short          attacks_by_turn; // nombre d'attaques par tour que confère l'arme
    char*                   draw;

} Weapon;

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
    bool                           turn;               // indique si cest au tour du monstre de jouer
    bool                           isAlive;            // indique si le monstre a été tué ou non
    char *                         draw;               // chaine de caractère de dessin du monstre
    struct Monster*                next;
    struct Weapon*                 loot_weapon;        // arme lootable sur le monstre
    struct Armor*                  loot_armor;         // armure lootable sur le monstre
    unsigned int                   loot_gold;          // gold lootable sur le monstre

};


typedef struct {

    Monster*                 monsters;           // liste chainée de monstres
    unsigned short           id;                  // niveau 1, 2, 3...
    unsigned short           nbMonsters;          // nb de monstres de la partie
    struct Weapon*           loot_weapon;        // arme lootable sur le niveau
    struct Armor*            loot_armor;         // armure lootable sur le niveau
    unsigned int             loot_gold;          // gold lootable sur le niveau

} Level;



typedef struct {

    unsigned short      lifepoints;         // pv restants
    unsigned short      lifepoints_max;     // pv max
    unsigned short      mana;               // mana restant
    unsigned short      mana_max;           // mana max
    unsigned short      min_strength;
    unsigned short      max_strength;
    unsigned short      defense;
    unsigned short      attacks_by_turn;
    unsigned short      attacks_left;
    unsigned short      gold;
    bool                isAlive;
    bool                turn;               // indique si cest au tour du joueur de jouer
    char*               draw;
    Weapon*             current_weapon;     // arme équipée
    Armor*              current_armor;      // armure équipée
    Level*              current_level;      // niveau actuel dans lequel se situe le joueur

} Player;




typedef struct {

    Level**                 levelList;           // tableaux des niveaux de la partie
    bool                    isRunning;           // bool d'état de la partie

} Game;



#endif //DOOM_STRUCTS_H
