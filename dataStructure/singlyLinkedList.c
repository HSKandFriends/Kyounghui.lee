// #include <stdio.h>
#include "singlyLinkedList.h"


////////////////////////////////////////////////////////////
SNode* newSNode(){
    SNode* pNode = (SNode*)malloc(sizeof(SNode));
    pNode->nData = 0;
    pNode->pNext = 0;

    // memset from string.h for initialization
    // memset(pNode, 0, sizeof(Node));
    
    // calloc from stdlib.h for malloc + memset
    // Node* pNode = (Node*)calloc(1, sizeof(Node));
    return pNode;
}


int delSNode(SNode* pNode){
    // printf(
    //     "Node [%p]: data [%d] deleted successfully\n",
    //     pNode, pNode->nData
    // );
    int rData = pNode->nData;
    free(pNode);
    pNode = NULL;
    return rData;
}


int writeDataSNode(SNode* pNode, int nData){
    pNode->nData = nData;
    return 0;
}


int nextSNode(SNode* pNode, SNode* pNext){
    pNode->pNext = pNext;
    return 0;
}
////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////
SLList* newSLList(){
    SLList* pSLList = (SLList*)malloc(sizeof(SLList));
    pSLList->pHead = 0;
    pSLList->nSize = 0;
    return pSLList;
}


SNode* delSLList(SLList* pSLList){
    // list를 삭제하기 전에 해당 노드들이 free 되지 않았기 때문에 메모리 누수 가능성을 항상 염두해 둬야함
    // 이를 해결하기 위해서 어떻게 해야할까? 
    // 1. pHead를 리턴하는 방법 -> 이후 사용자가 pHead를 알아서 처리해라. -> 사용자 실수로 메모리 누수 가능
    // 2. pSLList->nSize가 0보다 클 경우 delAllNode()를 수행하고 삭제
    // 2번 방식의 경우, 해당 노드를 다른 리스트와 연결해서 쓸 수 있기 때문에 문제 발생
    // ex) A리스트, B리스트가 존재, B리스트의 노드를 A리스트와 연결함
    // 그 후 B리스트에 할당된 메모리를 제거. 이 때 2번 방식을 쓸 경우 A 리스트에 연결된 노드가 다 삭제됨.
    if(pSLList->nSize){
        printf("There are Nodes in linked list.\n");
    }
    SNode* pHead = pSLList->pHead;
    free(pSLList);
    pSLList = NULL;
    return pHead;
}


int delAllSNode(SLList* pSLList){
    SNode* pNode = pSLList->pHead;
    // Node* pTemp = pNode;
    int loopSize = pSLList->nSize;
    for(int i = 0; i>loopSize; i++){
        SNode* pTemp = pNode;
        pNode = pNode->pNext;
        delSNode(pTemp); 
        pSLList->nSize--;
        // printf(
        //     "delData: %d, remainSize: %d\n",
        //     delNode(pTemp), pSLList->nSize--
        // );
    }
    return 0;
}


int lenSLList(SLList* pSLList){
    return pSLList->nSize;
}


int readSLLHeadData(SLList* pSLList){
    if(pSLList->pHead){
        return pSLList->pHead->nData;
    }
    return 0;
}


int traversalSLList(SLList* pSLList){
    if (pSLList->nSize == 0){
        printf("[]\n");
        return 0;
    }
    SNode* pNode = pSLList->pHead;
    printf("[");
    for(int i = 0; i<pSLList->nSize; i++){
        printf("%d ", pNode->nData);
        pNode = pNode->pNext;
    }
    printf("\b]\n");
    return 0;
}


int pushSNodeLeft(SLList* pSLList, int nData){
    //Push Node to Head
    //1. Make New Node
    SNode* pNode = newSNode();

    //2. Write Data to New Node
    writeDataSNode(pNode, nData);

    //3. Check SLList has Node(s).
    if (pSLList->nSize){                //3-1. If SLList has Node(s).
        pNode->pNext = pSLList->pHead;  //Set the Next Node of New Node to current SLList Head Node.
    }
    //4. Set New Node to SLList's Head Node.
    pSLList->pHead = pNode;

    //5. Set SLList Size +1
    pSLList->nSize++;
    return 0;
}


int delSNodeLeft(SLList* pSLList){
    //delete Node from head
    if(pSLList->nSize == 0){
        printf("[CANNOT DELETE]Empty List.\n");
        return 0;
    }
    SNode* pNode = pSLList->pHead;
    pSLList->pHead = pSLList->pHead->pNext;
    pSLList->nSize--;
    return delSNode(pNode);
}


