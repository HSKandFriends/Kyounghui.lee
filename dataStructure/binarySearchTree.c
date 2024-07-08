#include "binarySearchTree.h"

typedef enum { FALSE, TRUE } bool;
/////////////////////////////////////////////////////////////////
typedef struct _TreeNode TNode;
struct _TreeNode{
    TNode*  pLeft;
    TNode*  pRight;
    int     nData;
};
TNode* _newTreeNode(){
    TNode* pNode = (TNode*)malloc(sizeof(TNode));
    pNode->pLeft = NULL;
    pNode->pRight = NULL;
    pNode->nData = 0;
    return pNode;
}
int _delTreeNode(TNode* pNode){
    free(pNode);
    pNode = NULL;
    return 0;
}
/////////////////////////////////////////////////////////////////
struct _BinarySearchTree{
    TNode*  pRoot;
    int     nSize;
};
enum _EnumTraversalOrder{
    PREORDER,
    INORDER,
    POSTORDER
};
BSTree* newBSTree(){
    BSTree* pBSTree = (BSTree*)malloc(sizeof(BSTree));
    pBSTree->pRoot = NULL;
    pBSTree->nSize = 0;
    return pBSTree;
}
int _delTraversalTNode(TNode* pNode){
    if(pNode->pLeft){
        _delTraversalTNode(pNode->pLeft);
    }
    if(pNode->pRight){
        _delTraversalTNode(pNode->pRight);
    }
    free(pNode);
    pNode = NULL;
    return 0;
}
int delBSTree(BSTree* pBSTree){
    _delTraversalTNode(pBSTree->pRoot);
    free(pBSTree);
    pBSTree = NULL;
    return 0;
}
int _inorderTraversalTNode(TNode* pNode){
    if(pNode->pLeft){
        _inorderTraversalTNode(pNode->pLeft);
    }
    printf("%d ", pNode->nData);
    if(pNode->pRight){
        _inorderTraversalTNode(pNode->pRight);
    }
    return 0;
}
int _preorderTraversalTNode(TNode* pNode){
    printf("%d ", pNode->nData);
    if(pNode->pLeft){
        _preorderTraversalTNode(pNode->pLeft);
    }
    if(pNode->pRight){
        _preorderTraversalTNode(pNode->pRight);
    }
    return 0;
}
int _postorderTraversalTNode(TNode* pNode){
    if(pNode->pLeft){
        _postorderTraversalTNode(pNode->pLeft);
    }
    if(pNode->pRight){
        _postorderTraversalTNode(pNode->pRight);
    }
    printf("%d ", pNode->nData);
    return 0;
}
int traversalBSTree(BSTree* pBSTree, EOrder eOrder){
    if(pBSTree->nSize){
        TNode* pNode = pBSTree->pRoot;
        printf("[");
        switch (eOrder){
        case INORDER:
            _inorderTraversalTNode(pNode);
            break;
        case PREORDER:
            _preorderTraversalTNode(pNode);
            break;
        case POSTORDER:
            _postorderTraversalTNode(pNode);
            break;
        default:
            _inorderTraversalTNode(pNode);
            break;
        }
        printf("\b]\n");
        return 0;
    }
    printf("Empty Tree.\n");
    return 0;
}
int searchBSTreeNode(BSTree* pBSTree, int nData){
    if(pBSTree->nSize){
        TNode* pNode = pBSTree->pRoot;
        do{
            if(pNode->nData==nData){
                return 1;
            } else if(pNode->nData>nData){
                pNode = pNode->pLeft;
            } else {
                pNode = pNode->pRight;
            }
        } while(pNode);
        return 0;
    }
    printf("Empty Tree.\n");
    return 0;
}
int insertBSTreeNode(BSTree* pBSTree, int nData){
    TNode* pNode = _newTreeNode();
    pNode->nData = nData;
    if(pBSTree->nSize){
        TNode* pCurN = pBSTree->pRoot;
        while (1){
            if(pCurN->nData == nData){
                printf("Already Existed.\n");
                _delTreeNode(pNode);
                return -1;
            } else if(pCurN->nData > nData){
                if(pCurN->pLeft){
                    pCurN = pCurN->pLeft;
                } else {
                    pCurN->pLeft = pNode;
                    pBSTree->nSize += 1;
                    return 0;
                }
            } else {
                if(pCurN->pRight){
                    pCurN = pCurN->pRight;
                } else {
                    pCurN->pRight = pNode;
                    pBSTree->nSize += 1;
                    return 0;
                }
                
            }
        }
    }
    pBSTree->pRoot = pNode;
    pBSTree->nSize += 1;
    return 0;
}
int deleteBSTreeNode(BSTree* pBSTree, int nData){
    // 1. BST 사이즈가 0일 경우 return 0;
    if(pBSTree->nSize == 0){
        return 0;
    }

    // 2. 일반적인 케이스
    //  2-0. 타겟을 찾는다. T  타겟이 없을경우 return 0;
    //  2-1. 타겟의 부모를 찾는다. TP  타겟이 Root일 경우 NULL
    //       -> if(TP->Left == T){isLeft = TRUE} or if(TP->Right == T){isLeft = FALSE}
    bool isLeft = FALSE;
    TNode* pTargetParent = NULL;
    TNode* pTarget = pBSTree->pRoot;
    while(pTarget->nData!=nData){
        if(pTarget->nData > nData){
            if(pTarget->pLeft){
                pTargetParent = pTarget;
                pTarget = pTarget->pLeft;
                isLeft = TRUE;
            } else {
                return 0;
            }
        } else {
            if(pTarget->pRight){
                pTargetParent = pTarget;
                pTarget = pTarget->pRight;
                isLeft = FALSE;
            } else {
                return 0;
            }
        }
    }
    //  2-2. 타겟의 L-R-R-R-... or R-L-L-... 끝으로 가서 Right/Left가 NULL이 나오는 다음 타겟을 찾는다. NT
    //  2-3. 다음 타겟의 부모를 찾는다. NTP
    TNode* pNextTargetParent = pTargetParent;
    TNode* pNextTarget = pTarget;
    bool isLeftNT = FALSE;
    if(pNextTarget->pLeft){
        // L-R-R-R-... case
        pNextTargetParent = pNextTarget;
        pNextTarget = pNextTarget->pLeft;
        isLeftNT = TRUE;
        while(pNextTarget->pRight){
            pNextTargetParent = pNextTarget;
            pNextTarget = pNextTarget->pRight;
            isLeftNT = FALSE;
        }
    } else if(pNextTarget->pRight){
        // R-L-L-L-... case
        pNextTargetParent = pNextTarget;
        pNextTarget = pNextTarget->pRight;
        isLeftNT = FALSE;
        while(pNextTarget->pLeft){
            pNextTargetParent = pNextTarget;
            pNextTarget = pNextTarget->pLeft;
            isLeftNT = TRUE;
        }
    } else {
        // NT가 없을 경우 연결 재정의 필요 X
        // 타겟 삭제 후 타겟 부모의 연결만 재정의 하고 return
        if(pTargetParent){
            if(isLeft){
                pTargetParent->pLeft = NULL;
            } else {
                pTargetParent->pRight = NULL;
            }
        } else {
            pBSTree->pRoot = NULL;
        }
        _delTreeNode(pTarget);
        pTarget = NULL;
        pBSTree->nSize -= 1;
        return 0;
    }
    
    // 3. 연결을 재정의 한다.
    if(isLeftNT){
        // NTP -> Left = NT -> Right : 다음 타겟의 우측을 다음타겟부모의 좌측에 연결한다.
        pNextTargetParent->pLeft = pNextTarget->pRight;
    } else {
        // NTP -> Right = NT -> Left : 다음 타겟의 좌측을 다음타겟부모의 우측에 연결한다.
        pNextTargetParent->pRight = pNextTarget->pLeft;
    }
    if(isLeft){
        // TP -> L/R = NT : 삭제된 위치에 NT를 연결한다. TP가 NULL일 경우 pBSTree->pRoot에 연결
        if(pTargetParent){
            pTargetParent->pLeft = pNextTarget;
        } else {
            pBSTree->pRoot = pNextTarget;
        }
    } else {
        if(pTargetParent){
            pTargetParent->pRight = pNextTarget;
        } else {
            pBSTree->pRoot = pNextTarget;
        }
    }
    // 삭제할 타겟의 좌/우를 NT 각각 좌/우에 연결한다.
    // NT -> Left = T -> Left, NT -> Right = T -> Right
    pNextTarget->pLeft = pTarget->pLeft;
    pNextTarget->pRight = pTarget->pRight;
    
    // 4. 타겟을 제거한다.
    _delTreeNode(pTarget);
    pTarget = NULL;
    pBSTree->nSize -= 1;
    return 0;
}

