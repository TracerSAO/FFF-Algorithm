/*
Problem Description
“回文串”是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。请写一个程序判断读入的字符串是否是“回文”。
 

Input
输入包含多个测试实例，输入数据的第一行是一个正整数n,表示测试实例的个数，后面紧跟着是n个字符串。
 

Output
如果一个字符串是回文串，则输出"yes",否则输出"no".
 

Sample Input
4
level
abcde
noon
haha
 

Sample Output
yes
no
yes
no
*/

#include <stdio.h>
#include <string.h>

int main()
{
    int num = 0;
    char str[100];

    while (EOF != scanf("%d", &num)) {
        for (int NO=0; NO<num; NO++) {
            getchar();
            scanf("%s", str);

            int length = strlen(str);
            int leftStr = 0, rightStr = length - 1;
            while (leftStr <= rightStr) {
                if (str[leftStr] == str[rightStr]) {
                    leftStr ++;
                    rightStr --;
                }
                else break;
            }

            leftStr > rightStr ? printf("yes\n") : printf("no\n");
        }
    }
}