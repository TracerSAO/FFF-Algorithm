/*
Problem Description
有n(n<=100)个整数，已经按照从小到大顺序排列好，现在另外给一个整数x，请将该数插入到序列中，并使新的序列仍然有序。
 

Input
输入数据包含多个测试实例，每组数据由两行组成，第一行是n和m，第二行是已经有序的n个数的数列。n和m同时为0标示输入数据的结束，本行不做处理。
 

Output
对于每个测试实例，输出插入新的元素后的数列。
 

Sample Input
3 3
1 2 4
0 0
 

Sample Output
1 2 3 4
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 0, value = 0;
    while (EOF != scanf("%d %d", &num, &value)) {
        if (0 == num && 0 == value) break;

        int *valueList = (int*) malloc(sizeof(int) * num);
        for (int i=0; i<num; i++)
            scanf("%d", &valueList[i]);

        int signal = 0;
        for (int i=0; i<num; i++) {
            if (value < valueList[i]) {
                if (!signal)  {
                    printf("%d %d", value, valueList[i]);
                    signal = 1;
                } else printf("%d", valueList[i]);
            } else if (value == valueList[i]) {
                if (!signal)  {
                    printf("%d %d", value, value);
                    signal = 1;
                } else  printf("%d", valueList[i]);
            } else if (value > valueList[i]) {
                i < num-1 ? printf("%d", valueList[i]) : printf("%d %d", valueList[i], value);
            }

            i < num-1 ? printf(" ") : printf("\n");
        }
        free(valueList);
    }
}