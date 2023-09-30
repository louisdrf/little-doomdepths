#include <stdio.h>
#include <stdlib.h>
#include "../../headers/includes/structs.h"
//
// Created by Benzekki Talal on 25/09/2023.
//

void free_sprite(char **sprite) {
    free(sprite);

#if DEBUG
    if(sprite == NULL)   printf("\nplayer correctly free\n");
#endif
}
void show_monster_player(char **sprite_player,char **sprite_monster1,char **sprite_monster2,char **sprite_monster3){// la methode les monstre de gauche a droite
    for (int i = 0; i <= 19; ++i) {
        printf("%s",sprite_player[i]);
        if(i<=14){
            if(sprite_monster1!=NULL){
                printf("    ");
                printf("%s",sprite_monster1[i]);}

            if(sprite_monster2!=NULL){
                printf("    ");
                printf("%s",sprite_monster2[i]);}
            if(sprite_monster3!=NULL){
                printf("    ");
                printf("%s",sprite_monster3[i]);}
        }
        printf("\n");
    }

};
char** monster_sprite_random(int type){//La methode prend le type de monstre en parametre et renvoie le sprite correspondant

    char ***sprite= malloc(sizeof(char)*4*405);
    sprite[0]= malloc(sizeof(char)*405);
    sprite[0][0]="                 /\\      ";
    sprite[0][1]="                 ||      ";
    sprite[0][2]="   ____ (((+))) _||_     ";
    sprite[0][3]="  /.--.\\  .-.  /.||.\\    ";
    sprite[0][4]=" /.,   \\\\(0.0)// || \\\\   ";
    sprite[0][5]="/;`\";/\\ \\\\|m|//  ||  ;\\  ";
    sprite[0][6]="|:   \\ \\__`:`____||__:|  ";
    sprite[0][7]="|:    \\__ \\T/ (@~)(~@)|  ";
    sprite[0][8]="|:    _/|     |\\_\\/  :|  ";
    sprite[0][9]="|:   /  |     |  \\   :|  ";
    sprite[0][10]="|'  /   |     |   \\  '|  ";
    sprite[0][11]=" \\_/    |     |    \\_/   ";
    sprite[0][12]="        |     |          ";
    sprite[0][13]="        |_____|          ";
    sprite[0][14]="        |_____|          ";

    sprite[1]= malloc(sizeof(char)*405);
    sprite[1][0]="                         ";
    sprite[1][1]="                         ";
    sprite[1][2]="                         ";
    sprite[1][3]="                         ";
    sprite[1][4]="                         ";
    sprite[1][5]="     <=======]}======    ";
    sprite[1][6]="       --.   /|          ";
    sprite[1][7]="      _\\\"/_.'/           ";
    sprite[1][8]="    .'._._,.'            ";
    sprite[1][9]="    :/ \\{}/              ";
    sprite[1][10]="   (L  /--',----._       ";
    sprite[1][11]="       |          \\\\     ";
    sprite[1][12]="      : /-\\ .'-'\\ / |    ";
    sprite[1][13]="       \\\\, ||    \\|      ";
    sprite[1][14]="        \\/ ||    ||      ";

    sprite[2]= malloc(sizeof(char)*405);
    sprite[2][0]="                         ";
    sprite[2][1]="          .-.            ";
    sprite[2][2]="         (o.o)           ";
    sprite[2][3]="          |=|            ";
    sprite[2][4]="         __|__           ";
    sprite[2][5]="       //.=|=.\\\\         ";
    sprite[2][6]="      // .=|=. \\\\        ";
    sprite[2][7]="      \\\\ .=|=. //        ";
    sprite[2][8]="       \\\\(_=_)//         ";
    sprite[2][9]="        (:| |:)          ";
    sprite[2][10]="         || ||           ";
    sprite[2][11]="         () ()           ";
    sprite[2][12]="         || ||           ";
    sprite[2][13]="         || ||           ";
    sprite[2][14]="        ==' '==           ";

    sprite[3]= malloc(sizeof(char)*405);
    sprite[3][0]="                         ";
    sprite[3][1]="                         ";
    sprite[3][2]="                         ";
    sprite[3][3]="                         ";
    sprite[3][4]="                         ";
    sprite[3][5]="                         ";
    sprite[3][6]="          _____          ";
    sprite[3][7]="      .-,;='';_),-.      ";
    sprite[3][8]="       \\_\\(),()/_/       ";
    sprite[3][9]="         (,___,)         ";
    sprite[3][10]="       / /).:.('--._)    ";
    sprite[3][11]="      {_[ (_,_)          ";
    sprite[3][12]="          | Y |          ";
    sprite[3][13]="         /  |  \\         ";
    sprite[3][14]="        \"\"\" \"\"\"          ";

    return sprite[type];
}
