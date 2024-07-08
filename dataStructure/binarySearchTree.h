#ifndef _BINARYSEARCHTREE_H_
    #define _BINARYSEARCHTREE_H_

    #include <stdio.h>
    #include <malloc.h>

    typedef struct _BinarySearchTree BSTree;
    typedef enum _EnumTraversalOrder EOrder;
    BSTree* newBSTree       ();
    int     delBSTree       (BSTree* pBSTree);
    int     traversalBSTree (BSTree* pBSTree, EOrder eOrder);
    int     searchBSTreeNode(BSTree* pBSTree, int nData);
    int     insertBSTreeNode(BSTree* pBSTree, int nData);
    int     deleteBSTreeNode(BSTree* pBSTree, int nData);

#endif