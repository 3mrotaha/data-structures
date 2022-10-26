#include <stdio.h>
#include <stdlib.h>
#include "TreeError.h"
#include "private.h"

TreeError_t CreateTree(Tree_t* pTree){
    if(pTree){
        pTree->root = NULL;
        pTree->depth = pTree->size = 0;
        return TREE_CREATED;        
    }
    return TREE_IS_ALREADY_CREATED;
}

TreeError_t ClearTree(Tree_t* pTree){
    if(pTree){
        ClearTreeAux(&pTree->root);
        pTree->root = NULL;
        pTree->depth = pTree->size = 0;
        return TREE_CLEARED;
    }
    return TREE_IS_ALREADY_CLEARED;
}

TreeError_t TreeSize(Tree_t tree, int* size){
    if(tree.root){
        *size = tree.size;
        return TREE_NOT_EMPTY;
    }
    *size = 0;
    return TREE_EMPTY;
}

TreeError_t TreeDepth(Tree_t tree, int* depth){
    if(tree.root){
        *depth = tree.depth;
        return TREE_NOT_EMPTY;
    }
    *depth = 0;
    return TREE_EMPTY;
}

TreeError_t TreeEmpty(Tree_t tree){
    if(tree.root != NULL)
        return TREE_EMPTY;
    else
        return TREE_NOT_EMPTY;
}

TreeError_t InsertElement(Tree_t* pTree, TreeEntry_t entry){
    int dep = 0;
    InsertAux(&pTree->root, entry, &dep);
    pTree->size++;
    if(dep > pTree->depth){
        pTree->depth = dep;
    }
    return ELEMENT_INSERTED;
}

TreeError_t DeleteElements(Tree_t*, TreeEntry_t);

TreeError_t DeleteFirst(Tree_t*, TreeEntry_t);

TreeError_t DeleteItem(Tree_t*, KeyType, TreeEntry_t*);

TreeError_t FindElement(Tree_t, KeyType, TreeEntry_t*);

TreeError_t TraverseTree(Tree_t, void (*)(TreeEntry_t));

static inline void ClearTreeAux(InformalTree_t* pTree){
    if((*pTree)){
        ClearTreeAux(&(*pTree)->left);
        ClearTreeAux(&(*pTree)->right);
        free((*pTree));
    }
}


static inline void InsertAux(InformalTree_t* pTree, TreeEntry_t entry, int* depth){
    if(!(*pTree)){
        *pTree = (InformalTree_t) malloc(sizeof(TreeNode_t));
        (*pTree)->left = (*pTree)->right = NULL;                
    }
    else if((*pTree)->Item < entry)
        InsertAux(&(*pTree)->left, entry, depth);
    else
        InsertAux(&(*pTree)->right, entry, depth);
    (*depth)++;
}

