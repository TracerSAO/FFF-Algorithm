/*
Problem Description
青年歌手大奖赛中，评委会给参赛选手打分。选手得分规则为去掉一个最高分和一个最低分，然后计算平均得分，请编程输出某选手的得分。
 

Input
输入数据有多组，每组占一行，每行的第一个数是n(2<n<=100)，表示评委的人数，然后是n个评委的打分。
 

Output
对于每组输入数据，输出选手的得分，结果保留2位小数，每组输出占一行。
 

Sample Input
3 99 98 97
4 100 99 98 97
 

Sample Output
98.00
98.50

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 0;

    while (EOF != scanf("%d", &num)) {
        int *judgmentList = (int*) malloc(sizeof(int) * num);
        for (int i=0; i<num; i++)
            scanf("%d", &judgmentList[i]);

        int MAX, MIN;
        MAX = MIN = 0;
        for (int i=1; i<num; i++) {
            if (judgmentList[MAX] < judgmentList[i])
                MAX = i;
            else if (judgmentList[MIN] > judgmentList[i])
                MIN = i;
        }

        int sum = 0;
        for (int i=0; i<num; i++) {
            if (i == MAX || i == MIN)
                continue;
            sum += judgmentList[i];
        }
        free(judgmentList);
        printf("%.2f\n", (1.0*sum) / (num-2.0));
    }
}