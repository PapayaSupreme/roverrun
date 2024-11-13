//
// Created by pablo on 11/13/2024.
//

#ifndef TREE_H
#define TREE_H
typedef struct Node {
    int value;
    int nbSons;
    struct Node** sons;
} t_node;

/**
 * @brief function to create a node
 * @param val : the value of the node
 * @param nb_sons : the number of sons of the node
 * @return the node
 */
t_node *createNode(int val, int nb_sons);

/**
 * @brief function to create a tree with 9 nodes at the first level, 8 at the second, 7 at the third,
 * etc until it stops at level 5 with a total of 18730 nodes
 * values are for now increasing by 1 from 0 to 18730 (1 + 9 +9*8 +9*8*7+9*8*7*6+9*8*7*6*5 nodes)
 * @return the root of the tree
 */
t_node *createTree();

/**
 * @brief function to print the values of every node of a tree of depth 5 by level
 */
void printTree(t_node *root);

#endif //TREE_H
