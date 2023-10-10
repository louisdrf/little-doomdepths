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
        cfiles/inventory/inventory.c
        headers/inventory/inventory.h
        cfiles/weapon/init_weapon.c
        headers/weapon/init_weapon.h
        cfiles/inventory/potion.c
        headers/inventory/potion.h
        cfiles/monsters/monster_sprite.c
        headers/monsters/monster_sprite.h
        cfiles/inventory/display_inventory.c
        headers/inventory/display_inventory.h
        cfiles/armor/init_armor.c
        headers/armor/init_armor.h
        cfiles/inventory/display_inventory_potions.c
        headers/inventory/display_inventory_potions.h
        cfiles/inventory/display_inventory_armors.c
        headers/inventory/display_inventory_armors.h
        cfiles/inventory/display_inventory_weapons.c
        headers/inventory/display_inventory_weapons.h
        headers/zones/define_zones.h
        cfiles/zones/generate_random_map.c
        headers/zones/generate_random_map.h
        cfiles/zones/create_zone.c
        headers/zones/create_zone.h
        cfiles/zones/init_zones.c
        headers/zones/init_zones.h
        cfiles/zones/display_zone.c
        headers/zones/display_zone.h
)
