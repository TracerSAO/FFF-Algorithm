#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

/**
 * valueList[] -> 存储幂集集合中子集所包含的元素
 * signalList[] -> 标志作用，与 valueList[] 数组在下标上一一对应，表示 x 元素是否存在与 y 子集中
 * 
 * 思路：幂集问题，就是寻找幂集中有多少子集，并且将其表示出来的问题，
 *      简单点看，就是元素是否存在的问题  --->  这样就跟 “二进制” 挂上勾了。
 * 将每个数组都看作二进制上的一个位，那么，n 个元素，就是 n 个位，也就是说，有 2^n 种情况（子集）
 * 首先要明确，我们要把这些数据都输出出来，那就要使用 2^n 次 printf ，因为每个子集获取到的方法肯定都一样，
 * 也就是说，我们要重复进行 2^n 次这种操作，恩恩，就是 2^n 次循环嘛
 * OK-> 第一层训话确定，循环 2^n
 * 
 * 再来看，要如何获取每种子集，答案很简单：给你一个长度为 n 位的二进制数，让你把所有的情况写出来，你要怎么写？
 * 那，上面你怎么写完 n 位二进制数的所有形式的，你就怎么来设计算法来获取
 * 注意，要是用 signalList 来表示 0/1 
 * 
 * 。。。 感觉解释的好潦草，emmm，是给自己看的，那么较真了，能帮自己回忆起来就 OK
*/

void fun(int valueList[], bool signalList[], const int num);
void _fun(bool signalList[], const int num);

int main()
{
    int valueList[3] = { 1, 2, 3 };
    bool signalList[3];
    memset(signalList, 0, sizeof(signalList));

    int num = sizeof(valueList) / sizeof(int);
    fun(valueList, signalList, num);

    return 0;
}

void fun(int valueList[], bool signalList[], const int num)
{
    int count = (int)pow(2, num);
    for (int i=0; i<count; i++) {
        printf("{ ");
        for (int j=0; j<num; j++) {
            if (signalList[j])
                printf("%d ", valueList[j]);
        }
        printf("} ");
        _fun(signalList, num);
    }
    
    printf("\n");
}

void _fun(bool signalList[], const int num)
{
    for (int i=0; i<num; i++) {
        if (signalList[i]) signalList[i] = 0;
        else {
            signalList[i] = 1;
            break;
        }
    }
}
