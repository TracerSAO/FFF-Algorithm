/*
Problem Description
输入n(n<=100)个整数，按照绝对值从大到小排序后输出。题目保证对于每一个测试实例，所有的数的绝对值都不相等。
 

Input
输入数据有多组，每组占一行，每行的第一个数字为n,接着是n个整数，n=0表示输入数据的结束，不做处理。
 

Output
对于每个测试实例，输出排序后的结果，两个数之间用一个空格隔开。每个测试实例占一行。
 

Sample Input
3 3 -4 2
4 0 1 2 -3
0
 

Sample Output
-4 3 2
-3 2 1 0

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node
{
    int value;
    bool signal;
} node;

int main()
{
    int num = 0;

    while (EOF != scanf("%d", &num)) {
        if (0 == num) break;

        node *valueList = (node*) malloc(sizeof(node) * num);
        for (int i=0; i<num; i++) {
            scanf("%d", &valueList[i].value);
            if (0 > valueList[i].value) {
                valueList[i].value = -valueList[i].value;
                valueList[i].signal = 1;
            } else valueList[i].signal = 0;
        }

        node temp;   // 临时交换变量
        for (int _time=1; _time<num; _time++) { // 循环判断 num-1 次
            for (int i=0; i< num-1; i++) {      // 从 0 位比较到 num-2 位
                if (valueList[i].value < valueList[i+1].value) {
                    temp = valueList[i];
                    valueList[i] = valueList[i+1];
                    valueList[i+1] = temp;
                }
            }
        }

        for (int i=0; i<num; i++) {
            if (valueList[i].signal) valueList[i].value = -valueList[i].value;
            i != num-1 ? printf("%d ", valueList[i].value) : printf("%d\n", valueList[i].value);
        }
        free(valueList);
    }
}