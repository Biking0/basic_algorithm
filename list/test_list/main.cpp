#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

using namespace std;

//5个常量定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1

//测试程序长度定义
#define LONGTH 5

//类型定义
typedef int Status;
typedef int ElemType;

//顺序栈的类型
typedef struct {
    ElemType *elem;
    int length;
    int size;
    int increment;
} SqList;

Status Print_Sq(SqList &L);
Status InitList_Sq(SqList &L, int size, int inc);
Status Append_Sq(SqList &L,ElemType e);

// 打印表
Status Print_Sq(SqList &L){
    printf("打印表\n");
    for(int i=0;i<L.length;i++){
        printf("%d\t",L.elem[i]);
    }
}

// 初始化
Status InitList_Sq(SqList &L, int size, int inc){
    L.elem = (ElemType *)malloc(size * sizeof(ElemType));
    if (NULL == L.elem) return OVERFLOW;
    L.length = 0;
    L.size = size;
    L.increment = inc;
    return OK;
}
// 表尾插入元素
Status Append_Sq(SqList &L, ElemType e){
//    printf("插入元素");
//    printf("%d\n",e);
    // 是否已满
    if(L.length>=L.size) return ERROR;
    L.elem[L.length]=e;
    L.length++;
    return OK;
}


int main()
{
    //定义表L
    SqList L;

    //定义测量值
    int size, increment, i;

    //初始化测试值
    size = LONGTH;
    increment = LONGTH;
    ElemType e, eArray[LONGTH] = { 1, 2, 3, 4, 5 };

    //显示测试值
    printf("---【顺序栈】---\n");
    printf("表L的size为：%d\n表L的increment为：%d\n", size, increment);
    printf("待测试元素为：\n");
    for (i = 0; i < LONGTH; i++) {
        printf("%d\t", eArray[i]);
    }
    printf("\n");

    //初始化顺序表
    if (!InitList_Sq(L, size, increment)) {
        printf("初始化顺序表失败\n");
        exit(0);
    }
    printf("已初始化顺序表\n");

    // 插入元素
    for(i=0;i<LONGTH;i++){
        if(ERROR==Append_Sq(L,eArray[i])) printf("入表失败\n");
    }

    // 打印表
    Print_Sq(L);                                    

    return 0;
}
