/*
Problem Description
给定一段连续的整数，求出他们中所有偶数的平方和以及所有奇数的立方和。
 

Input
输入数据包含多组测试实例，每组测试实例包含一行，由两个整数m和n组成。
 

Output
对于每组输入数据，输出一行，应包括两个整数x和y，分别表示该段连续的整数中所有偶数的平方和以及所有奇数的立方和。
你可以认为32位整数足以保存结果。
 

Sample Input
1 3
2 5
 

Sample Output
4 28
20 152

*/

#include <stdio.h>

int main()
{
    int sum_2 = 0, sum_3 = 0;
    int temp_start = 0, temp_end = 0;

    while (EOF != scanf("%d %d", &temp_start, &temp_end)) {
        if (temp_start > temp_end) {
            int n = temp_start;
            temp_start = temp_end;
            temp_end = n;
        }
        for (int i=temp_start; i<=temp_end; i++) {
            if (0 == i%2)
                sum_2 += i * i;
            else sum_3 += i * i * i;
        }
        printf("%d %d\n", sum_2, sum_3);
        sum_2 = 0, sum_3 = 0;
    }
}
