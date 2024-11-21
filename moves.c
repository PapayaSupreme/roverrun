//
// Created by flasque on 19/10/2024.
//
#include "draw.h"
#include "moves.h"

#include <stdio.h>

#include "map.h"
#include "tree.h"

/* prototypes of local functions */
/* local functions are used only in this file, as helper functions */

/**
 * @brief Function to rotate the robot according to a move and its actual orientation
 * @param ori : the actual orientation of the robot
 * @param move : the move to do
 * @return the new orientation of the robot
 */
t_orientation rotate(t_orientation, t_move );

/**
 * @brief function to translate the robot according to a move and its actual position
 * @param loc : the actual localisation of the robot
 * @param move : the move to do
 * @return the new localisation of the robot
 */
t_localisation translate(t_localisation , t_move);

/* definition of local functions */

t_orientation rotate(t_orientation ori, t_move move)
{
    int rst;
    switch (move)
    {
        case T_LEFT:
            rst=3;
            break;
        case T_RIGHT:
            rst=1;
            break;
        case U_TURN:
            rst=2;
            break;
        default:
            break;
    }
    return (ori+rst)%4;
}

t_localisation translate(t_localisation loc, t_move move)
{
    /** rules for coordinates:
     *  - x grows to the right with step of +1
     *  - y grows to the bottom with step of +1
     *  - the origin (x=0, y=0) is at the top left corner
     */
    t_position res = loc.pos;
    switch (move) {
        case F_10:
            switch (loc.ori) {
                case NORTH:
                    res.y = loc.pos.y - 1;
                    break;
                case EAST:
                    res.x = loc.pos.x + 1;
                    break;
                case SOUTH:
                    res.y = loc.pos.y + 1;
                    break;
                case WEST:
                    res.x = loc.pos.x - 1;
                    break;
                default:
                    break;
            }
            break;
        case F_20:
            switch (loc.ori) {
                case NORTH:
                    res.y = loc.pos.y - 2;
                    break;
                case EAST:
                    res.x = loc.pos.x + 2;
                    break;
                case SOUTH:
                    res.y = loc.pos.y + 2;
                    break;
                case WEST:
                    res.x = loc.pos.x - 2;
                    break;
                default:
                    break;
            }
            break;
        case F_30:
            switch (loc.ori) {
                case NORTH:
                    res.y = loc.pos.y - 3;
                    break;
                case EAST:
                    res.x = loc.pos.x + 3;
                    break;
                case SOUTH:
                    res.y = loc.pos.y + 3;
                    break;
                case WEST:
                    res.x = loc.pos.x - 3;
                    break;
                default:
                    break;
            }
            break;
        case B_10:
            switch (loc.ori) {
                case NORTH:
                    res.y = loc.pos.y + 1;
                    break;
                case EAST:
                    res.x = loc.pos.x - 1;
                    break;
                case SOUTH:
                    res.y = loc.pos.y - 1;
                    break;
                case WEST:
                    res.x = loc.pos.x + 1;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
        return loc_init(res.x, res.y, loc.ori);

}

/* definitions of exported functions */

char *getMoveAsString(t_move move)
{
    return _moves[move];
}

t_localisation move(t_localisation loc, t_move move)
{
    t_localisation new_loc;
    new_loc.ori = rotate(loc.ori, move);
    new_loc = translate(loc, move);
    return new_loc;
}

void updateLocalisation(t_localisation *p_loc, t_move m)
{
    *p_loc = move(*p_loc, m);
    return;
}

// function moveInTree will use draw9Moves() to fill in  the first level of the tree with a move in each node. Then, fills the second level with every move left for each of the sons of the 9 fathers
t_node *moveIntree()
{
    //first, call draw9Moves
    char *moves = draw9Moves();
    //print the moves
    for (int i = 0; i < 9; i++)
    {
        printf("%s ", getMoveAsString(moves[i]));
    }
    //create the tree
    t_node *root = createTree();
    //fill the first level
    for (int i = 0; i < 9; i++)
    {
        root->sons[i]->value = moves[i];   //[9] 1st floor
        int skippedJ = 0;
        for (int j = 0; j<9;j++) {
            //fill the 2nd level with the moves left
            if (j!=i)
            {
                root->sons[i]->sons[j-skippedJ]->value = moves[j];  //[8] 2nd floor
                //fill the 3rd level with the moves left
                int skippedK = 0;
                for (int k = 0;k<9;k++) {
                    if (k!=i && k!=j) {
                        root->sons[i]->sons[j-skippedJ]->sons[k-skippedK]->value = moves[k];  //[7] 3rd floor
                        int skippedL = 0;
                        for (int l = 0;l<9;l++) {
                            if (l!=i && l!=j && l!=k) {
                                root->sons[i]->sons[j-skippedJ]->sons[k-skippedK]->sons[l-skippedL]->value = moves[l];  //[6] 4th floor
                                int skippedM = 0;
                                //fill the 5th level with the moves left, last level
                                for (int m = 0;m<9;m++) {
                                    if (m!=i && m!=j && m!=k && m!=l) {
                                        root->sons[i]->sons[j-skippedJ]->sons[k-skippedK]->sons[l-skippedL]->sons[m-skippedM]->value = moves[m];  //[5] 5th floor
                                    }
                                    else {
                                        skippedM++;
                                    }
                                }
                            }
                            else {
                                skippedL++;
                            }
                        }
                    }
                    else {
                        skippedK++;
                    }

                }
            }
            else {
                skippedJ++;
            }
        }
    }
    return root;
}

int cost(t_localisation loc,t_map map)
{
    if (isValidLocalisation(loc.pos, 6, 7)){
        return map.costs[loc.pos.y][loc.pos.x];
    }
    return -1 ;
}

/*void computeCostInTree(t_node *root, t_map map, t_localisation loc)
{
    //check if the node is a leaf
    if (checkNode(root) == 0)
    {
        //update the localisation
        t_localisation new_loc = move(loc, root->value);
        //update the cost : actual cost of the move(value of the node) + cost of the new position
        root->value = cost(new_loc, map);
    }
    else
    {
        //recursive call on the sons
        for (int i = 0; i < root->nbSons; i++)
        {
            computeCostInTree(root->sons[i], map, loc);
        }
    }
    return;
}
*/

//compute every cost of moves thnaks to calculatenode
void fillTreeWithCost(t_node *root, t_map map, t_localisation loc)
{
    //check if the node is a leaf
    if (checkNode(root) == 0)
    {
        //update the cost : actual cost of the move(value of the node) + cost of the new position
        root->value = calculate_node(root->value, loc, map, 1)+100; // DOESNT WORK AT ALL 
    }
    else
    {
        //recursive call on the sons
        for (int i = 0; i < root->nbSons; i++)
        {
            fillTreeWithCost(root->sons[i], map, loc);
        }
    }
}

int calculate_node(int nodevalue, t_localisation localisation, t_map map, int size) {
    t_localisation newloc = localisation;
    for (int i = 0; i < size; i++) {
        switch(nodevalue) {
            case 0: newloc = translate(newloc, F_10); break;
            case 1: newloc = translate(newloc, F_20); break;
            case 2: newloc = translate(newloc, F_30); break;
            case 3: newloc = translate(newloc, B_10); break;
            case 4: newloc.ori = rotate(newloc.ori, T_RIGHT); break;
            case 5: newloc.ori = rotate(newloc.ori, T_LEFT); break;
            case 6: newloc.ori = rotate(newloc.ori, U_TURN); break;
            default: break;
        }
    }
    if (isValidLocalisation(newloc.pos, map.x_max, map.y_max)) {
        return -1;
    }

    int cost = map.costs[newloc.pos.y][newloc.pos.x];
    printf("Position: (%d, %d), Orientation %d\n", newloc.pos.x, newloc.pos.y, newloc.ori);
    return cost;
}

int checkMove(t_localisation loc, t_map map, t_move move)
{
    //if cost is>10000, it's a crevasse
    if (cost(loc, map) > 10000)
    {
        return 0;
    }
    //if cost is 0, it's the base station
    if (cost(loc, map) == 0)
    {
        return 2;
    }
    //if the destination is an erg
    if (map.soils[translate(loc, move).pos.y][translate(loc, move).pos.x] == ERG)
    {
        return 3;
    }
    //if the destination is a reg
    if (map.soils[translate(loc, move).pos.y][translate(loc, move).pos.x] == REG)
    {
        return 4;
    }
    return 1;
}
