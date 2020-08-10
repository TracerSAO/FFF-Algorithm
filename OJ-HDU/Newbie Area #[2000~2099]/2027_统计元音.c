/*
Problem Description
统计每个元音字母在字符串中出现的次数。
 

Input
输入数据首先包括一个整数n，表示测试实例的个数，然后是n行长度不超过100的字符串。
 

Output
对于每个测试实例输出5行，格式如下：
a:num1
e:num2
i:num3
o:num4
u:num5
多个测试实例之间由一个空行隔开。

请特别注意：最后一块输出后面没有空行：）
 

Sample Input
2
aeiou
my name is ignatius
 

Sample Output
a:1
e:1
i:1
o:1
u:1

a:2
e:1
i:3
o:0
u:1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int num = 0;

    while (EOF != scanf("%d", &num)) {
        int **strList = (int**) malloc(sizeof(int*) * num);
        for (int i=0; i<num; i++) {
            strList[i] = (int*) malloc(sizeof(int) * 5);
            memset(strList[i], 0, sizeof(int) * 5);
        }

        getchar();
        for (int i=0; i<num; i++) {
            char ch = '\0';
            while ('\n' != (ch = getchar())) {
                if ('a' == ch || 'A' == ch)
                    strList[i][0] ++;
                else if ('e' == ch || 'E' == ch)
                    strList[i][1] ++;
                else if ('i' == ch || 'I' == ch)
                    strList[i][2] ++;
                else if ('o' == ch || 'O' == ch)
                    strList[i][3] ++;
                else if ('u' == ch || 'U' == ch)
                    strList[i][4] ++;
            }
        }

        for (int i=0; i<num; i++) {
            printf("a:%d\n", strList[i][0]);
            printf("e:%d\n", strList[i][1]);
            printf("i:%d\n", strList[i][2]);
            printf("o:%d\n", strList[i][3]);
            printf("u:%d\n", strList[i][4]);
            if (i != num-1) printf("\n");
        }

        for (int i=0; i<num; i++)
            free(strList[i]);
        free(strList);
    }

    return 0;
}