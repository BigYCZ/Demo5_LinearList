//
// Created by Yuecaizheng on 2020/11/27.
//
/** 示例：利用线性表的基本运算，实现如果在线性表 A中出现的元素，在线性表 B中也出现，则将 A中的该元素删除。 */
/** 分析：这其实是求两个表的差集，即 A-B。依次检查线性表 B中的每个元素，如果该元素在线性表 A中也出现，则在 A删除该元素 */
#include "stdio.h"
#include "SeqList.h"
#define ListSize 100
typedef int DateType;





