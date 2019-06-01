#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

using namespace std;

//5����������
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1

//���Գ��򳤶ȶ���
#define LONGTH 5

//���Ͷ���
typedef int Status;
typedef int ElemType;

//˳��ջ������
typedef struct {
    ElemType *elem;
    int length;
    int size;
    int increment;
} SqList;

Status Print_Sq(SqList &L);
Status InitList_Sq(SqList &L, int size, int inc);
Status Append_Sq(SqList &L,ElemType e);

// ��ӡ��
Status Print_Sq(SqList &L){
    printf("��ӡ��\n");
    for(int i=0;i<L.length;i++){
        printf("%d\t",L.elem[i]);
    }
}

// ��ʼ��
Status InitList_Sq(SqList &L, int size, int inc){
    L.elem = (ElemType *)malloc(size * sizeof(ElemType));
    if (NULL == L.elem) return OVERFLOW;
    L.length = 0;
    L.size = size;
    L.increment = inc;
    return OK;
}
// ��β����Ԫ��
Status Append_Sq(SqList &L, ElemType e){
//    printf("����Ԫ��");
//    printf("%d\n",e);
    // �Ƿ�����
    if(L.length>=L.size) return ERROR;
    L.elem[L.length]=e;
    L.length++;
    return OK;
}


int main()
{
    //�����L
    SqList L;

    //�������ֵ
    int size, increment, i;

    //��ʼ������ֵ
    size = LONGTH;
    increment = LONGTH;
    ElemType e, eArray[LONGTH] = { 1, 2, 3, 4, 5 };

    //��ʾ����ֵ
    printf("---��˳��ջ��---\n");
    printf("��L��sizeΪ��%d\n��L��incrementΪ��%d\n", size, increment);
    printf("������Ԫ��Ϊ��\n");
    for (i = 0; i < LONGTH; i++) {
        printf("%d\t", eArray[i]);
    }
    printf("\n");

    //��ʼ��˳���
    if (!InitList_Sq(L, size, increment)) {
        printf("��ʼ��˳���ʧ��\n");
        exit(0);
    }
    printf("�ѳ�ʼ��˳���\n");

    // ����Ԫ��
    for(i=0;i<LONGTH;i++){
        if(ERROR==Append_Sq(L,eArray[i])) printf("���ʧ��\n");
    }

    // ��ӡ��
    Print_Sq(L);                                    

    return 0;
}
