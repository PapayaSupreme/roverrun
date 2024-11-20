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

    //test moveIntree from moves.c
    t_node *root2 = moveIntree();
    //print the tree by level and tests the depending fucntion at the same time LOL
    printTreeLayerByLayer(root2);
    return 0;
}
