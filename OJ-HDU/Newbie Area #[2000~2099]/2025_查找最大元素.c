/*
Problem Description
对于输入的每个字符串，查找其中的最大字母，在该字母后面插入字符串“(max)”。
 

Input
输入数据包括多个测试实例，每个实例由一行长度不超过100的字符串组成，字符串仅由大小写字母构成。
 

Output
对于每个测试实例输出一行字符串，输出的结果是插入字符串“(max)”后的结果，如果存在多个最大的字母，就在每一个最大字母后面都插入"(max)"。
 

Sample Input
abcdefgfedcba
xxxxx
 

Sample Output
abcdefg(max)fedcba
x(max)x(max)x(max)x(max)x(max)
*/

#include <stdio.h>

int main()
{
    char chList[101];
    char chMAX;

    while (EOF != scanf("%s", chList)) {
        chMAX = 'A';
        for (int i=0; chList[i]!='\0'; i++)
            chMAX = (chMAX < chList[i] ? chList[i] : chMAX);
        for (int i=0; chList[i]!='\0'; i++)
            chMAX == chList[i] ? printf("%c(max)", chList[i]) : printf("%c", chList[i]); 
        printf("\n");
    }

    return 0;
}