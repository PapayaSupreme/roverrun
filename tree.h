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

/**
 * @brief function to check if a node is a leaf, a root or a node in the middle
 * @param root : the node to check
 * @return 0 if value>=10000, 2 if this node as the root as father,
 * 3 if this node is on the last level, 1 otherwise
 */
int checkNode(t_node *root);

/**
 * @brief function to calculate the height of the tree
 * @param root : the root of the tree
 * @return the height of the tree
 */
int getHeight(t_node* root);

/**
 * @brief function to print all nodes at a given level
 * @param root : the root of the tree
 * @param level : the level to print
 */
void printLevel(t_node* root, int level);

/**
 * @brief prints the tree layer by layers
 * @param root : the root of the tree
 */
void printTreeLayerByLayer(t_node* root);

// function to compute the lightest branch of the tree, returns its path in a simple list
int* lightestBranch(t_node* root);

#endif //TREE_H
