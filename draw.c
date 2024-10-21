//
// Created by pablo on 21/10/2024.
//
#include <stdlib.h>

#include "draw.h"
char draw9Moves() {
    //chances of each move happening, total 100
    int chances[7] = {22, 15, 7, 7, 21, 21, 7};
    //each time a movement is chosen, its probability of being drawn decreases by 1%
    //counter for each move
    int counter[7] = {0, 0, 0, 0, 0, 0, 0};
    //malloc the array of moves
    char *moves = (char *)malloc(9 * sizeof(char));
    for (int i = 0; i < 9; i++) {
        //random number between 1 and 100
        int random = rand() % 100 + 1;
        if (random<=22) {
            moves[i]= F_10;
            counter[0]+=1;
        }
        else if (random<=37) {
            moves[i]=F_20;
            counter[1]+=1;
        }
        else if (random<=44) {
            moves[i]=F_30;
            counter[2]+=1;
        }
        else if (random<=51) {
            moves[i]=B_10;
            counter[3]+=1;
        }
        else if (random<=72) {
            moves[i]=T_LEFT;
            counter[4]+=1;
        }
        else if (random<=93) {
            moves[i]=T_RIGHT;
            counter[5]+=1;
        }
        else {
            moves[i]=U_TURN;
            counter[6]+=1;
        }
        //decrease the probability of the chosen move by 1%
        for (int j = 0; j < 7; j++) {
            if (counter[j]>0) {
                chances[j]-=1;
            }
        }
    }
    return moves;
}
