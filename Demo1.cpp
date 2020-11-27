//
// Created by Yuecaizheng on 2020/11/27.
//

/** 示例：利用线性表的基本运算，实现如果在线性表 A中出现的元素，在线性表 B中也出现，则将 A中的该元素删除。 */
/** 分析：这其实是求两个表的差集，即 A-B。依次检查线性表 B中的每个元素，如果该元素在线性表 A中也出现，则在 A删除该元素 */
#include "stdio.h"
#include "main.cpp" //引入main源文件中的增加、删除、销毁数组的方法

typedef int DateType;

/** 求 A-B的差集算法如下  */
/** 求 A-B 即在 A中依次查找 B中各元素，若该元素在 A中出现，则删除 */
void DeleteElement(SeqList *A, SeqList B) {
    int flag, pos;
    DateType e;
    for (int i = 1; i < B.length; ++i) {
        flag = GetElement(B, i, &e);    //依次把B中每个元素取出给e
        if (flag == 1) {
            pos = LocateElement(*A, e);     //在A中查找元素e
            if (pos > 0)                    //如果元素存在
                DeleteList(A, pos, &e);     //将其从A中删除
        }
    }
}

/** 测试程序如下： */
void DeleteElement(SeqList *A, SeqList B);      //删除函数声明

int main() {
    int flag;
    DateType e;
    SeqList A, B;       //声明顺序表A和B
    InitList(&A);       //初始化顺序表A
    InitList(&B);       //初始化顺序表B
    for (int i = 1; i <= 10; i++) {
        if (InsertList(&A, i, i + 10) == 0) {   //将10个数据插入到顺序表A中
            printf("插入位置不合法1\n");
            return 0;
        }
    }
    for (int i = 1, j = 1; j <= 6; i = i + 2, j++) {    //插入到几个数据到顺序表B中
        if (InsertList(&B, j, i * 2) == 0) {
            printf("插入位置不合法2\n");
            return 0;
        }
    }
    printf("顺序表A中的元素：\n");
    for (int i = 0; i < A.length; ++i) {    //输出顺序表A中的每个元素
        flag = GetElement(A, i, &e);        //返回顺序表A中的每个元素到e中
        if (flag == 1)
            printf("%4d", e);
    }
    printf("\n");
    printf("顺序表B中的元素：\n");
    for (int i = 0; i < B.length; ++i) {     //输出顺序表B中的每个元素
        flag = GetElement(B, i, &e);        //返回顺序表B中的每个元素到e中
        if (flag == 1)
            printf("%4d", e);
    }
    printf("\n");
    printf("将在A中出现B的元素删除后，A中的元素（即A-B）：\n");
    DeleteElement(&A, B);                   //将在顺序表中A中出现的B的元素删除
    for (int i = 0; i < A.length; ++i) {    //显示输出删除后A中所有元素
        flag = GetElement(A, i, &e);
        if (flag == 1)
            printf("%4d,", e);
    }
    ClearList(&A);
    ClearList(&B);
    printf("\n");
}


