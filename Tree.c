#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"
#include "print.h"

Tree* createTree()
{
    Tree *tree = malloc(sizeof(Tree));
    tree->root = NULL;
    tree->count = 0;
    return tree;
}

void insert( Tree *tree, int inKey, void *inData )
{
    /* Creating the new Node */
    TreeNode *newNd = malloc(sizeof(TreeNode));

    /* Initialising all the value */
    newNd->left = NULL; newNd->right = NULL;
    newNd->key = inKey; newNd->data = inData;

    /* Assign back to root to get the pointer of all nodes and new node */
    tree->root = insertRec( tree, tree->root, newNd );

    tree->count++;
}

TreeNode* insertRec( Tree *tree, TreeNode *travelNd, TreeNode *newNd )
{
    /* Base case: travelNd = NULL */
    if( travelNd != NULL )
    {
        /* Key cannot be duplicated */
        if( newNd->key != travelNd->key )
        {
            /* If current key is smaller than inKey, Recurse to the right  */ 
            if( newNd->key > travelNd->key )
                travelNd->right = insertRec( tree, travelNd->right, newNd );
            else
                travelNd->left = insertRec( tree, travelNd->left, newNd );
        }
        else
        {
            printf("Key is already existed\n");
            free( newNd ); newNd = NULL;    /* Dont need that extra node */
        }
    }
    else
        travelNd = newNd;   /* Base case reached means we have found the position */

    return travelNd;
}

void removeAt( Tree *tree, int inKey )
{
    if( tree->root != NULL )
        tree->root = removeRec( tree, tree->root, inKey );
    else
        printf("Tree is empty\n");

    tree->count--;
}

TreeNode* removeRec( Tree *tree, TreeNode *removeNd, int inKey )
{
    TreeNode *updateNd = removeNd;

    /* Check whether Node existed */
    if( removeNd != NULL )         
    {
        if( removeNd->key < inKey )         /* Recurse right if key is smaller */
            removeNd->right = removeRec( tree, removeNd->right, inKey );
        else if( removeNd->key > inKey )    /* Recurse left if key is larger */
            removeNd->left = removeRec( tree, removeNd->left, inKey );
        else                                /* Otherwise the key is found */
            updateNd = removeNode( tree, removeNd );
    }
    else
        printf("Node does not exist\n");

    return updateNd;
}

TreeNode* removeNode( Tree *tree, TreeNode *removeNd )
{
    TreeNode *updateNd = NULL;

    if( removeNd->left == NULL && removeNd->right != NULL )
        updateNd = removeNd->right;         /* Right will replace current node */
    else if( removeNd->left != NULL && removeNd->right == NULL )
        updateNd = removeNd->left;          /* Left will replace current node */
    else if( removeNd->left != NULL && removeNd->right != NULL )
    {
        updateNd = promoteSuccessor( removeNd );

        if( removeNd->left != updateNd )    /* Check if the left node is the actual updateNd */
            updateNd->left = removeNd->left;    /* Obtain all the left childrens from removeNd */

        updateNd->right = removeNd->right;  /* Obtain all the right childrens from removeNd */
    }

    free( removeNd ); 
    removeNd = NULL;

    return updateNd;
}

TreeNode* promoteSuccessor( TreeNode *currNd )
{
    TreeNode *leftNd = currNd->left;        /* Finding the max from left sub-tree  */
    TreeNode *successor = NULL;

    successor = max( leftNd ); 

    return successor;
}

TreeNode* max( TreeNode *startNd )
{
    TreeNode *maxNd = NULL;

    if( startNd != NULL )
        maxNd = maxRec( startNd );

    return maxNd;
}

TreeNode* maxRec( TreeNode* maxNd )
{
    if( maxNd->right != NULL  && maxNd->key < maxNd->right->key )
        maxNd = maxRec( maxNd->right );

    return maxNd;
}

TreeNode* findNode( Tree *tree, int key )
{
    TreeNode *findNd = NULL;

    if( tree->root != NULL )
        findNd = findNodeRec( tree->root, key, FALSE );

    return findNd;
}

TreeNode* findNodeRec( TreeNode *findNd, int inKey, int found )
{
    if( findNd != NULL && found != TRUE )   /* Stop when node is found or reaches the end */
    {
        if( findNd->key > inKey )           /* Recurse left */
            findNd = findNodeRec( findNd->left, inKey, found );
        else if( findNd->key < inKey )      /* Recurse right */
            findNd = findNodeRec( findNd->right, inKey, found ); 
        else if( findNd->key == inKey )     /* Key found */
            found = TRUE;
    }
    else                                    /* Key does not exist since we get to NULL */ 
        printf("Key does not exist\n");
    
    return findNd;
}

TreeNode* maximumRec( TreeNode *maxNd )
{
    if( maxNd->key < maxNd->right->key )
        maxNd = maximumRec( maxNd->right );

    return maxNd;
}    

int isBalance( Tree* tree )
{
    int left = 0, right = 0, balance = FALSE;

    if( tree->root != NULL )
    {
        left = level( tree->root->left, 0, 0 );
        right = level( tree->root->right, 0, 0 );

        if( left == right )
            balance = TRUE;
    }
    else
        printf("Tree is empty\n");

    return balance;
}

int level( TreeNode *currNd, int currDepth, int lastDepth )
{
    if( currNd != NULL )
    {
        lastDepth = level( currNd->left, currDepth+1, lastDepth+1 );
        lastDepth = level( currNd->right, currDepth+1, lastDepth+1 );

        /* Update the depth if deeper node is encountered */
        if( currDepth > lastDepth )
            lastDepth = currDepth;
    }
    else
        --lastDepth;    /* Revert back as there are no tree node */

    return lastDepth;
}

void preOrder( Tree *tree )
{
    if( tree->root != NULL )
        preOrderRec( tree->root );
}

void preOrderRec( TreeNode *travelNd )
{
    if( travelNd != NULL )
    {
        printInteger( travelNd->data );
        preOrderRec( travelNd->left );
        preOrderRec( travelNd->right );
    }
}

void postOrder( Tree *tree )
{
    if( tree->root != NULL )
        postOrderRec( tree->root );
}

void postOrderRec( TreeNode *travelNd )
{
    if( travelNd != NULL )
    {
        postOrderRec( travelNd->left );
        postOrderRec( travelNd->right );
        printInteger( travelNd->data );
    }
}

void inOrder( Tree *tree )
{
    if( tree->root != NULL )
        inOrderRec( tree->root );
}

void inOrderRec( TreeNode *travelNd )
{
    if( travelNd != NULL )
    {
        inOrderRec( travelNd->left );
        printInteger( travelNd->data );
        inOrderRec( travelNd->right );
    }
}

void freeTree( Tree *tree )
{
    if( tree->root != NULL )
    {
        freeTreeRec( tree->root );
        free( tree ); tree = NULL;
    }
}

void freeTreeRec( TreeNode *freeNd )
{
    if( freeNd != NULL )
    {
        freeTreeRec( freeNd->left );
        freeTreeRec( freeNd->right );
        free( freeNd ); freeNd = NULL;
    }
}
