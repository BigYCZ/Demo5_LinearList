//
// Created by Yuecaizheng on 2020/11/26.
//


#ifndef DEMO5_LINEARLIST_SEQLIST_H
#define DEMO5_LINEARLIST_SEQLIST_H

#endif //DEMO5_LINEARLIST_SEQLIST_H

/**         用数组来描述顺序表
 *          顺序表的结构体如下
 * */
typedef int DataType;
#define ListSize 100        //定义数组大小为100
typedef struct {
    DataType list[ListSize];    //用list存储数据表中的数据元素
    int length;                 //表示顺序表当前的数据元素个数
} SeqList;              //结构体名称SeqList

/** 顺序表的初始化 */
void InitList(SeqList *L) {
    L->length = 0;        //顺序表的长度置为0
}

/** 判断顺序表是否为空  */
int ListEmpty(SeqList L) {
    if (L.length == 0)        //如果顺序表长度为0
        return 1;           //返回1
    else                    //否则
        return 0;           //返回0
}

/** 按序号查找操作。查找操作分为两种：按序号查找和按内容查找。按序号查找就是查找顺序表L中的第i个元素，如果找到将该元素赋值给e  */
/** 查找顺序表中第i个元素 */
int GetElement(SeqList L, int i, DataType *e) {
    if (i < 1 || i > L.length)    //在查找第i个元素之前，判断该序号是否合法
        return -1;               //不合法返回-1
    *e = L.list[i - 1];         //合法 将第i个元素的值赋值给e
    return 1;                  //返回1
}

/** 按内容查找操作 */
int LocateElement(SeqList L, DataType e) {
    for (int i = 0; i < L.length; ++i)  //从第i个元素开始比较
    {
        if (L.list[i] == e)     //找到后将元素e赋值给list
            return i + 1;       //返回i+1
        return 0;
    }
}





