/*
Problem Description
输入n(n<100)个数，找出其中最小的数，将它与最前面的数交换后输出这些数。
 

Input
输入数据有多组，每组占一行，每行的开始是一个整数n，表示这个测试实例的数值的个数，跟着就是n个整数。n=0表示输入的结束，不做处理。
 

Output
对于每组输入数据，输出交换后的数列，每组输出占一行。
 

Sample Input
4 2 1 3 4
5 5 4 3 2 1
0
 

Sample Output
1 2 3 4
1 4 3 2 5

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 0;

    while (EOF != scanf("%d", &num)) {
        if (0 == num) break;

        int *numList = (int*) malloc(sizeof(int) * num);
        int MIN = 0;
        for (int i=0; i<num; i++) {
            scanf("%d", &numList[i]);
            if (numList[MIN] > numList[i]) MIN = i;
        }
        int temp = numList[MIN];
        numList[MIN] = numList[0];
        numList[0] = temp;

        for (int i=0; i<num; i++)
            (num-1) != i ? printf("%d ", numList[i]) : printf("%d\n", numList[i]);
        free(numList);
    }
}