#include "stack.h"

typedef struct _StackNode StackNode;
struct _StackNode{
    StackNode*  pBelow;
    int         nData;
};
StackNode* _newStackNode(){
    StackNode* pNode = (StackNode*)malloc(sizeof(StackNode));
    pNode->nData = 0;
    pNode->pBelow = NULL;
    return pNode;
}
int _delStackNode(StackNode* pNode){
    free(pNode);
    pNode = NULL;
    return 0;
}
///////////////////////////////////////////////////////////////
struct _Stack{
    StackNode*  pTop;
    int         nSize;
};

Stack* newStack(){
    Stack* pStack = (Stack*)malloc(sizeof(Stack));
    pStack->nSize = 0;
    pStack->pTop = NULL;
    return pStack;
}

int delStack(Stack* pStack){
    StackNode* pNode = pStack->pTop;
    StackNode* pFreeNode = NULL;
    for(int i=0; i>pStack->nSize; i++){
        pFreeNode = pNode;
        pNode = pNode->pBelow;
        _delStackNode(pFreeNode);
    }
    free(pStack);
    pStack = NULL;
    return 0;
}

int pushStack(Stack* pStack, int nData){
    StackNode* pNode = _newStackNode();
    pNode->nData = nData;
    pNode->pBelow = pStack->pTop;
    pStack->pTop = pNode;
    pStack->nSize += 1;
    return 0;
}

int popStack(Stack* pStack){
    if(pStack->nSize){
        StackNode* pNode = pStack->pTop;
        pStack->pTop = pNode->pBelow;
        int popData = pNode->nData;
        _delStackNode(pNode);
        pStack->nSize -= 1;
        return popData;
    }
    return 0;
}

int topStack(Stack* pStack){
    if(pStack->nSize){
        return pStack->pTop->nData;
    }
    return 0;
}

int lenStack(Stack* pStack){
    return pStack->nSize;
}

int main(){
    Stack* pStack = newStack();
    pushStack(pStack, 1);
    printf("Size: %d, Top: %d\n", lenStack(pStack), topStack(pStack));
    pushStack(pStack, 2);
    printf("Size: %d, Top: %d\n", lenStack(pStack), topStack(pStack));
    pushStack(pStack, 3);
    printf("Size: %d, Top: %d\n", lenStack(pStack), topStack(pStack));
    printf("POP: %d\n",popStack(pStack));
    printf("Size: %d, Top: %d\n", lenStack(pStack), topStack(pStack));
    pushStack(pStack, 4);
    printf("Size: %d, Top: %d\n", lenStack(pStack), topStack(pStack));
    pushStack(pStack, 5);
    printf("Size: %d, Top: %d\n", lenStack(pStack), topStack(pStack));
    printf("POP: %d\n",popStack(pStack));
    printf("Size: %d, Top: %d\n", lenStack(pStack), topStack(pStack));
    pushStack(pStack, 6);
    printf("Size: %d, Top: %d\n", lenStack(pStack), topStack(pStack));
    pushStack(pStack, 7);
    printf("Size: %d, Top: %d\n", lenStack(pStack), topStack(pStack));
    pushStack(pStack, 8);
    printf("Size: %d, Top: %d\n", lenStack(pStack), topStack(pStack));
    printf("POP: %d\n",popStack(pStack));
    printf("Size: %d, Top: %d\n", lenStack(pStack), topStack(pStack));
    pushStack(pStack, 9);
    printf("Size: %d, Top: %d\n", lenStack(pStack), topStack(pStack));
    printf("POP: %d\n",popStack(pStack));
    printf("Size: %d, Top: %d\n", lenStack(pStack), topStack(pStack));
    pushStack(pStack, 10);
    printf("Size: %d, Top: %d\n", lenStack(pStack), topStack(pStack));
    printf("POP: %d\n",popStack(pStack));
    printf("Size: %d, Top: %d\n", lenStack(pStack), topStack(pStack));
    pushStack(pStack, 11);
    printf("Size: %d, Top: %d\n", lenStack(pStack), topStack(pStack));
    printf("POP: %d\n",popStack(pStack));
    printf("Size: %d, Top: %d\n", lenStack(pStack), topStack(pStack));
    printf("POP: %d\n",popStack(pStack));
    printf("Size: %d, Top: %d\n", lenStack(pStack), topStack(pStack));
    printf("POP: %d\n",popStack(pStack));
    printf("Size: %d, Top: %d\n", lenStack(pStack), topStack(pStack));
    printf("POP: %d\n",popStack(pStack));
    printf("Size: %d, Top: %d\n", lenStack(pStack), topStack(pStack));
    printf("POP: %d\n",popStack(pStack));
    printf("Size: %d, Top: %d\n", lenStack(pStack), topStack(pStack));
    printf("POP: %d\n",popStack(pStack));
    printf("Size: %d, Top: %d\n", lenStack(pStack), topStack(pStack));
    printf("POP: %d\n",popStack(pStack));
    printf("Size: %d, Top: %d\n", lenStack(pStack), topStack(pStack));
    pushStack(pStack, 1);
    printf("Size: %d, Top: %d\n", lenStack(pStack), topStack(pStack));
    printf("POP: %d\n",popStack(pStack));
    printf("Size: %d, Top: %d\n", lenStack(pStack), topStack(pStack));

    delStack(pStack);
    pStack = NULL;
    return 0;
}