CREATE TABLE Game (
                      id INTEGER PRIMARY KEY,
                      hasSave INTEGER
);


CREATE TABLE Player (
                        id INTEGER PRIMARY KEY,
                        name VARCHAR(40),
                        lifepoints INTEGER,
                        shield INTEGER,
                        mana INTEGER,
                        attacks_left INTEGER,
                        gold INTEGER,
                        turn BOOLEAN,
                        current_zone_id INTEGER,
                        current_level_id INTEGER,
                        posX INTEGER,
                        posY INTEGER,
                        nbKill INTEGER,
                        nbQuestDone INTEGER,
                        nbLevelFinished INTEGER,
                        levelXP INTEGER,
                        totalXO INTEGER,
                        currentXP INTEGER
);



CREATE TABLE Spell (
                       id INTEGER PRIMARY KEY,
                       player_id INTEGER,
                       name TEXT,
                       value INTEGER,
                       mana_cost INTEGER,
                       spell_type INTEGER,
                       isEquipped BOOLEAN,
                       spell_id INTEGER
);




CREATE TABLE Inventory (
                           id INTEGER PRIMARY KEY,
                           player_id INTEGER KEY AUTOINCREMENT,
                           healthPotion BOOLEAN,
                           manaPotion BOOLEAN
);



CREATE TABLE Armor (
                       id INTEGER PRIMARY KEY,
                       inventory_id INTEGER,
                       armor_name VARCHAR(70),
                       defense INTEGER NOT NULL,
                       rarity INTEGER NOT NULL,
                       isEquipped INTEGER,
                       quest_id INTEGER
);


CREATE TABLE Weapon (
                        id INTEGER PRIMARY KEY,
                        inventory_id INTEGER,
                        weapon_name VARCHAR(70),
                        min_strength INTEGER NOT NULL,
                        max_strength INTEGER NOT NULL,
                        attacks_by_turn INTEGER NOT NULL,
                        mana_cost INTEGER,
                        rarity INTEGER NOT NULL,
                        isEquipped INTEGER,
                        quest_id INTEGER
);

CREATE TABLE Zone (
                      id INTEGER PRIMARY KEY,
                      player_id INTEGER,
                      name TEXT,
                      multiplicator REAL,
                      finished BOOLEAN,
                      difficulty INTEGER,
                      height INTEGER,
                      width INTEGER,
                      zone_id INTEGER
);


CREATE TABLE Level (
                       id INTEGER PRIMARY KEY,
                       zone_id INTEGER,
                       nbMonsters INTEGER,
                       finished BOOLEAN,
                       player_id INTEGER,
                       height_index INTEGER,
                       width_index INTEGER
);

CREATE TABLE Monster (
                         id INTEGER PRIMARY KEY,
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
                         zone_id INTEGER,
                         monster_id INTEGER,
                         level_height_index INTEGER,
                         level_width_index INTEGER,
                         xp INTEGER
);

CREATE TABLE Quests (
                        id INTEGER PRIMARY KEY,
                        player_id INTEGER,
                        quest_id INTEGER,
                        description VARCHAR(70),
                        gold_reward INTEGER,
                        claimedRewards INTEGER,
                        finished INTEGER,
                        displayedAlert INTEGER,
                        claimedGold INTEGER,
                        claimedWeapon INTEGER,
                        claimedArmor INTEGER,
                        xp INTEGER
);


INSERT INTO Game(id, hasSave) VALUES (1, 0);
INSERT INTO Game(id, hasSave) VALUES (2, 0);
INSERT INTO Game(id, hasSave) VALUES (3, 0);

INSERT INTO Player(id) VALUES(1);
INSERT INTO Player(id) VALUES(2);
INSERT INTO Player(id) VALUES(3);

INSERT INTO Inventory(id, player_id) VALUES(1, 1);
INSERT INTO Inventory(id, player_id) VALUES(2, 2);
INSERT INTO Inventory(id, player_id) VALUES(2, 2);