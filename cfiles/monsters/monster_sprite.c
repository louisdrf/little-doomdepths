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

#include "../../headers/display.h"
#define NBMAX_MONSTER_PRINT 3

Monster* little_print_monster(Monster* current) {

    int entityWidth = 40;
    int printIndex = 0;
    if (current != NULL) {
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


        while (printIndex < entityWidth) {
            printf(" ");
            printIndex++;
        }

                printIndex = 0;
                return  current->next;
            } else little_print_monster( current->next);
        }
    }
}


void print_monsters(Player *player) {
    int entityWidth = 45; // Une entité prendra 50 caractères de largeur

    int hpIndex=0;
    Monster *current = player->current_level->monsters;
    int playerIndex = 0;
    int printIndex = 0;     // index du curseur dans la ligne du terminal

    if(player->current_zone->map[player->currentX][player->currentY]==2){//Verifie si la zone est une zone de boss
        for (int j = 0; j < NBMAX_MONSTER_PRINT; j++) {
            if (current != NULL) {
                if(current->monster_type>=NB_MONSTER_TYPE){//affiche les pinfo et pv du boss
                    printf("                                  ");
                    printf("%d - %s (%d/%d)", current->id, monster_string[current->monster_type], current->lifepoints, current->lifepoints_max);
                    printf("\n");
                    display_boss_health(current);
                }
                current = current->next;
            }
        }
        current = player->current_level->monsters;
        printf("\n");
        for (int i = 0; i < 18; i++) {

            for (int j = 0; j < NBMAX_MONSTER_PRINT; j++) {
                printf("                                           ");
                if (current != NULL) {
                    if (current->isAlive == true) {
                        if(current->monster_type>=NB_MONSTER_TYPE){


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
                        else{

                            current = current->next;
                        }

                    }
                    else current =little_print_monster( current->next);
                }
            }
            printf("\n");
            current = player->current_level->monsters;
        }
    }
    current = player->current_level->monsters;



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
        if(hpIndex==0 ){
            for (int j = 0; j < NBMAX_MONSTER_PRINT; j++) {
                if (current != NULL) {
                        if (current->isAlive == true) {
                            if(current->monster_type<NB_MONSTER_TYPE) { //affichage des pv et info des monstre non boss

                            printf("%d - %s (%d/%d)", current->id, monster_string[current->monster_type], current->lifepoints, current->lifepoints_max);
                            printf("                            ");
                            current = current->next;
                            }
                            else{
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
                        }
                        else current = current->next;
                }

            }
            printf("\n");
            current = player->current_level->monsters;
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
                            if(current->monster_type<NB_MONSTER_TYPE) {
                            display_monster_health(current);
                            printf("                            ");
                            current = current->next;
                            }
                            else{
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
                        } else current = current->next;

                }

            }
            current = player->current_level->monsters;
            hpIndex++;
        } else{
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

        case BOSS_MINOTAURE:                            // retourne le char* du dragon
            return monster_sprites[BOSS_MINOTAURE];

        case BOSS_LICH:                            // retourne le char* du dragon
            return monster_sprites[BOSS_LICH];
        default:
            return NULL;
    }

}


