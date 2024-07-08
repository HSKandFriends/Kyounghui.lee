#include "queue.h"
///////////////////////////////////////////////////////////////
typedef struct _QueueNode QueueNode;
struct _QueueNode{
    QueueNode*  pBelow;
    int         nData;
};
QueueNode* _newQueueNode(){
    QueueNode* pNode = (QueueNode*)malloc(sizeof(QueueNode));
    pNode->pBelow = NULL;
    pNode->nData = 0;
    return pNode;
}
int _delQueueNode(QueueNode* pNode){
    free(pNode);
    pNode = NULL;
    return 0;
}
///////////////////////////////////////////////////////////////
struct _Queue{
    QueueNode*  pFirst;
    QueueNode*  pLast;
    int         nSize;
};
Queue* newQueue(){
    Queue* pQueue = (Queue*)malloc(sizeof(Queue));
    pQueue->pFirst = NULL;
    pQueue->pLast = NULL;
    pQueue->nSize = 0;
    return pQueue;
}
int delQueue(Queue* pQueue){
    QueueNode* pNode = pQueue->pFirst;
    QueueNode* pFreeNode = NULL;
    for(int i=0; i>pQueue->nSize; i++){
        pFreeNode = pNode;
        pNode = pNode->pBelow;
        _delQueueNode(pFreeNode);
    }
    free(pQueue);
    pQueue = NULL;
    return 0;
}
int pushQueue(Queue* pQueue, int nData){
    QueueNode* pNode = _newQueueNode();
    pNode->nData = nData;
    if(pQueue->nSize){
        pQueue->pLast->pBelow = pNode;
    } else {
        pQueue->pFirst = pNode;
    }
    pQueue->pLast = pNode;
    pQueue->nSize += 1;
    return 0;
}
int popQueue(Queue* pQueue){
    if(pQueue->nSize){
        QueueNode* pNode = pQueue->pFirst;
        pQueue->pFirst = pNode->pBelow;
        int popData = pNode->nData;
        _delQueueNode(pNode);
        pQueue->nSize -= 1;
        return popData;
    }
    return 0;
}
int firstQueue(Queue* pQueue){
    if(pQueue->nSize){
        return pQueue->pFirst->nData;
    }
    return 0;
}
int lastQueue(Queue* pQueue){
    if(pQueue->nSize){
        return pQueue->pLast->nData;
    }
    return 0;
}
int lenQueue(Queue* pQueue){
    return pQueue->nSize;
}
///////////////////////////////////////////////////////////////
int main(){
    Queue* pQueue = newQueue();
    pushQueue(pQueue, 1);
    printf("Size: %d, First: %d, Last: %d\n", lenQueue(pQueue), firstQueue(pQueue), lastQueue(pQueue));
    pushQueue(pQueue, 2);
    printf("Size: %d, First: %d, Last: %d\n", lenQueue(pQueue), firstQueue(pQueue), lastQueue(pQueue));
    pushQueue(pQueue, 3);
    printf("Size: %d, First: %d, Last: %d\n", lenQueue(pQueue), firstQueue(pQueue), lastQueue(pQueue));
    printf("POP: %d\n",popQueue(pQueue));
    printf("Size: %d, First: %d, Last: %d\n", lenQueue(pQueue), firstQueue(pQueue), lastQueue(pQueue));
    pushQueue(pQueue, 4);
    printf("Size: %d, First: %d, Last: %d\n", lenQueue(pQueue), firstQueue(pQueue), lastQueue(pQueue));
    pushQueue(pQueue, 5);
    printf("Size: %d, First: %d, Last: %d\n", lenQueue(pQueue), firstQueue(pQueue), lastQueue(pQueue));
    printf("POP: %d\n",popQueue(pQueue));
    printf("Size: %d, First: %d, Last: %d\n", lenQueue(pQueue), firstQueue(pQueue), lastQueue(pQueue));
    pushQueue(pQueue, 6);
    printf("Size: %d, First: %d, Last: %d\n", lenQueue(pQueue), firstQueue(pQueue), lastQueue(pQueue));
    pushQueue(pQueue, 7);
    printf("Size: %d, First: %d, Last: %d\n", lenQueue(pQueue), firstQueue(pQueue), lastQueue(pQueue));
    pushQueue(pQueue, 8);
    printf("Size: %d, First: %d, Last: %d\n", lenQueue(pQueue), firstQueue(pQueue), lastQueue(pQueue));
    printf("POP: %d\n",popQueue(pQueue));
    printf("Size: %d, First: %d, Last: %d\n", lenQueue(pQueue), firstQueue(pQueue), lastQueue(pQueue));
    pushQueue(pQueue, 9);
    printf("Size: %d, First: %d, Last: %d\n", lenQueue(pQueue), firstQueue(pQueue), lastQueue(pQueue));
    printf("POP: %d\n",popQueue(pQueue));
    printf("Size: %d, First: %d, Last: %d\n", lenQueue(pQueue), firstQueue(pQueue), lastQueue(pQueue));
    pushQueue(pQueue, 10);
    printf("Size: %d, First: %d, Last: %d\n", lenQueue(pQueue), firstQueue(pQueue), lastQueue(pQueue));
    printf("POP: %d\n",popQueue(pQueue));
    printf("Size: %d, First: %d, Last: %d\n", lenQueue(pQueue), firstQueue(pQueue), lastQueue(pQueue));
    pushQueue(pQueue, 11);
    printf("Size: %d, First: %d, Last: %d\n", lenQueue(pQueue), firstQueue(pQueue), lastQueue(pQueue));
    printf("POP: %d\n",popQueue(pQueue));
    printf("Size: %d, First: %d, Last: %d\n", lenQueue(pQueue), firstQueue(pQueue), lastQueue(pQueue));
    printf("POP: %d\n",popQueue(pQueue));
    printf("Size: %d, First: %d, Last: %d\n", lenQueue(pQueue), firstQueue(pQueue), lastQueue(pQueue));
    printf("POP: %d\n",popQueue(pQueue));
    printf("Size: %d, First: %d, Last: %d\n", lenQueue(pQueue), firstQueue(pQueue), lastQueue(pQueue));
    printf("POP: %d\n",popQueue(pQueue));
    printf("Size: %d, First: %d, Last: %d\n", lenQueue(pQueue), firstQueue(pQueue), lastQueue(pQueue));
    printf("POP: %d\n",popQueue(pQueue));
    printf("Size: %d, First: %d, Last: %d\n", lenQueue(pQueue), firstQueue(pQueue), lastQueue(pQueue));
    printf("POP: %d\n",popQueue(pQueue));
    printf("Size: %d, First: %d, Last: %d\n", lenQueue(pQueue), firstQueue(pQueue), lastQueue(pQueue));
    printf("POP: %d\n",popQueue(pQueue));
    printf("Size: %d, First: %d, Last: %d\n", lenQueue(pQueue), firstQueue(pQueue), lastQueue(pQueue));
    pushQueue(pQueue, 1);
    printf("Size: %d, First: %d, Last: %d\n", lenQueue(pQueue), firstQueue(pQueue), lastQueue(pQueue));
    printf("POP: %d\n",popQueue(pQueue));
    printf("Size: %d, First: %d, Last: %d\n", lenQueue(pQueue), firstQueue(pQueue), lastQueue(pQueue));
    printf("POP: %d\n",popQueue(pQueue));
    printf("Size: %d, First: %d, Last: %d\n", lenQueue(pQueue), firstQueue(pQueue), lastQueue(pQueue));
    printf("POP: %d\n",popQueue(pQueue));
    printf("Size: %d, First: %d, Last: %d\n", lenQueue(pQueue), firstQueue(pQueue), lastQueue(pQueue));
    pushQueue(pQueue, 1);
    printf("Size: %d, First: %d, Last: %d\n", lenQueue(pQueue), firstQueue(pQueue), lastQueue(pQueue));

    delQueue(pQueue);
    pQueue = NULL;
    return 0;
}