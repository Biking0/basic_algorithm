// 2019-04-10
// 线性表顺序结构

#include <iostream>

using namespace std;
// 各个方法，返回状态，0，1

// 定义最大长度
#define MAXSIZE 100

// 定义顺序表结构
typedef struct
{
    int *elem;
    int length;
}SqlList;



// 初始化，创建空表
int InitList(SqlList &L)
{
    L.elem=new int[MAXSIZE];
    // 内存溢出，分配失败

    cout<<L.elem<<endl;
//    if(!L.elem) exit(overflow_error);
    L.length=0;
    cout<<'初始化表成功'<<endl;
    return 0;

}


int main()
{
    cout << "Hello World!" << endl;
    SqlList list;

    // 初始化
    InitList(list);

    return 0;
}




