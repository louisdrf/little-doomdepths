//
// Created by louis on 22/10/2023.
//

#include <stdio.h>
#include "../../headers/saves/create_save.h"
#include "../../headers/includes/structs.h"
#include "../../sqlite3/sqlite3.h"
#include "../../headers/saves/save_inventory.h"
#include "../../headers/saves/save_player.h"
#include "../../headers/saves/save_player_spells.h"
#include "../../headers/db_connexion.h"

void create_save(Game *game, Player *player) {

    sqlite3 *conn = connect_to_db();

    save_player(player, &conn);
    save_inventory(player, &conn);
    save_player_spells_book(player, &conn);
    //save_zones(game);           // sauvegarde zones + leurs niveaux
    //save_game(game);

    sqlite3_close(conn);
}




/*
 * CREATE TABLE Game (
   id INTEGER PRIMARY KEY,
   player_id INTEGER,
   FOREIGN KEY (player_id) REFERENCES Player(id)
);


CREATE TABLE Player (
   id INTEGER PRIMARY KEY,
   name TEXT,
   lifepoints INTEGER,
   shield INTEGER,
   mana INTEGER,
   attacks_left INTEGER,
   gold INTEGER,
   turn BOOLEAN,
   current_weapon_id INTEGER,
   current_armor_id INTEGER,
   current_level_id INTEGER,
   current_zone_id INTEGER,
   inventory_id INTEGER,
   book_id INTEGER,
   FOREIGN KEY (current_weapon_id) REFERENCES Weapon(id),
   FOREIGN KEY (current_armor_id) REFERENCES Armor(id),
   FOREIGN KEY (current_level_id) REFERENCES Level(id),
   FOREIGN KEY (current_zone_id) REFERENCES Zone(id),
   FOREIGN KEY (inventory_id) REFERENCES Inventory(id),
   FOREIGN KEY (book_id) REFERENCES Book(id)
);

CREATE TABLE Spell (
   id INTEGER PRIMARY KEY,
   name TEXT,
   value INTEGER,
   mana_cost INTEGER,
   spell_type INTEGER
);

CREATE TABLE Book (
   id INTEGER PRIMARY KEY,
   spell_equipped_1_id INTEGER,
   spell_equipped_2_id INTEGER,
   spell_equipped_3_id INTEGER,
   spell_stock_id INTEGER,
   FOREIGN KEY (spell_equipped_1_id) REFERENCES Spell(id),
   FOREIGN KEY (spell_equipped_2_id) REFERENCES Spell(id),
   FOREIGN KEY (spell_equipped_3_id) REFERENCES Spell(id),
   FOREIGN KEY (spell_stock_id) REFERENCES Spell(id)
);





CREATE TABLE Armor (
   id INTEGER PRIMARY KEY,
   armor_name VARCHAR(70),
   defense INTEGER NOT NULL,
   rarity INTEGER NOT NULL
);


CREATE TABLE Weapon (
   id INTEGER PRIMARY KEY,
   weapon_name VARCHAR(70),
   min_strength INTEGER NOT NULL,
   max_strength INTEGER NOT NULL,
   attacks_by_turn INTEGER NOT NULL,
   mana_cost INTEGER,
   rarity INTEGER NOT NULL
);


CREATE TABLE Zone (
   id INTEGER PRIMARY KEY,
   game_id INTEGER,
   name TEXT,
   multiplicator REAL,
   finished BOOLEAN,
   difficulty INTEGER,
   FOREIGN KEY (game_id) REFERENCES Game(id)
);


CREATE TABLE Level (
   id INTEGER PRIMARY KEY,
   zone_id INTEGER,
   nbMonsters INTEGER,
   loot_weapon_id INTEGER,
   loot_armor_id INTEGER,
   loot_gold INTEGER,
   finished BOOLEAN,
   FOREIGN KEY (zone_id) REFERENCES Zone(id),
   FOREIGN KEY (loot_weapon_id) REFERENCES Weapon(id),
   FOREIGN KEY (loot_armor_id) REFERENCES Armor(id)
);

CREATE TABLE Monster (
   id INTEGER PRIMARY KEY,
   level_id INTEGER,
   monster_type INTEGER,
   lifepoints INTEGER,
   lifepoints_max INTEGER,
   min_strength INTEGER,
   max_strength INTEGER,
   defense INTEGER,
   attacks_by_turn INTEGER,
   attacks_left INTEGER,
   turn BOOLEAN,
   isAlive BOOLEAN,
   draw TEXT,
   drawIndex INTEGER,
   loot_weapon_id INTEGER,
   loot_armor_id INTEGER,
   loot_gold INTEGER,
   FOREIGN KEY (level_id) REFERENCES Level(id),
   FOREIGN KEY (loot_weapon_id) REFERENCES Weapon(id),
   FOREIGN KEY (loot_armor_id) REFERENCES Armor(id)
);
 */