#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "draw.h"
#include <time.h>
#include "loc.h"
#include "moves.h"
#include "tree.h"
int main() {
    srand((unsigned)(time(NULL)));  // seed the random number generator
    t_map map = createMapFromFile("..\\maps\\example1.map");
    printf("Map created with dimensions %d x %d\n", map.y_max, map.x_max);
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
    displayMap(map);
    /*
    //test draw9moves from draw.c
    char* moves = draw9Moves();
    for (int i = 0; i < 9; i++)
    {
        printf("%c ", moves[i]);
    }
    */

    //test moveIntree from moves.c3
    t_node *root2 = moveIntree();

    //test getMoveAsString from moves.c

    printf("%s\n", getMoveAsString(F_10));
    //test move from moves.c
    t_localisation loc = loc_init(3, 3, NORTH);
    //printf("New position : x = %d, y = %d, orientation = %d\n", new_loc.pos.x, new_loc.pos.y, new_loc.ori);
    //test computeCostInTree from moves.c
    //computeCostInTree(root2, map, loc);
    //print the tree by level and tests the depending fucntion at the same time LOL
    //test calculate_node and printTreeWithCosts from moves.c
    fillTreeWithCost(root2, map, loc);
    printTreeLayerByLayer(root2);
    // print costs of the actual position
    //printf("Cost of the move : %d\n", cost(loc, map));
    //test cost from moves.c
    printf("Cost of the move : %d\n", cost(loc, map));

    return 0;
}
