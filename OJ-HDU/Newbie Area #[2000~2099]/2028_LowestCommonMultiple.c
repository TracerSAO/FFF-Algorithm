/*
Problem Description
求n个数的最小公倍数。
 

Input
输入包含多个测试实例，每个测试实例的开始是一个正整数n，然后是n个正整数。
 

Output
为每组测试数据输出它们的最小公倍数，每个测试实例的输出占一行。你可以假设最后的输出是一个32位的整数。
 

Sample Input
2 4 6
3 2 5 7
 

Sample Output
12
70
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 0;

    while (EOF != scanf("%d", &num)) {
        int *valueList = (int*) malloc(sizeof(int) * num);
        for (int i=0; i<num; i++)
            scanf("%d", &valueList[i]);

        if (1 == num) {
            printf("%d\n", valueList[0]);
            free(valueList);
            continue;
        }

        for (int i=1; i<num; i++) {
            int temp_left = valueList[i-1];
            int temp_right = valueList[i];

            if (temp_left < temp_right) {
                int temp = temp_left;
                temp_left = temp_right;
                temp_right = temp;
            }

            while (0 != (temp_left % temp_right)) {
                int left = temp_right;
                int right = temp_left % temp_right;
                temp_left = left;
                temp_right = right;
            }

            int MinimumCommonDivisor = temp_right;
            temp_left = valueList[i-1] / MinimumCommonDivisor;
            temp_right = valueList[i] / MinimumCommonDivisor;
            valueList[i] = MinimumCommonDivisor * temp_left * temp_right;
        }
        printf("%d\n", valueList[num-1]);

        free(valueList);
    }

    return 0;
}