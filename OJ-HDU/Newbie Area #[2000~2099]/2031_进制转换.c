/*
Problem Description
输入一个十进制数N，将它转换成R进制数输出。
 

Input
输入数据包含多个测试实例，每个测试实例包含两个整数N(32位整数)和R（2<=R<=16, R<>10）。
 

Output
为每个测试实例输出转换后的数，每个输出占一行。如果R大于10，则对应的数字规则参考16进制（比如，10用A表示，等等）。
 

Sample Input
7 2
23 12
-4 3
 

Sample Output
111
1B
-11
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 0, R = 0;

    while (EOF != scanf("%d %d", &num, &R)) {
        if (0 > num) { 
            num = -num;
            printf("-");
        }

        int size = 1, _R = R; 
        for (; num>=_R; size++) 
            _R *= R;
        int *str = (int*) malloc(sizeof(int) * size);

        for (size=0; 0 != num; size++) {
            str[size] = num % R;
            num /= R;
        }

        for (int NO=size-1; NO>=0; NO--) {
            if (10 > str[NO])
                printf("%d", str[NO]);
            else
                printf("%c", 'A' + (str[NO] - 10));
        }
        printf("\n");

        free(str);
    }

    return 0;
}


