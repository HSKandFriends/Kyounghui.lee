#ifndef _SINGLYLINKEDLIST_H_
    #define _SINGLYLINKEDLIST_H_

    #include <stdio.h>
    #include <malloc.h>

    ////////////////////////////////////////////////////////////Node 관련
    typedef struct _SNode SNode;
    struct _SNode{
        SNode*  pNext;
        int     nData;
    };

    SNode*  newSNode        ();
    int     delSNode        (SNode* pNode);
    int     writeDataSNode  (SNode* pNode, int nData);
    int     nextSNode       (SNode* pNode, SNode* pNext);


    //////////////////////////////////////////////////////////// List 관련
    typedef struct _SinglyLinkedList SLList;
    struct _SinglyLinkedList{
        SNode*  pHead;
        int     nSize;    
    };

    SLList* newSLList       ();                             // 생성자
    SNode*  delSLList       (SLList* pSLList);              // 소멸자
    int     delAllSNode     (SLList* pSLList);
    int     lenSLList       (SLList* pSLList);
    int     readSLLHeadData    (SLList* pSLList);
    int     traversalSLList (SLList* pSLList);
    int     pushSNodeLeft   (SLList* pSLList, int nData);
    int     delSNodeLeft    (SLList* pSLList);
//  SNode*  _findSNode      (SLList* pSLList, int nData);
    int     delSNodeByData  (SLList* pSLList, int nData);

#endif