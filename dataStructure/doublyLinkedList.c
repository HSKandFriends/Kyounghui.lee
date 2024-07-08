// #include <stdio.h>
#include "doublyLinkedList.h"


////////////////////////////////////////////////////////////
DNode* newDNode(){
    DNode* pNode = (DNode*)malloc(sizeof(DNode));
    pNode->nData = 0;
    pNode->pNext = NULL;
    pNode->pPrev = NULL;

    return pNode;
}
int delDNode(DNode* pNode){
    // printf(
    //     "Node [%p]: data [%d] deleted successfully\n",
    //     pNode, pNode->nData
    // );
    int rData = pNode->nData;
    free(pNode);
    pNode = NULL;
    return rData;
}
int writeDataDNode(DNode* pNode, int nData){
    pNode->nData = nData;
    return 0;
}
int nextDNode(DNode* pNode, DNode* pNext){
    pNode->pNext = pNext;
    return 0;
}
int prevDNode(DNode* pNode, DNode* pPrev){
    pNode->pPrev = pPrev;
    return 0;
}
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
DLList* newDLList(){
    DLList* pDLList = (DLList*)malloc(sizeof(DLList));
    pDLList->pHead = NULL;
    pDLList->pTail = NULL;
    pDLList->nSize = 0;
    return pDLList;
}
//list 삭제 전 Node를 어떻게 처리할지 고민해야한다.
//User가 직접 Node를 사용가능하게 해야할지... 아닐지...
//
DNode* delDLList(DLList* pDLList){
    if(pDLList->nSize){
        printf("There are Nodes in linked list.\n");
    }
    DNode* pHead = pDLList->pHead;
    free(pDLList);
    pDLList = NULL;
    return pHead;
}
int delAllNode(DLList* pDLList){
    DNode* pNode = pDLList->pHead;
    int loopSize = pDLList->nSize;
    for(int i = 0; i>loopSize; i++){
        DNode* pTemp = pNode;
        pNode = pNode->pNext;
        delDNode(pTemp); 
        pDLList->nSize--;
        // printf(
        //     "delData: %d, remainSize: %d\n",
        //     delNode(pTemp), pDLList->nSize--
        // );
    }
    return 0;
}
int lenDLList(DLList* pDLList){
    return pDLList->nSize;
}
int readDLLHeadData(DLList* pDLList){
    if(pDLList->pHead){
        return pDLList->pHead->nData;
    }
    return 0;
}
int traversalDLList(DLList* pDLList){
    if (pDLList->nSize == 0){
        printf("[]\n");
        return 0;
    }
    DNode* pNode = pDLList->pHead;
    printf("[");
    for(int i = 0; i<pDLList->nSize; i++){
        printf("%d ", pNode->nData);
        pNode = pNode->pNext;
    }
    printf("\b]\n");
    return 0;
}
int pushDNodeLeft(DLList* pDLList, int nData){
    // Make a New Node
    DNode* pNode = newDNode();
    writeDataDNode(pNode, nData);

    //2 cases
    //  1. Empty DLL
    //  2. Not Empty DLL
    if (pDLList->nSize){
        pDLList->pHead->pPrev = pNode;
        pNode->pNext = pDLList->pHead;
        pDLList->pHead = pNode;
    } else {
        pDLList->pHead = pNode;
        pDLList->pTail = pNode;
    }

    pDLList->nSize++;
    return 0;
}
int pushDNodeRight(DLList* pDLList, int nData){
    // Make a New Node
    DNode* pNode = newDNode();
    writeDataDNode(pNode, nData);

    //2 cases
    //  1. Empty DLL
    //  2. Not Empty DLL
    if (pDLList->nSize){
        pDLList->pTail->pNext = pNode;
        pNode->pPrev = pDLList->pTail;
        pDLList->pTail = pNode;
    } else {
        pDLList->pHead = pNode;
        pDLList->pTail = pNode;
    }

    pDLList->nSize++;
    return 0;
}
int delDNodeLeft(DLList* pDLList){
    //delete Node from head
    if(pDLList->nSize == 0){
        printf("[CANNOT DELETE]Empty List.\n");
        return 0;
    }
    if(pDLList->nSize == 1){
        pDLList->pTail = NULL;
    }

    DNode* pNode = pDLList->pHead;
    pDLList->pHead = pDLList->pHead->pNext;
    pDLList->nSize--;
    return delDNode(pNode);
}
int delDNodeRight(DLList* pDLList){
    //delete Node from tail
    if(pDLList->nSize == 0){
        printf("[CANNOT DELETE]Empty List.\n");
        return 0;
    }
    if(pDLList->nSize == 1){
        pDLList->pHead = NULL;
    }

    DNode* pNode = pDLList->pTail;
    pDLList->pTail = pDLList->pTail->pPrev;
    pDLList->nSize--;
    return delDNode(pNode);
}
DNode* _findDNode(DLList* pDLList, int nData){
    DNode* pNode = pDLList->pHead;

    for(int i = 0; i<pDLList->nSize; i++){
        if(pNode->nData == nData){
            return pNode;
        }
        pNode = pNode->pNext;
    }
    return NULL;
}
int delDNodeByData(DLList* pDLList, int nData){
    DNode* pNode = _findDNode(pDLList, nData);
    if(pNode == NULL){
        return 0;
    }
    if(pNode->pPrev == NULL){
        pDLList->pHead = pNode->pNext;
    } else {
        pNode->pPrev->pNext = pNode->pNext;
    }
    if(pNode->pNext == NULL){
        pDLList->pTail = pNode->pPrev;
    } else {
        pNode->pNext->pPrev = pNode->pPrev;
    }
    pDLList->nSize--;

    return delDNode(pNode);

}
////////////////////////////////////////////////////////////