char **init_monster_sprites()
{

    char **monster_sprites_list = malloc((NB_MONSTER_TYPE+NB_BOSS_TYPE) * sizeof(char *));

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


    char *boss_minotaure="         ,     .\n"
                         "        /(     )\\               A\n"
                         "   .--.( `.___.' ).--.         /_\\\n"
                         "   `._ `%_&%#%$_ ' _.'     /| <___> |\\\n"
                         "      `|(@\\*%%/@)|'       / (  |L|  ) \\\n"
                         "       |  |%%#|  |       J d8bo|=|od8b L\n"
                         "        \\ \\$#%/ /        | 8888|=|8888 |\n"
                         "        |\\|%%#|/|        J Y8P\"|=|\"Y8P F\n"
                         "        | (.\".)%|         \\ (  |L|  ) /\n"
                         "    ___.'  `-'  `.___      \\|  |L|  |/\n"
                         "  .'#*#`-       -'$#*`.       / )|\n"
                         " /#%^#%*_ *%^%_  #  %$%\\    .J (__)\n"
                         " #&  . %%%#% ###%*.   *%\\.-'&# (__)\n"
                         " %*  J %.%#_|_#$.\\J* \\ %'#%*^  (__)\n"
                         " *#% J %$%%#|#$#$ J\\%   *   .--|(_)\n"
                         " |%  J\\ `%%#|#%%' / `.   _.'   |L|\n"
                         " |#$%||` %%%$### '|   `-'      |L|\n"
                         " |#$*|| #$%$$#%%$ |\\           |L|\n"
                         " ||||||  %%(@)$#  |\\\\          |L|\n"
                         " `|||||  #$$|%#%  | L|         |L|\n"
                         "      |  #$%|$%%  | ||l        |L|\n"
                         "      |  ##$H$%%  | |\\\\        |L|\n"
                         "      |  #%%H%##  | |\\\\|       |L|\n"
                         "      |  ##% $%#  | Y|||       |L|\n"
                         "      J $$#* *%#% L  |E/\n"
                         "      (__ $F J$ __)  F/\n"
                         "      J#%$ | |%%#%L\n"
                         "      |$$%#& & %%#|\n"
                         "      J##$ J % %%$F\n"
                         "       %$# * * %#&\n"
                         "       %#$ | |%#$%\n"
                         "       *#$%| | #$*\n"
                         "      /$#' ) ( `%%\\\n"
                         "     /#$# /   \\ %$%\\\n"
                         "    ooooO'     `Ooooo";

    char *boss_lich="                                       .\n"
                    "                                      | |\n"
                    "                                    | [-] |\n"
                    "                                      | |\n"
                    "                                      /|/\n"
                    "              .'` `'.                /////}\n"
                    "             /    ,-.\\              //{///\n"
                    "            /    /:::\\\\            // `||\n"
                    "            |    |:::||          _//   ||\n"
                    "            |    |:::||        _///\\   ||\n"
                    "            |    |:::||       / |/ |   ||\n"
                    "           /     |:::|/     .'`  \\  |  ||\n"
                    "          /     |:::| |_.-`    |  \\    ||\n"
                    "         /|   `\\:::| |        \\   |    ||\n"
                    "       /` `|   /   | |          |   /  ||\n"
                    "     |`    \\   |   / /          \\  |   ||\n"
                    "    |       `\\_|   |/      ,.__. \\ |   ||\n"
                    "    /                    /`     `\\ ||  ||\n"
                    "   |           .        /        \\||  ||\n"
                    "   |                    |         |/  ||\n"
                    "   /         /          |         (   ||\n"
                    "  /          .          /          )  ||\n"
                    " |            \\         |             ||\n"
                    "/             |         /             ||\n"
                    "\\            /         |              ||\n"
                    " `-._       |          /              ||\n"
                    "  ,//`\\    /`          |              ||\n"
                    " ///\\  \\  |            \\              ||\n"
                    "|||| ) |__/            |              ||\n"
                    "|||| `.(               |              ||\n"
                    "`\\\\` /`                /              ||\n"
                    "   /`                  /              ||\n"
                    "  /                    |              ||\n"
                    " |                      \\             ||\n"
                    "/                       |             ||\n"
                    "__,-.      .-.       ___,'            ||\n"
                    "     `---'`   `'----'`";


    monster_sprites_list[GRIM] = malloc(strlen(grim) + 1);
    strcpy(monster_sprites_list[GRIM], grim);

    monster_sprites_list[SKELETON] = malloc(strlen(skeleton) + 1);
    strcpy(monster_sprites_list[SKELETON], skeleton);

    monster_sprites_list[GHOST] = malloc(strlen(ghost) + 1);
    strcpy(monster_sprites_list[GHOST], ghost);

    monster_sprites_list[DRAGON] = malloc(strlen(dragon) + 1);
    strcpy(monster_sprites_list[DRAGON], dragon);

    monster_sprites_list[BOSS_MINOTAURE] = malloc(strlen(boss_minotaure) + 1);
    strcpy(monster_sprites_list[BOSS_MINOTAURE], boss_minotaure);

    monster_sprites_list[BOSS_LICH] = malloc(strlen(boss_lich) + 1);
    strcpy(monster_sprites_list[BOSS_LICH], boss_lich);
    return monster_sprites_list;
}
