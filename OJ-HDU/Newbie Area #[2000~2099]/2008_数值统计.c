/*
Problem Description
统计给定的n个数中，负数、零和正数的个数。
 

Input
输入数据有多组，每组占一行，每行的第一个数是整数n（n<100），表示需要统计的数值的个数，然后是n个实数；如果n=0，则表示输入结束，该行不做处理。
 

Output
对于每组输入数据，输出一行a,b和c，分别表示给定的数据中负数、零和正数的个数。
 

Sample Input
6 0 1 2 3 -1 0
5 1 2 3 4 0.5
0 
 

Sample Output
1 2 3
0 0 5
*/

#include <stdio.h>

int main()
{
    int lessZero = 0, equalZero = 0, greatZero = 0;
    int numList = 0;
    while (EOF != scanf("%d", &numList)) {
        if (0 == numList) break;

        for (int i=0; i<numList; i++) {
            float temp;
            scanf("%f", &temp);

            if (0 == temp)  equalZero ++;
            else if (0 > temp) lessZero ++;
            else if (0 < temp) greatZero ++;
        }
        printf("%d %d %d\n", lessZero, equalZero, greatZero);

        lessZero = equalZero = greatZero = 0;
    }
}