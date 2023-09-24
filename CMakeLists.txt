cmake_minimum_required(VERSION 3.26)
project(doom C)

set(CMAKE_C_STANDARD 11)

add_executable(doom main.c
        structs.h
        defines.h
        game.c
        game.h
        display.c
        display.h
        player.c
        player.h
        colors.h
        init_monster.c
        init_monster.h
        init_level.c
        init_level.h)