SNode* _findSNode(SLList* pSLList, int nData){
    SNode* preNode = 0;
    SNode* curNode = pSLList->pHead;

    for(int i = 0; i<pSLList->nSize; i++){
        if(curNode->nData == nData){
            return preNode;
        }
        preNode = curNode;
        curNode = curNode->pNext;
    }
    // Exception: Head Node is the Node to find.
    // 어떻게 처리해야 되지? 헷깔리는군...
    // 못 찾은 것과 head 인 것과 구분을 해야하는데...
    // findNode를 내부 함수에만 쓰는 걸로 결정.
    return 0;
}


int delSNodeByData(SLList* pSLList, int nData){
    SNode* preNode = _findSNode(pSLList, nData);
    if(preNode == 0){
        //When preNode == 0, delNode is head or no delNode. 
        if(readSLLHeadData(pSLList) == nData){
            // Node* pNode = pSLList->pHead;
            // pSLList->pHead = pSLList->pHead->pNext;
            // free(pNode);
            // pNode = NULL;
            // pSLList->nSize--;
            delSNodeLeft(pSLList);
            return 0; 
        } 
        // There is no Node to delete.
        return -1;
    }
    SNode* pNode = preNode->pNext;
    preNode->pNext = preNode->pNext->pNext;
    free(pNode);
    pNode = NULL;
    pSLList->nSize--;
    return 0;
}
////////////////////////////////////////////////////////////

int main(){

    SLList* pSLList = newSLList();
    pushSNodeLeft(pSLList, 10);
    traversalSLList(pSLList);
    pushSNodeLeft(pSLList, 20);
    traversalSLList(pSLList);
    pushSNodeLeft(pSLList, 30);
    traversalSLList(pSLList);
    pushSNodeLeft(pSLList, 40);
    traversalSLList(pSLList);
    printf("head: %d, length: %d\n", readSLLHeadData(pSLList), lenSLList(pSLList));
    delSNodeLeft(pSLList);
    traversalSLList(pSLList);
    pushSNodeLeft(pSLList, 50);
    traversalSLList(pSLList);
    delSNodeLeft(pSLList);
    traversalSLList(pSLList);
    delSNodeLeft(pSLList);
    traversalSLList(pSLList);
    printf("head: %d, length: %d\n", readSLLHeadData(pSLList), lenSLList(pSLList));
    delSNodeLeft(pSLList);
    traversalSLList(pSLList);
    printf("head: %d, length: %d\n", readSLLHeadData(pSLList), lenSLList(pSLList));
    delSNodeLeft(pSLList);
    traversalSLList(pSLList);
    printf("head: %d, length: %d\n", readSLLHeadData(pSLList), lenSLList(pSLList));
    delSNodeLeft(pSLList);
    traversalSLList(pSLList);
    delSNodeLeft(pSLList);
    traversalSLList(pSLList);
    printf("head: %d, length: %d\n", readSLLHeadData(pSLList), lenSLList(pSLList));


    pushSNodeLeft(pSLList, 10);
    traversalSLList(pSLList);
    printf("head: %d, length: %d\n", readSLLHeadData(pSLList), lenSLList(pSLList));
    pushSNodeLeft(pSLList, 20);
    traversalSLList(pSLList);
    printf("head: %d, length: %d\n", readSLLHeadData(pSLList), lenSLList(pSLList));
    pushSNodeLeft(pSLList, 30);
    traversalSLList(pSLList);
    printf("head: %d, length: %d\n", readSLLHeadData(pSLList), lenSLList(pSLList));
    pushSNodeLeft(pSLList, 40);
    traversalSLList(pSLList);
    printf("head: %d, length: %d\n", readSLLHeadData(pSLList), lenSLList(pSLList));
    pushSNodeLeft(pSLList, 50);
    traversalSLList(pSLList);
    printf("head: %d, length: %d\n", readSLLHeadData(pSLList), lenSLList(pSLList));
    delSNodeByData(pSLList, 30);
    traversalSLList(pSLList);
    printf("head: %d, length: %d\n", readSLLHeadData(pSLList), lenSLList(pSLList));
    delSNodeByData(pSLList, 50);
    traversalSLList(pSLList);
    printf("head: %d, length: %d\n", readSLLHeadData(pSLList), lenSLList(pSLList));
    delSNodeByData(pSLList, 10);
    traversalSLList(pSLList);
    printf("head: %d, length: %d\n", readSLLHeadData(pSLList), lenSLList(pSLList));
    delSNodeByData(pSLList, 20);
    traversalSLList(pSLList);
    printf("head: %d, length: %d\n", readSLLHeadData(pSLList), lenSLList(pSLList));
    delSNodeByData(pSLList, 40);
    traversalSLList(pSLList);
    printf("head: %d, length: %d\n", readSLLHeadData(pSLList), lenSLList(pSLList));

    return 0;
}