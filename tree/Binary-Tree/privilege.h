#ifndef _TREE_PRIVILEGES_
#define _TREE_PRIVILEGES_
#include "TreeError.h"
#include "private.h"

/*
pre: none
post: returns TREE_CREATED if a null pointer passed to it
      otherwise it returns TREE_IS_ALREADY_CREATED
*/
TreeError_t CreateTree(Tree_t*);

/*
pre: none
post: 
*/
TreeError_t ClearTree(Tree_t*);

TreeError_t TreeSize(Tree_t, int*);

TreeError_t TreeDepth(Tree_t, int*);

TreeError_t TreeEmpty(Tree_t);

TreeError_t InsertElement(Tree_t*, TreeEntry_t);

TreeError_t DeleteElements(Tree_t*, TreeEntry_t);

TreeError_t DeleteFirst(Tree_t*, TreeEntry_t);

TreeError_t DeleteItem(Tree_t*, KeyType, TreeEntry_t*);

TreeError_t FindElement(Tree_t, KeyType, TreeEntry_t*);

TreeError_t TraverseTree(Tree_t, void (*)(TreeEntry_t));

#endif 