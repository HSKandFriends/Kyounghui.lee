#include <stdio.h>
#include <malloc.h>

typedef struct _Data1{
    char        memberVariable1;
    short       memberVariable2;
    int         memberVariable4;
    long long   memberVariable8;
} Data1;

typedef struct _Data2{
    char                memberVariable1;
    unsigned char       memberVariable1U;
    short               memberVariable2;
    unsigned short      memberVariable2U;
    int                 memberVariable4;
    unsigned int        memberVariable4U;
    long long           memberVariable8;
    unsigned long long  memberVariable8U;
} Data2;

typedef struct _SNode{
    void*           pData;
    struct _SNode*   pNext;
} SNode;

typedef enum _TYPE{
    DATA1,
    DATA2
} TYPE;

// int typeCastingTest(void* any_struct, TYPE type){
    
//     switch (type)
//     {
//     case DATA1:
//         Data1* temp = (Data1*)any_struct;
//         break;
//     case DATA2:
//         Data2* temp = (Data2*)any_struct;
//         break;
//     default:
//         break;
//     }

//     return 0;
// }


int main(){

    Data1* pData1 = (Data1*)malloc(sizeof(Data1));
    Data2* pData2 = (Data2*)malloc(sizeof(Data1));
    printf("test\n");
    pData1->memberVariable1 = 1;
    pData1->memberVariable2 = 2;
    pData1->memberVariable4 = 3;
    pData1->memberVariable8 = 4;
    printf("%d,%d,%d,%d\n", pData1->memberVariable1,pData1->memberVariable2,pData1->memberVariable4,pData1->memberVariable8);
    printf("%d,%d,%d,%d\n", pData2->memberVariable1,pData2->memberVariable2,pData2->memberVariable4,pData2->memberVariable8);
    


    printf("test: %d(%d,%d,%d,%d)\n", sizeof(Data1), 
        sizeof(pData1->memberVariable1),
        sizeof(pData1->memberVariable2),
        sizeof(pData1->memberVariable4),
        sizeof(pData1->memberVariable8)
    );
    printf("test: %d(%d,%d,%d,%d,%d,%d,%d,%d)\n", sizeof(Data2), 
        sizeof(pData2->memberVariable1),
        sizeof(pData2->memberVariable2),
        sizeof(pData2->memberVariable4),
        sizeof(pData2->memberVariable8),
        sizeof(pData2->memberVariable1U),
        sizeof(pData2->memberVariable2U),
        sizeof(pData2->memberVariable4U),
        sizeof(pData2->memberVariable8U)
    );
    
    
    // typeCastingTest((void*)pData1, DATA1);
    SNode* pNode1 = (SNode*)malloc(sizeof(SNode));
    SNode* pNode2 = (SNode*)malloc(sizeof(SNode));
    pNode1->pData = pData1;
    pNode2->pData = pData2;

    printf("%p",pNode1->pData);

    
    
    free(pData1);
    free(pData2);
    return 0;
}