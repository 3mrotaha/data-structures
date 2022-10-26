#ifndef _TREE_PRIVATE_
#define _TREE_PRIVATE_
#include "config.h"

typedef int KeyType;

typedef struct treenode{
    KeyType key;
    TreeEntry_t Item;
    struct treenode *right, *left;
}TreeNode_t;

typedef TreeNode_t* InformalTree_t;

typedef struct Tree{
    TreeNode_t* root;
    int size, depth;
}Tree_t;

static inline void ClearTreeAux(InformalTree_t*);

static inline void InsertAux(InformalTree_t*, TreeEntry_t, int*);

#endif