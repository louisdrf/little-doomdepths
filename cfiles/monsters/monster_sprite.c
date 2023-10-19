//
// Created by louis on 01/10/2023.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../headers/monsters/monster_sprite.h"
#include "../../headers/includes/structs.h"
#include "../../headers/includes/defines.h"
#include "../../headers/includes/colors.h"

#define NBMAX_MONSTER_PRINT 3

Monster* little_print_monster(Monster* current){
    int entityWidth = 40;
    int printIndex = 0;
    if (current->isAlive == true) {

        while (current->draw[current->drawIndex] != '\n' && current->draw[current->drawIndex] != '\0') {
            printf( RED"%c"RESET, current->draw[current->drawIndex]);
            current->drawIndex++;
            printIndex++;
        }

        if (current->draw[current->drawIndex] == '\n') {
            current->drawIndex++; // Passer à la ligne suivante
        } else if (current->draw[current->drawIndex] == '\0') {
            while (printIndex < entityWidth) {
                printf(" "); // Ajouter des espaces jusqu'à la largeur de l'entité
                printIndex++;
            }
        }


        while (printIndex < entityWidth) {
            printf(" ");
            printIndex++;
        }

        printIndex = 0;
        return  current->next;
    } else little_print_monster( current->next);
}
void print_monsters(Player *player) {
    int entityWidth = 40; // Une entité prendra 50 caractères de largeur

    Monster *current = player->current_level->monsters;
    int playerIndex = 0;
    int printIndex = 0;     // index du curseur dans la ligne du terminal

    while (player->draw[playerIndex] != '\0')
    {
        while (player->draw[playerIndex] != '\n' && player->draw[playerIndex] != '\0')
        {
            printf(BLUE "%c" RESET, player->draw[playerIndex]);
            playerIndex++;
            printIndex++;
        }
        playerIndex++;
        printIndex++;

        while (printIndex < entityWidth) {
            printf(" ");
            printIndex++;
        }
        printIndex = 0;

        for (int j = 0; j < NBMAX_MONSTER_PRINT; j++) {
            if (current != NULL) {
                if (current->isAlive == true) {

                    while (current->draw[current->drawIndex] != '\n' && current->draw[current->drawIndex] != '\0') {
                        printf( RED"%c"RESET, current->draw[current->drawIndex]);
                        current->drawIndex++;
                        printIndex++;
                    }

                    if (current->draw[current->drawIndex] == '\n') {
                        current->drawIndex++; // Passer à la ligne suivante
                    } else if (current->draw[current->drawIndex] == '\0') {
                        while (printIndex < entityWidth) {
                            printf(" "); // Ajouter des espaces jusqu'à la largeur de l'entité
                            printIndex++;
                        }
                    }

                    current = current->next;
                    while (printIndex < entityWidth) {
                        printf(" ");
                        printIndex++;
                    }
                    printIndex = 0;
                }
                else current =little_print_monster( current->next);
            }
        }

        current = player->current_level->monsters;
        printf("\n");
    }

    monster_indexes_to_zero(player);
}


void monster_indexes_to_zero(Player *player) {

    Monster *current = player->current_level->monsters;

    while(current != NULL) {
        current->drawIndex = 0;
        current = current->next;
    }
}


char *return_monster_sprite(int type) {

    char **monster_sprites = init_monster_sprites();    // on récupère tous les sprites

    switch(type) {
        case GRIM:                              // retourne le char* du grim
            return monster_sprites[GRIM];

        case SKELETON:                         // retourne le char* du skeleton
            return monster_sprites[SKELETON];

        case GHOST:                            // retourne le char* du ghost
            return monster_sprites[GHOST];

        case DRAGON:                            // retourne le char* du dragon
            return monster_sprites[DRAGON];

        default:
            return NULL;
    }

}


char **init_monster_sprites()
{

    char **monster_sprites_list = malloc(NB_MONSTER_TYPE * sizeof(char *));

    char *grim = "                /\\\n"
                 "                 ||\n"
                 "   ____ (((+))) _||_\n"
                 "  /.--.\\  .-.  /.||.\\\n"
                 " /.,   \\\\(0.0)// || \\\\\n"
                 "/;`\";/\\ \\\\|m|//  ||  ;\\\n"
                 "|:   \\ \\__`:`____||__:|\n"
                 "|:    \\__ \\T/ (@~)(~@)|\n"
                 "|:    _/|     |\\_\\/  :|\n"
                 "|:   /  |     |  \\   :|\n"
                 "|'  /   |     |   \\  '|\n"
                 "\\_/    |     |    \\_/\n"
                 "        |     |\n"
                 "        |_____|\n"
                 "        |_____|";

    char *ghost = " .-.\n"
                  "(o o)     \n"
                  "| O \\\n"
                  " \\   \\\n"
                  "  `~~~'";

    char *skeleton = "      .-.\n"
                     "     (o.o)\n"
                     "      |=|\n"
                     "     __|__\n"
                     "   //.=|=.\\\\\n"
                     "  // .=|=. \\\\\n"
                     "  \\\\ .=|=. //\n"
                     "   \\\\(_=_)//\n"
                     "    (:| |:)\n"
                     "     || ||\n"
                     "     () ()\n"
                     "     || ||\n"
                     "     || ||\n"
                     "    ==' '==";

    char *dragon = "       ,===:'.,            `-._\n"
                   "           `:.`---.__         `-._\n"
                   "             `:.     `--.         `.\n"
                   "               \\.        `.         `.\n"
                   "       (,,(,    \\.         `.   ____,-`.,\n"
                   "    (,'     `/   \\.   ,--.___`.'\n"
                   ",  ,'  ,--.  `,   \\.;'\n"
                   " `{D, {    \\  :    \\;\n"
                   "  V,,'    /  /    // \n"
                   "   j;;    /  ,' ,-//.    ,---.      ,\n"
                   "   \\;'   /  ,' /  _  \\  /  _  \\   ,'/\n"
                   "         \\   `'  / \\  `'  / \\  `.' /\n"
                   "          `.___,'   `.__,'   `.__,'    ";




    monster_sprites_list[GRIM] = malloc(strlen(grim) + 1);
    strcpy(monster_sprites_list[GRIM], grim);

    monster_sprites_list[SKELETON] = malloc(strlen(skeleton) + 1);
    strcpy(monster_sprites_list[SKELETON], skeleton);

    monster_sprites_list[GHOST] = malloc(strlen(ghost) + 1);
    strcpy(monster_sprites_list[GHOST], ghost);

    monster_sprites_list[DRAGON] = malloc(strlen(dragon) + 1);
    strcpy(monster_sprites_list[DRAGON], dragon);


    return monster_sprites_list;
}
