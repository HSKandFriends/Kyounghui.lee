#ifndef _QUEUE_H_
    #define _QUEUE_H_

    #include <stdio.h>
    #include <malloc.h>

    typedef struct _Queue Queue;

    Queue*  newQueue    ();
    int     delQueue    (Queue* pQueue);
    int     pushQueue   (Queue* pQueue, int nData);
    int     popQueue    (Queue* pQueue);
    int     firstQueue  (Queue* pQueue);
    int     lastQueue   (Queue* pQueue);
    int     lenQueue    (Queue* pQueue);
#endif