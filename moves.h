//
// Created by flasque on 19/10/2024.
//

#ifndef UNTITLED1_MOVES_H
#define UNTITLED1_MOVES_H

#include "loc.h"
#include "tree.h"
#include "map.h"
/**
 * @brief Array of strings for the possible moves of the robot
 */
static char _moves[8][8] = {"F 10m", "F 20m", "F 30m", "B 10m", "T left", "T right", "U-turn"};

/**
 * @brief Enum for the possible moves of the robot
 */

typedef enum e_move
{
    F_10, // Forward 10 m
    F_20, // Forward 20 m
    F_30, // Forward 30 m
    B_10, // Backward 10 m
    T_LEFT, // Turn left (+90°)
    T_RIGHT, // Turn right (-90°)
    U_TURN
} t_move;

/**
 * @brief function to get a t_move as a string
 * @param move : the move to convert
 * @return the string corresponding to the move
 */
char *getMoveAsString(t_move move);

/**
 * @brief function to update the localisation of the robot according to a move
 * @param loc : the localisation of the robot
 * @param move : the move to do
 * @return the new localisation of the robot
 */
t_localisation move(t_localisation, t_move);

/**
 * @brief wrapper function to update a single location
 * @param p_loc : the pointer to the localisation of the robot
 * @param move : the move to do
 * @return none
 */
void updateLocalisation(t_localisation *, t_move);

/**
 * @brief function to assignate all the possibilities of a drawXMoves draw to a tree
 * @param x : the number of moves to draw
 * @return the adress of the root of the tree
 */
t_node *moveIntree(int x);

int cost(t_localisation loc,t_map map);

// function to fill the tree with the moves costs DOESNT ORK YETDOESNT ORK YET
void computeCostInTree(t_node *root, t_map map, t_localisation loc);

/**
 *
 * @param loc : location of the robot
 * @param map : the map
 * @param move : the move, e.g. to know where the robot will land
 * @return : 2 : base station, 3 : erg, 4 : reg, 0 : crevasse, 1 : plain
 */
int checkMove(t_localisation loc, t_map map, t_move move);

/**
 * @brief function to check if a move is possible
 * @param root : the node to check
 * @param loc : the location of the robot
 * @param map : the map
 * @return 0 default, -1 for turn debuff of reg
 */
int checkNode4checkMove(t_node *root, t_localisation loc, t_map map);



#endif //UNTITLED1_MOVES_H
