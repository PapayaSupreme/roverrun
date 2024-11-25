#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include <time.h>

#include "draw.h"
#include "loc.h"
#include "moves.h"
#include "tree.h"
int main() {
    srand((unsigned)(time(NULL)));  // seed the random number generator

    //setup maps and test createMap from map.c
    t_map map = createMapFromFile("..\\maps\\example1.map");
    //printf("Map created with dimensions %d x %d\n", map.y_max, map.x_max);

    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%d ", map.soils[i][j]);
        }
        printf("\n");
    }

    // printf the costs, aligned left 5 digits
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%-5d ", map.costs[i][j]);
        }
        printf("\n");
    }

    // test displayMap
    displayMap(map);

    int x = 9; // number of moves to draw to account for reg debuff, 9 default
    /*
    //test drawXmoves from draw.c
    char* moves = drawXMoves(x);
    for (int i = 0; i < 9; i++)
    {
        printf("%c ", moves[i]);
    }
    */
    //mesure the time it takes for all the functions to run
    clock_t start, end;
    start = clock();

    //test moveIntree from moves.c3
    t_node *root2 = moveIntree(x);

    //test getMoveAsString from moves.c
    //printf("%s\n", getMoveAsString(F_10));

    //test move from moves.c
    t_localisation loc = loc_init(3, 3, NORTH);
    //printf("New position : x = %d, y = %d, orientation = %d\n", new_loc.pos.x, new_loc.pos.y, new_loc.ori);

    //test computeCostInTree from moves.c
    computeCostInTree(root2, map, loc, x);

    //print the tree by level and tests the depending fucntion at the same time LOL
    //printTreeLayerByLayer(root2);

    //test cost from moves.c
    //printf("Cost of the move : %d\n", cost(loc, map));

    //test lightestBranch from tree.c
    int *branch = lightestBranch(root2);
    for (int i = 1; i < 6; i++)
    {
        printf("%d ", branch[i]);
    }
    //end the timer
    end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken : %f\n", cpu_time_used);
    return 0;
}
