CREATE TABLE Game (
                      id INTEGER PRIMARY KEY,
                      hasSave INTEGER
);


CREATE TABLE Player (
                        id INTEGER PRIMARY KEY,
                        game_id INTEGER KEY AUTOINCREMENT,
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
                        FOREIGN KEY (game_id) REFERENCES Game(id),
                        FOREIGN KEY (current_weapon_id) REFERENCES Weapon(id),
                        FOREIGN KEY (current_armor_id) REFERENCES Armor(id)
);



CREATE TABLE Spell (
                       id INTEGER PRIMARY KEY,
                       player_id INTEGER,
                       name TEXT,
                       value INTEGER,
                       mana_cost INTEGER,
                       spell_type INTEGER,
                       isEquipped BOOLEAN
);




CREATE TABLE Inventory (
                           id INTEGER PRIMARY KEY,
                           player_id INTEGER KEY AUTOINCREMENT,
                           healthPotion BOOLEAN,
                           manaPotion BOOLEAN,
                           FOREIGN KEY (player_id) REFERENCES Player(id)
);



CREATE TABLE Armor (
                       id INTEGER PRIMARY KEY,
                       inventory_id INTEGER,
                       player_id INTEGER KEY AUTOINCREMENT,
                       armor_name VARCHAR(70),
                       defense INTEGER NOT NULL,
                       rarity INTEGER NOT NULL,
                       FOREIGN KEY (inventory_id) REFERENCES Inventory(id),
                       FOREIGN KEY (player_id) REFERENCES Player(id)
);


CREATE TABLE Weapon (
                        id INTEGER PRIMARY KEY,
                        inventory_id INTEGER,
                        player_id INTEGER KEY AUTOINCREMENT,
                        weapon_name VARCHAR(70),
                        min_strength INTEGER NOT NULL,
                        max_strength INTEGER NOT NULL,
                        attacks_by_turn INTEGER NOT NULL,
                        mana_cost INTEGER,
                        rarity INTEGER NOT NULL,
                        FOREIGN KEY (inventory_id) REFERENCES Inventory(id),
                        FOREIGN KEY (player_id) REFERENCES Player(id)
);

CREATE TABLE Zone (
                      id INTEGER PRIMARY KEY,
                      player_id INTEGER,
                      name TEXT,
                      multiplicator REAL,
                      finished BOOLEAN,
                      difficulty INTEGER
);


CREATE TABLE Level (
                       id INTEGER PRIMARY KEY,
                       zone_id INTEGER,
                       nbMonsters INTEGER,
                       finished BOOLEAN,
                       player_id INTEGER
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
                         loot_gold INTEGER,
                         player_id INTEGER,
                         zone_id INTEGER
);