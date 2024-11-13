//
// Created by pablo on 21/10/2024.
//

#ifndef DRAW_H
#define DRAW_H

//function to return a list of 9 moves following a probability rule and using the structure t_moves in moves.h


/**
 * @brief function to draw 9 moves
 * @return the list of 9 moves
 */
char* draw9Moves();

/**
 * @brief function to return a random number between min and max
 * @param min : the minimum value
 * @param max : the maximum value
 * @return the random number
 */
int randomint(int min, int max);

#endif //DRAW_H
