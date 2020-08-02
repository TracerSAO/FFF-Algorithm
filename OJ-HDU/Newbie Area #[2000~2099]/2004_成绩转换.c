
/*
Problem Description
输入一个百分制的成绩t，将其转换成对应的等级，具体转换规则如下：
90~100为A;
80~89为B;
70~79为C;
60~69为D;
0~59为E;
 

Input
输入数据有多组，每组占一行，由一个整数组成。
 

Output
对于每组输入数据，输出一行。如果输入数据不在0~100范围内，请输出一行：“Score is error!”。
 

Sample Input
56
67
100
123
 

Sample Output
E
D
A
Score is error!
*/

#include <stdio.h>

int main()
{
    int grade;
    while (EOF != scanf("%d", &grade)) {
        if (0 > grade || grade > 100)
            printf("Score is error!\n");
        else if (60 > grade) printf("E\n");
        else if (70 > grade) printf("D\n");
        else if (80 > grade) printf("C\n");
        else if (90 > grade) printf("B\n");
        else if (100 > grade) printf("A\n");
    }

    return 0;
}