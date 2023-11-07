//
// Created by louis on 07/11/2023.
//

#include "../headers/rand.h"

int random_int(int min, int max) {

    return rand() % (max + 1 - min) + min;
}