//
// Created by pablo on 21/10/2024.
//
#include <stdlib.h>
#include <stdio.h>
#include "draw.h"
char* draw9Moves() {
    //chances of each move happening, total 100
    int chances[7] = {22, 15, 7, 7, 21, 21, 7};
    //each time a movement is chosen, its probability of being drawn decreases by 1%
    //counter index for current move
    int counter;
    //malloc the array of moves
    char *moves = (char *)malloc(9 * sizeof(char));
    for (int i = 0; i < 9; i++) {
        //random number between 1 and 100
        int random = randomint(1, 100-i);
        //print random
        printf("%d\n", random);
        if (random<=chances[0]) {
            moves[i]="F_10";
            counter=0;
        }
        else if (random <= chances[0]+chances[1]) {
            moves[i]="F_20";
            counter=1;
        }
        else if (random <= chances[0]+chances[1]+chances[2]) {
            moves[i]="F_30";
            counter=2;
        }
        else if (random<=chances[0]+chances[1]+chances[2]+chances[3]) {
            moves[i]="B_10";
            counter=3;
        }
        else if (random<=chances[0]+chances[1]+chances[2]+chances[3]+chances[4]) {
            moves[i]="T_LEFT";
            counter=4;
        }
        else if (random<=chances[0]+chances[1]+chances[2]+chances[3]+chances[4]+chances[5]) {
            moves[i]="T_RIGHT";
            counter=5;
        }
        else {
            moves[i]="U_TURN";
            counter=6;
        }
        //decrease the probability of the chosen move by 1%
        chances[counter]--;
    }
    return moves;
}

int randomint(int min, int max) {
    return min + rand() % (max - min + 1);
}