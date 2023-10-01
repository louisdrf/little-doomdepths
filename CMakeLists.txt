cmake_minimum_required(VERSION 3.26)
project(doom C)

set(CMAKE_C_STANDARD 11)

add_executable(doom cfiles/main.c
        headers/includes/structs.h
        headers/includes/defines.h
        cfiles/game.c
        headers/game.h
        cfiles/display.c
        headers/display.h
        cfiles/player/player.c
        headers/player/player.h
        headers/includes/colors.h
        cfiles/init/init_monster.c
        headers/init/init_monster.h
        cfiles/init/init_inventory.c
        headers/init/init_inventory.h
        cfiles/init/init_level.c
        headers/init/init_level.h
        cfiles/loop.c
        headers/loop.h
        cfiles/player/player_attack.c
        headers/player/player_attack.h
        cfiles/monsters/monster.c
        headers/monsters/monster.h
        cfiles/monsters/monster_sprite.c
        headers/monsters/monster_sprite.h
        cfiles/inventory/inventory.c
        headers/inventory/inventory.h
        cfiles/weapon/init_weapon.c
        headers/weapon/init_weapon.h
        cfiles/inventory/potion.c
        headers/inventory/potion.h
        cfiles/monsters/monster_spritev2.c
        cfiles/monsters/monster_spritev2.h)
