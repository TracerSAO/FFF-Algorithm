/*
Problem Description
对于表达式n^2+n+41，当n在（x,y）范围内取整数值时（包括x,y）(-39<=x<y<=50)，判定该表达式的值是否都为素数。
 

Input
输入数据有多组，每组占一行，由两个整数x，y组成，当x=0,y=0时，表示输入结束，该行不做处理。
 

Output
对于每个给定范围内的取值，如果表达式的值都为素数，则输出"OK",否则请输出“Sorry”,每组输出占一行。
 

Sample Input
0 1
0 0
 

Sample Output
OK
*/


#include <stdio.h>
#include <math.h>

int main()
{
    int x = 0, y = 0;

    while (EOF != scanf("%d %d", &x, &y)) {
        if (0 == x && 0 == y)
            break;

        int signal = 0;
        for (int _value=x; _value<=y; _value++) {
            int temp = _value*_value + _value + 41;
            for (int i=2; i<= (int)sqrt(temp); i++) {
                if (temp % i == 0) {
                    signal = 1;
                    break;
                }
            }
            if (signal) {
                printf("Sorry\n");
                break;
            }
        }
        if (!signal) printf("OK\n");
    }

    return 0;
}