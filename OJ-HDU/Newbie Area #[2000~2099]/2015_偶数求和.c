/*
Problem Description
有一个长度为n(n<=100)的数列，该数列定义为从2开始的递增有序偶数，现在要求你按照顺序每m个数求出一个平均值，如果最后不足m个，则以实际数量求平均值。编程输出该平均值序列。
 

Input
输入数据有多组，每组占一行，包含两个正整数n和m，n和m的含义如上所述。
 

Output
对于每组输入数据，输出一个平均值序列，每组输出占一行。
 

Sample Input
3 2
4 2
 

Sample Output
3 6
3 7
*/

#include <stdio.h>

int main()
{
    int num = 0, interval = 0;
    while (EOF != scanf("%d %d", &num, &interval)) {
        int sum = 0;
        for (int i=1; i<=num; i++) {
            sum += 2 * i;

            if (i == num)
                0 == (num%interval) ? printf("%d\n", sum/interval) : printf("%d\n", sum / (num%interval));
            else if (0 == i%interval) {
                sum /= interval;
                printf("%d ", sum);
                sum = 0;
            }
        }
    }
}