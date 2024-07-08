#ifndef _DOUBLYLINKEDLIST_H_
    #define _DOUBLYLINKEDLIST_H_

    #include <stdio.h>
    #include <malloc.h>

    ////////////////////////////////////////////////////////////
    // .c에서만 쓸 텐데 헤더에 넣을 필요가 있는가.?
    typedef struct _DNode DNode;
    struct _DNode{
        DNode*  pNext;
        DNode*  pPrev;
        int     nData;
    };

    DNode*  newDNode        ();
    int     delDNode        (DNode* pNode);
    int     writeDataDNode  (DNode* pNode, int nData);
    int     nextDNode       (DNode* pNode, DNode* pNext);
    int     prevDNode       (DNode* pNode, DNode* pPrev);

    ////////////////////////////////////////////////////////////
    typedef struct _doublyLinkedList DLList;
    struct _doublyLinkedList{
        // void*   pDataType;
        DNode*  pHead;
        DNode*  pTail;
        int     nSize;
    };

    DLList* newDLList       ();                             // 생성자
    DNode*  delDLList       (DLList* pDLList);              // 소멸자
    int     delAllNode      (DLList* pDLList);
    int     lenDLList       (DLList* pDLList);
    int     readDLLHeadData (DLList* pDLList);
    int     traversalDLList (DLList* pDLList);
    int     pushNodeLeft    (DLList* pDLList, int nData);
    int     delNodeLeft     (DLList* pDLList);
//  DNode*  _findNode       (DLList* pDLList, int nData);
    int     delNodeByData   (DLList* pDLList, int nData);

#endif