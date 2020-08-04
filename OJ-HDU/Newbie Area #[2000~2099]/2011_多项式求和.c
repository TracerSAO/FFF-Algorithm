/*
Problem Description
多项式的描述如下：
1 - 1/2 + 1/3 - 1/4 + 1/5 - 1/6 + ...
现在请你求出该多项式的前n项的和。
 

Input
输入数据由2行组成，首先是一个正整数m（m<100），表示测试实例的个数，第二行包含m个正整数，对于每一个整数(不妨设为n,n<1000），求该多项式的前n项的和。
 

Output
对于每个测试实例n，要求输出多项式前n项的和。每个测试实例的输出占一行，结果保留2位小数。
 

Sample Input
2
1 2
 

Sample Output
1.00
0.50
*/

#include <stdio.h>

int main()
{
    int count = 0;

    while (EOF != scanf("%d", &count)) {
        for (int i=0; i<count; i++) {
            int agrv;
            scanf("%d", &agrv);

            double sum = 0;
            for (int _value=1; _value<=agrv; _value++) {
                if (_value % 2 != 0) {
                    sum += 1.0 / _value;
                } else {
                    sum -= 1.0 / _value;
                }
            }
            printf("%.2f\n", sum);
        }
    }
}