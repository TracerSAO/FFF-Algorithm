/**
 * Problem Description: 根据输入的半径值，计算球的体积。
 * Output: 输出对应的球的体积，对于每组输入数据，输出一行，计算结果保留三位小数。
 * Sample Input: 
 *      1 
 *      1.5
 * Sample Output: 
 *      4.189
 *      14.137
 * Hint: #define PI 3.1415927
*/

#include <stdio.h>
#include <math.h>

#define PI 3.1415927

int main()
{
    double radius;
    while (EOF != scanf("%le", &radius)) {
        printf("%.3lf\n", (4.0 * PI * pow(radius, 3)) / 3);
    }

    return 0;
}
