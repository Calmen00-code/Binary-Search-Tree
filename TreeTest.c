#include <stdio.h>
#include "Tree.h"
#define GRN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

int main()
{
    Tree *tree = createTree();
    TreeNode *findNd = NULL;
    TreeNode *maxNd = NULL, *startNd = NULL;
    int a = 50, b = 16, c = 7, d = 89, e = 70;
    int f = 45, g = 10, h = 66, i = 95;
    int A = 1, B = 2, C = 3, D = 4, E = 5, F = 6, G = 7; 

/* ------------------------------------------------------------------------------------*/

    printf("==============================================\n");
    printf("TEST Insert\n\n");

    printf("Normal Insert: ");
    insert( tree, 50, &a );
    insert( tree, 16, &b );
    insert( tree, 7, &c );
    insert( tree, 89, &d );
    insert( tree, 70, &e );
    insert( tree, 45, &f );
    insert( tree, 10, &g );
    insert( tree, 66, &h );
    insert( tree, 95, &i );

    if( tree->count == 9 )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    printf("Insert Existing: ");
    insert( tree, 95, &i );

    printf("\n");
/* ------------------------------------------------------------------------------------*/

    printf("==============================================\n");
    printf("TEST Find\n\n");

    printf("Normal Find: ");
    findNd = findNode( tree, 50 );
    if( findNd->key == 50 ) 
    {
        findNd = findNode( tree, 16 );
        if( findNd->key == 16 ) {
            findNd = findNode( tree, 7 );
            if( findNd->key == 7 ) {
                findNd = findNode( tree, 10 );
                if( findNd->key == 10 ) {
                    findNd = findNode( tree, 66 );
                    if( findNd->key == 66 ) {
                        findNd = findNode( tree, 95 );
                        if( findNd->key == 95 ) 
                            printf("%sPASSED%s\n", GRN, RESET);
                    }
                }
            }
        }
    }
    else
        printf("%sFAILED%s\n", RED, RESET);

    printf("Invalid Key: ");
    findNode( tree, 500 );
 
    printf("\n");
/* ------------------------------------------------------------------------------------*/

    printf("==============================================\n");
    printf("TEST max\n");

    /* Get the visualisation of the tree first */

    /* From Root */
    printf("Root Level: ");
    startNd = findNode( tree, 95 );   /* Return the node using the key */
    maxNd = max( startNd );
    if( maxNd->key == 95 )
        printf("%sPASSED%s\n\n", GRN, RESET);
    else
        printf("%sFAILED%s\n\n", RED, RESET);

    /* From Left Subtree: Level 1 */
    printf("Level 1 (Left): ");
    startNd = findNode( tree, 45 );   /* Return the node using the key */
    maxNd = max( startNd );
    if( maxNd->key == 45 )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    /* From Right Subtree: Level 1 */
    printf("Level 1 (Right): ");
    startNd = findNode( tree, 95 );   /* Return the node using the key */
    maxNd = max( startNd );
    if( maxNd->key == 95 )
        printf("%sPASSED%s\n\n", GRN, RESET);
    else
        printf("%sFAILED%s\n\n", RED, RESET);

    /* From Left Subtree: Level 2 */ 
    printf("Level 2 (Left): ");
    startNd = findNode( tree, 10 );   /* Return the node using the key */
    maxNd = max( startNd );
    if( maxNd->key == 10 )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    printf("Level 2 (Left): ");
    startNd = findNode( tree, 45 );   /* Return the node using the key */
    maxNd = max( startNd );
    if( maxNd->key == 45 )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    /* From Right Subtree: Level 2 */
    printf("Level 2 (Right): ");
    startNd = findNode( tree, 70 );   /* Return the node using the key */
    maxNd = max( startNd );
    if( maxNd->key == 70 )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    printf("Level 2 (Right): ");
    startNd = findNode( tree, 95 );   /* Return the node using the key */
    maxNd = max( startNd );
    if( maxNd->key == 95 )
        printf("%sPASSED%s\n\n", GRN, RESET);
    else
        printf("%sFAILED%s\n\n", RED, RESET);

    /* From Left Subtree: Level 3 */
    printf("Level 3 (Left): ");
    startNd = findNode( tree, 10 );   /* Return the node using the key */
    maxNd = max( startNd );
    if( maxNd->key == 10 )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    printf("Level 3 (Left): ");
    startNd = findNode( tree, 66 );   /* Return the node using the key */
    maxNd = max( startNd );
    if( maxNd->key == 66 )
        printf("%sPASSED%s\n\n", GRN, RESET);
    else
        printf("%sFAILED%s\n\n", RED, RESET);    

    printf("==============================================\n\n");
    printf("Remove 66:\t");
    removeAt( tree, 66 );
    preOrder( tree ); printf("\n");

    insert( tree, 66, &h );
    printf("Remove 89:\t");
    removeAt( tree, 89 );
    preOrder( tree ); printf("\n");

    printf("Remove 70:\t");
    removeAt( tree, 70 );
    preOrder( tree ); printf("\n");

    printf("Remove 7:\t");
    removeAt( tree, 7 );
    preOrder( tree ); printf("\n");

    printf("Remove 16:\t");
    removeAt( tree, 16 );
    preOrder( tree ); printf("\n");

    printf("Remove 10:\t");
    removeAt( tree, 10 );
    preOrder( tree ); printf("\n");

    printf("Remove 50:\t");
    removeAt( tree, 50 );
    preOrder( tree ); printf("\n");

    printf("Remove 66:\t");
    removeAt( tree, 66 );
    preOrder( tree ); printf("\n");

    printf("Remove 95:\t");
    removeAt( tree, 95 );
    preOrder( tree ); printf("\n");

    printf("Remove 45:\t");
    removeAt( tree, 45 );
    preOrder( tree ); printf("\n");

    printf("Remove None:\t");
    removeAt( tree, 45 );
    preOrder( tree );

    printf("Count: ");
    if( tree->count == 0 )
        printf("\t\t%sPASSED%s\n\n", GRN, RESET);
    else
        printf("%sFAILED%s\n\n", RED, RESET);

    printf("\n");

/* ------------------------------------------------------------------------------------*/

    printf("==============================================\n\n");

    insert( tree, 'D', &D );    /* 4 */
    insert( tree, 'B', &B );    /* 2 */
    insert( tree, 'A', &A );    /* 1 */
    insert( tree, 'C', &C );    /* 3 */
    insert( tree, 'F', &F );    /* 6 */
    insert( tree, 'E', &E );    /* 5 */
    insert( tree, 'G', &G );    /* 7 */
    
    printf("Pre-Order: ");
    preOrder(tree); printf("\n");

    printf("Post-Order: ");
    postOrder(tree); printf("\n");

    printf("In-Order: ");
    inOrder(tree); printf("\n");

    freeTree( tree );

/* ------------------------------------------------------------------------------------*/

    printf("==============================================\n\n");
    tree = createTree();
    printf("Balance 1: ");

    insert( tree, 50, &a );
    insert( tree, 16, &b );
    insert( tree, 7, &c );
    insert( tree, 89, &d );
    insert( tree, 70, &e );
    insert( tree, 45, &f );
    insert( tree, 10, &g );
    insert( tree, 66, &h );
    insert( tree, 95, &i );

    if( isBalance( tree ) == TRUE )
        printf("\t%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);
        
    freeTree( tree );

    tree = createTree();

    printf("Balance 2: ");
    insert( tree, 50, &a );
    insert( tree, 16, &b );
    insert( tree, 89, &d );
    insert( tree, 7, &c );
    insert( tree, 95, &i );

    if( isBalance( tree ) == TRUE )
        printf("\t%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);
    
    freeTree( tree );

    tree = createTree();

    printf("Unbalance: ");
    insert( tree, 50, &a );
    insert( tree, 16, &b );
    insert( tree, 89, &d );
    insert( tree, 7, &c );
 
    if( isBalance( tree ) == FALSE )
        printf("\t%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    freeTree( tree );
      
    return 0;
}
