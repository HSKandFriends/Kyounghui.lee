#ifndef _STACK_H_
    #define _STACK_H_

    #include <stdio.h>
    #include <malloc.h>

    typedef struct _Stack Stack;

    Stack*  newStack    ();
    int     delStack    (Stack* pStack);
    int     pushStack   (Stack* pStack, int nData);
    int     popStack    (Stack* pStack);
    int     topStack    (Stack* pStack);
    int     lenStack    (Stack* pStack);
#endif