int main(){

    DLList* pDLList = newDLList();
    pushDNodeLeft(pDLList, 10);
    traversalDLList(pDLList);
    pushDNodeLeft(pDLList, 20);
    traversalDLList(pDLList);
    pushDNodeLeft(pDLList, 30);
    traversalDLList(pDLList);
    pushDNodeLeft(pDLList, 40);
    traversalDLList(pDLList);
    printf("head: %d, length: %d\n", readDLLHeadData(pDLList), lenDLList(pDLList));
    delDNodeLeft(pDLList);
    traversalDLList(pDLList);
    pushDNodeLeft(pDLList, 50);
    traversalDLList(pDLList);
    delDNodeLeft(pDLList);
    traversalDLList(pDLList);
    delDNodeLeft(pDLList);
    traversalDLList(pDLList);
    printf("head: %d, length: %d\n", readDLLHeadData(pDLList), lenDLList(pDLList));
    delDNodeLeft(pDLList);
    traversalDLList(pDLList);
    printf("head: %d, length: %d\n", readDLLHeadData(pDLList), lenDLList(pDLList));
    delDNodeLeft(pDLList);
    traversalDLList(pDLList);
    printf("head: %d, length: %d\n", readDLLHeadData(pDLList), lenDLList(pDLList));
    delDNodeLeft(pDLList);
    traversalDLList(pDLList);
    delDNodeLeft(pDLList);
    traversalDLList(pDLList);
    printf("head: %d, length: %d\n", readDLLHeadData(pDLList), lenDLList(pDLList));


    pushDNodeLeft(pDLList, 10);
    traversalDLList(pDLList);
    printf("head: %d, length: %d\n", readDLLHeadData(pDLList), lenDLList(pDLList));
    pushDNodeLeft(pDLList, 20);
    traversalDLList(pDLList);
    printf("head: %d, length: %d\n", readDLLHeadData(pDLList), lenDLList(pDLList));
    pushDNodeLeft(pDLList, 30);
    traversalDLList(pDLList);
    printf("head: %d, length: %d\n", readDLLHeadData(pDLList), lenDLList(pDLList));
    pushDNodeLeft(pDLList, 40);
    traversalDLList(pDLList);
    printf("head: %d, length: %d\n", readDLLHeadData(pDLList), lenDLList(pDLList));
    pushDNodeLeft(pDLList, 50);
    traversalDLList(pDLList);
    printf("head: %d, length: %d\n", readDLLHeadData(pDLList), lenDLList(pDLList));
    delDNodeByData(pDLList, 30);
    traversalDLList(pDLList);
    printf("head: %d, length: %d\n", readDLLHeadData(pDLList), lenDLList(pDLList));
    delDNodeByData(pDLList, 50);
    traversalDLList(pDLList);
    printf("head: %d, length: %d\n", readDLLHeadData(pDLList), lenDLList(pDLList));
    delDNodeByData(pDLList, 10);
    traversalDLList(pDLList);
    printf("head: %d, length: %d\n", readDLLHeadData(pDLList), lenDLList(pDLList));
    delDNodeByData(pDLList, 20);
    traversalDLList(pDLList);
    printf("head: %d, length: %d\n", readDLLHeadData(pDLList), lenDLList(pDLList));
    delDNodeByData(pDLList, 40);
    traversalDLList(pDLList);
    printf("head: %d, length: %d\n", readDLLHeadData(pDLList), lenDLList(pDLList));

    return 0;
}