/*
Problem Description
输入一个英文句子，将每个单词的第一个字母改成大写字母。
 

Input
输入数据包含多个测试实例，每个测试实例是一个长度不超过100的英文句子，占一行。
 

Output
请输出按照要求改写后的英文句子。
 

Sample Input
i like acm
i want to get an accepted
 

Sample Output
I Like Acm
I Want To Get An Accepted
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str[101];
    int i = 0;

    while (EOF != (str[i] = getchar())) {
        if ('\n' == str[i]) {
            printf("\n");
            i = 0;
            memset(str, '\0', sizeof(str));
            continue;
        }

        if (0 == i)
            'a' <= str[i] ? printf("%c", str[i]-32) : printf("%c", str[i]);
        else if (' ' == str[i-1])
            'a' <= str[i] ? printf("%c", str[i]-32) : printf("%c", str[i]);
        else printf("%c", str[i]);

        i ++;
    }

    return 0;
}