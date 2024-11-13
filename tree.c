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
    t_node *root = createNode(0, 9);
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
                        root->sons[i]->sons[j]->sons[k]->sons[l]->sons[m] = createNode(  1+ m, 4);
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