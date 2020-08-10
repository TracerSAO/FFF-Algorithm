/*
Problem Description
输入一个字符串，判断其是否是C的合法标识符。
 

Input
输入数据包含多个测试实例，数据的第一行是一个整数n,表示测试实例的个数，然后是n行输入数据，每行是一个长度不超过50的字符串。
 

Output
对于每组输入数据，输出一行。如果输入数据是C的合法标识符，则输出"yes"，否则，输出“no”。
 

Sample Input
3
12ajf
fi8x_a
ff  ai_2
 

Sample Output
no
yes
no
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char ch[51];
    int num = 0;

    while (EOF != scanf("%d", &num)) {
        getchar();
        for (int n=0; n<num; n++) {
            memset(ch, 0, sizeof(ch));
            int x=0;
            while ('\n' != (ch[x]=getchar())) { x++; }
            ch[x] = '\0';

            int i = 0;
            for (; i<strlen(ch); i++) {
                if (0 == i && (('A' <= ch[i] && ch[i] <= 'Z') || ('a' <= ch[i] && ch[i] <= 'z') || '_' == ch[i]))
                    continue;
                if (0 != i && (('0' <= ch[i] && ch[i] <= '9') || ('A' <= ch[i] && ch[i] <= 'Z') || ('a' <= ch[i] && ch[i] <= 'z') || '_' == ch[i]))
                    continue;
                break;
            }
            i != strlen(ch) ? printf("no\n") : printf("yes\n");
        }
    }
}