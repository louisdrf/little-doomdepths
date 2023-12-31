//
// Created by louis on 22/09/2023.
//

#ifndef DOOM_STRUCTS_H
#define DOOM_STRUCTS_H
#include <stdbool.h>
#include "defines.h"
#include "../zones/define_zones.h"

enum rarity {

    COMMON,
    RARE,
    EPIC,
    LEGENDARY
};

static const char *monster_string[] = {
        "GRIM", "SKELETON", "GHOST", "DRAGON","MINOTAURE","LICH"
};

enum spell_type {
    HEAL,
    DAMAGE,
    SHIELD,
    AOE,
    BUFF_SPEED,
};

enum monster_type {
    GRIM,
    SKELETON,
    GHOST,
    DRAGON,
    BOSS_MINOTAURE,
    BOSS_LICH,

};

enum level_type {
    VOID,
    LEVEL,
    BOSS,
    RANDOM,
    FINISHED
};

enum random_level_types {
    CHEST = 5,
    SHOP
};

typedef struct {

    unsigned short          id;
    unsigned int            defense;
    char*                   name;
    unsigned short          rarity;

} Armor;


typedef struct {

    unsigned short          id;
    char*                   name;
    unsigned short          min_strength;
    unsigned short          max_strength;
    unsigned short          attacks_by_turn;   // nombre d'attaques par tour que confère l'arme
    int                     mana_cost;         // cout en mana d'une attaque
    unsigned short          rarity;            // rareté de l'arme

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
    unsigned short                 attacks_left;       // nombre d'attaques restantes pour le tour
    bool                           turn;               // indique si cest au tour du monstre de jouer
    bool                           isAlive;            // indique si le monstre a été tué ou non
    char*                          draw;               // chaine de caractère de dessin du monstre
    int                            drawIndex;          // index utilisé pour dessiner le monstre
    struct Monster*                next;
    Weapon*                        monster_weapon;     // arme lootable sur le monstre
    Armor*                         monster_armor;      // armure lootable sur le monstre
    unsigned int                   loot_gold;          // gold lootable sur le monstre
    int                            xp;                 // xp donnée par le monstre à sa mort

};


typedef struct {

    unsigned short           id;                                        // niveau 1, 2, 3...
    unsigned short           level_type;                                // chest, level, boss...
    Monster*                 monsters;                                  // liste chainée de monstres
    unsigned short           nbMonsters;                                // nb de monstres de la partie
    unsigned int             loot_gold;                                 // gold lootable sur le niveau
    Weapon*                  loot_weapon;
    Armor*                   loot_armor;
    bool                     finished;                                  // true si le niveau a été fini

} Level;


typedef struct {

    int                     id;
    unsigned short          height;
    unsigned short          width;
    char*                   name;                                   // nom de la zone
    double                  multiplicator;                          // multiplicateur de la zone (xp, gold, monstres...)
    unsigned short          nbLevels;                               // nombre de niveaux/étages de la zone
    Level***                levelList;                              // tableau des niveaux de la zone
    bool                    finished;                               // true si tous les niveaux de la zone ont été terminés
    unsigned short          difficulty;                             // indicateur du niveau de difficulté de la zone (EASY, MODERATE, HARD)
    int**                   map;

} Zone;


typedef struct {

    int**           map;
    int             height;
    int             width;

} Map;


typedef struct {

    unsigned short                 manaValue;
    unsigned short                 healthValue;
    char*                          name;
    char*                          sprite;

} Potion;


typedef struct {

    int                    limObjects;                                  // limite d'objets que le joueur peut transporter
    Weapon*                weaponList[NBOBJECTS_MAX];                   // tableaux de ses armes
    Armor*                 armorList[NBOBJECTS_MAX];                    // tableaux de ses Armures
    Potion*                healthPotion;
    Potion*                manaPotion;

} Inventory;


typedef struct Spell Spell;
struct Spell{

    int                    id;
    char*                  name;                            // nom du sort
    int                    value;                          // puissance du sort
    int                    mana_cost;                       // cout du sort
    unsigned short         spell_type;                      //  type de sort
    struct Spell*          next;

};


typedef struct {

    Spell*                 spell_equipped[NBSPELL_MAX];                            // liste des sort équipé
    Spell*                 spell_stock;                                            // liste chainé de sort


} Book;



typedef struct Quest Quest;
struct Quest {

    int                    id;
    char*                  description;
    int                    goldReward;
    int                    xpReward;
    Weapon                *weaponReward;
    Armor                 *armorReward;
    bool                   claimedRewards;
    struct Quest*          next;
    bool                   finished;
    bool                   displayedAlert;  // pour n'afficher le message d'alerte qu'une fois
    bool                   claimedGold;
    bool                   claimedWeapon;
    bool                   claimedArmor;
};


typedef struct {

    int                 id;
    int                 levelXP;
    int                 totalXP;
    int                 currentXP;
    int                 nextLevelXP;
    int                 levelsXP[NB_PLAYER_LEVELS];
    char*               name;               // nom du joueur
    unsigned short      lifepoints;         // pv restants
    unsigned short      lifepoints_max;     // pv max
    unsigned short      shield;             // bouclier
    unsigned short      mana;               // mana restant
    unsigned short      mana_max;           // mana max
    unsigned short      min_strength;
    unsigned short      max_strength;
    unsigned short      defense;
    unsigned short      attacks_by_turn;
    unsigned short      attacks_left;
    unsigned short      gold;
    int                 currentX;
    int                 currentY;
    bool                isAlive;
    bool                turn;               // indique si cest au tour du joueur de jouer
    char*               draw;
    Weapon*             current_weapon;     // arme équipée
    Armor*              current_armor;      // armure équipée
    Level*              current_level;      // niveau actuel dans lequel se situe le joueur
    Zone*               current_zone;       // zone dans laquelle se situe le joueur
    Inventory*          inventory;          // inventaire du joueur
    Book*               book;               // livre de sorts du joueur
    unsigned short      nbSpells;           // nombre de sorts accumulés
    Quest*              questList;          // liste de quetes du joueur
    int                 nbKill;             // nombre de monstres tués
    int                 nbQuestDone;        // nombre de quetes terminées
    int                 nbLevelFinished;

} Player;




typedef struct {

    int                     id;
    Zone*                   zoneList[NBZONES];              // tableaux des zones de la partie
    bool                    isRunning;                      // bool d'état de la partie
    int                     display_zones_index;            // id de la zone actuelle en affichage

} Game;


#endif //DOOM_STRUCTS_H