int main(){
    BSTree* pBSTree = newBSTree();
    insertBSTreeNode(pBSTree, 10);
    insertBSTreeNode(pBSTree, 5);
    insertBSTreeNode(pBSTree, 3);
    insertBSTreeNode(pBSTree, 15);
    insertBSTreeNode(pBSTree, 11);
    insertBSTreeNode(pBSTree, 16);
    insertBSTreeNode(pBSTree, 13);
    insertBSTreeNode(pBSTree, 8);
    insertBSTreeNode(pBSTree, 9);

    traversalBSTree(pBSTree, INORDER);
    traversalBSTree(pBSTree, PREORDER);
    traversalBSTree(pBSTree, POSTORDER);
    
    printf("%d\n", pBSTree->nSize);
    deleteBSTreeNode(pBSTree, 10);
    printf("%d\n", pBSTree->nSize);
    deleteBSTreeNode(pBSTree, 5);
    printf("%d\n", pBSTree->nSize);
    deleteBSTreeNode(pBSTree, 3);
    printf("%d\n", pBSTree->nSize);
    deleteBSTreeNode(pBSTree, 15);
    printf("%d\n", pBSTree->nSize);
    deleteBSTreeNode(pBSTree, 11);
    printf("%d\n", pBSTree->nSize);
    deleteBSTreeNode(pBSTree, 16);
    printf("%d\n", pBSTree->nSize);
    deleteBSTreeNode(pBSTree, 13);
    printf("%d\n", pBSTree->nSize);
    deleteBSTreeNode(pBSTree, 8);
    printf("%d\n", pBSTree->nSize);
    deleteBSTreeNode(pBSTree, 9);
    printf("%d\n", pBSTree->nSize);

    traversalBSTree(pBSTree, INORDER);
    traversalBSTree(pBSTree, PREORDER);
    traversalBSTree(pBSTree, POSTORDER);

    insertBSTreeNode(pBSTree, 10);
    insertBSTreeNode(pBSTree, 5);
    insertBSTreeNode(pBSTree, 3);
    insertBSTreeNode(pBSTree, 15);
    insertBSTreeNode(pBSTree, 11);
    insertBSTreeNode(pBSTree, 16);
    insertBSTreeNode(pBSTree, 13);
    insertBSTreeNode(pBSTree, 8);
    insertBSTreeNode(pBSTree, 9);

    traversalBSTree(pBSTree, INORDER);
    traversalBSTree(pBSTree, PREORDER);
    traversalBSTree(pBSTree, POSTORDER);
    
    printf("SEARCH: %d\n", searchBSTreeNode(pBSTree, 10));
    printf("SEARCH: %d\n", searchBSTreeNode(pBSTree, 50));
    printf("SEARCH: %d\n", searchBSTreeNode(pBSTree, 1));
    printf("SEARCH: %d\n", searchBSTreeNode(pBSTree, 9));

    printf("%d\n", pBSTree->nSize);
    deleteBSTreeNode(pBSTree, 10);
    printf("%d\n", pBSTree->nSize);
    deleteBSTreeNode(pBSTree, 5);
    printf("%d\n", pBSTree->nSize);
    deleteBSTreeNode(pBSTree, 3);
    printf("%d\n", pBSTree->nSize);
    deleteBSTreeNode(pBSTree, 15);
    printf("%d\n", pBSTree->nSize);
    deleteBSTreeNode(pBSTree, 11);
    printf("%d\n", pBSTree->nSize);
    deleteBSTreeNode(pBSTree, 16);
    printf("%d\n", pBSTree->nSize);
    deleteBSTreeNode(pBSTree, 13);
    printf("%d\n", pBSTree->nSize);
    deleteBSTreeNode(pBSTree, 8);
    printf("%d\n", pBSTree->nSize);
    deleteBSTreeNode(pBSTree, 9);
    printf("%d\n", pBSTree->nSize);

    traversalBSTree(pBSTree, INORDER);
    traversalBSTree(pBSTree, PREORDER);
    traversalBSTree(pBSTree, POSTORDER);

    insertBSTreeNode(pBSTree, 10);

    delBSTree(pBSTree);
    pBSTree = NULL;
    return 0;
}