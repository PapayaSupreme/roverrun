//
// Created by pablo on 11/13/2024.
//

#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
t_node *createNode(int val, int nb_sons)
{
    t_node *new_node;
    new_node = (t_node *)malloc(sizeof(t_node));
    new_node->value = val;
    new_node->nbSons = nb_sons;
    new_node->sons = (t_node **)malloc(nb_sons*sizeof(t_node *));
    for (int i=0; i <nb_sons; i++)
    {
        new_node->sons[i]=NULL;
    }
    return new_node;
}

// create function to make a tree with 9 nodes at the first level, 8 at the second, 7 at the third,
// etc until it stops at level 5 with a total of 18730 nodes
// values are for now increasing by 1 from 0 to 18730 (1 + 9 +9*8 +9*8*7+9*8*7*6+9*8*7*6*5 nodes)
t_node *createTree()
{
    t_node *root = createNode(-1, 9);
    for (int i = 0; i < 9; i++)
    {
        root->sons[i] = createNode(i +10000, 8);
        for (int j = 0; j < 8; j++)
        {
            root->sons[i]->sons[j] = createNode(j+1000, 7);
            for (int k = 0; k < 7; k++)
            {
                root->sons[i]->sons[j]->sons[k] = createNode(100+ k, 6);
                for (int l = 0; l < 6; l++)
                {
                    root->sons[i]->sons[j]->sons[k]->sons[l] = createNode( 10+ l, 5);
                    for (int m = 0; m < 5; m++)
                    {
                        root->sons[i]->sons[j]->sons[k]->sons[l]->sons[m] = createNode(  1+ m, 0);
                    }
                }
            }
        }
    }
    return root;
}

// fct to print the values of every node of a tree of depth 5 by level
void printTree(t_node *root)
{
    printf("Root value : %d\n", root->value);
    for (int i = 0; i < 9; i++)
    {
        printf("First level son %d value : %d\n", i, root->sons[i]->value);
        for (int j = 0; j < 8; j++)
        {
            printf("Second level son %d value : %d\n", j, root->sons[i]->sons[j]->value);
            for (int k = 0; k < 7; k++)
            {
                printf("Third level son %d value : %d\n", k, root->sons[i]->sons[j]->sons[k]->value);
                for (int l = 0; l < 6; l++)
                {
                    printf("Fourth level son %d value : %d\n", l, root->sons[i]->sons[j]->sons[k]->sons[l]->value);
                    for (int m = 0; m < 5; m++)
                    {
                        printf("Fifth level son %d value : %d\n", m, root->sons[i]->sons[j]->sons[k]->sons[l]->sons[m]->value);
                    }
                }
            }
        }
    }
}

//return 0 if value>=10000, 2 if this node as the root as father,
//3 if this node is on the last level, 1 otherwise
int checkNode(t_node *root)
{
    if (root->value >= 10000)
    {
        return 0;
    }
    if (root->value == -1)
    {
        return 2;
    }
    if (root->nbSons == 0)
    {
        return 3;
    }
    return 1;
}

// FjiozrmjoremjjbjmtenjbkomtrnjkblmngtkrmnbjkmenbrmnzkblmrenklbmnerklmbnkrelmnbklremnbkrleUUIDOFekjzlbvjkrzelbvjlerbvjklebrhjkvlbrejlvbrkelbvjkrelbvjklrebjvklbejklv
// Function to calculate the height of the tree
int getHeight(t_node* root) {
    if (root == NULL)
        return 0;

    int maxHeight = 0;
    for (int i = 0; i < root->nbSons; i++) {
        int childHeight = getHeight(root->sons[i]);
        if (childHeight > maxHeight)
            maxHeight = childHeight;
    }

    return maxHeight + 1;
}

// Function to print all nodes at a given level
void printLevel(t_node* root, int level) {
    if (root == NULL) {
        //print new line
        printf("\n ");
        return;
    }
    if (level == 1) {
        printf("%d ", root->value);
    } else {
        for (int i = 0; i < root->nbSons; i++) {
            printLevel(root->sons[i], level - 1);
        }
    }
}

// Function to print the tree layer by layer
void printTreeLayerByLayer(t_node* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    int height = getHeight(root);

    for (int i = 1; i <= height; i++) {
        printLevel(root, i);
        printf("\n");
    }
}

int* lightestBranch(t_node* root) {
    if (root == NULL) {
        return NULL;
    }
    int height = getHeight(root);
    int* path = (int*)malloc(height * sizeof(int));
    path[0] = root->value;

    t_node* current = root;
    for (int i = 1; i < height; i++) {
        int min = 10000;
        int index = 0;
        for (int j = 0; j < current->nbSons; j++) {
            if (current->sons[j]->value < min) {
                min = current->sons[j]->value;
                index = j;
            }
        }
        current = current->sons[index];
        path[i] = current->value;
    }
    return path;
}