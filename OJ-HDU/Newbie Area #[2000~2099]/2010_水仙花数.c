/*
Problem Description
春天是鲜花的季节，水仙花就是其中最迷人的代表，数学上有个水仙花数，他是这样定义的：
“水仙花数”是指一个三位数，它的各位数字的立方和等于其本身，比如：153=1^3+5^3+3^3。
现在要求输出所有在m和n范围内的水仙花数。
 

Input
输入数据有多组，每组占一行，包括两个整数m和n（100<=m<=n<=999）。
 

Output
对于每个测试实例，要求输出所有在给定范围内的水仙花数，就是说，输出的水仙花数必须大于等于m,并且小于等于n，如果有多个，则要求从小到大排列在一行内输出，之间用一个空格隔开;
如果给定的范围内不存在水仙花数，则输出no;
每个测试实例的输出占一行。
 

Sample Input
100 120
300 380
 

Sample Output
no
370 371
*/

#include <stdio.h>
#include <math.h>

int main()
{
    int start = 0, end = 0;

    while (EOF != scanf("%d %d", &start, &end)) {
        int value = 0, signal = 0;
        for (value=start; value<=end; value++) {
            int a, b, c;
            a = value / 100;
            b = value % 100 / 10;
            c = value % 100 % 10;

            if (pow(a, 3) + pow(b, 3) + pow(c, 3) == value) {
                if (!signal) {
                    printf("%d", value);
                    signal = 1;
                } else {
                    printf(" %d", value);
                }
            }
        }
        if (!signal) printf("no");
        printf("\n");
    }

    return 0;
}