#ifndef TREE
#define TREE

#ifndef BOOLEAN
#define BOOLEAN
    #define FALSE 0
    #define TRUE !FALSE
#endif

#define BREAK -1

typedef struct TreeNode
{
    struct TreeNode *left;
    struct TreeNode *right;
    int key;
    void *data;
} TreeNode;

typedef struct Tree
{
    TreeNode *root;
    int count;
} Tree;

typedef void(*listFunc)(void *);

Tree* createTree();
void insert( Tree*, int, void* );
TreeNode* insertRec( Tree*, TreeNode*, TreeNode* );
void preOrder( Tree* );
void preOrderRec( TreeNode* );
void postOrder( Tree* );
void postOrderRec( TreeNode* );
void inOrder( Tree* );
void inOrderRec( TreeNode* );
void freeTree( Tree* );
void freeTreeRec( TreeNode* );
void removeAt( Tree*, int );
TreeNode* max( TreeNode* );
TreeNode* maxRec( TreeNode* );
TreeNode* removeRec( Tree*, TreeNode*, int );
TreeNode* removeNode( Tree*, TreeNode* );
TreeNode* findNode( Tree*, int );
TreeNode* findNodeRec( TreeNode*, int, int );
TreeNode* promoteSuccessor( TreeNode* );
TreeNode* findSuccessorRec( TreeNode* );
int isBalance( Tree* );
int level( TreeNode*, int, int );

#endif
