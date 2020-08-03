/*
Problem Description
给定一个日期，输出这个日期是该年的第几天。
 

Input
输入数据有多组，每组占一行，数据格式为YYYY/MM/DD组成，具体参见sample input ,另外，可以向你确保所有的输入数据是合法的。
 

Output
对于每组输入数据，输出一行，表示该日期是该年的第几天。
 

Sample Input
1985/1/20
2006/3/12
 

Sample Output
20
71

*/

/*
    1 3 5 7 8 10 12 -> 31
    2 判断闰年 Y=28 : N=29
    4 6 9 11 -> 30
*/

#include <stdio.h>

int main()
{
    int monthList[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int year, month, day;

    while(EOF != scanf("%d/%d/%d", &year, &month, &day)) {
        if ((year%4 == 0 && year%100 != 0) || (year%400 == 0))
            monthList[1] = 29;
        else monthList[1] = 28;

        int sum = 0;
        for (int i=0; i< month - 1; i++)
            sum += monthList[i];
        sum += day;
        printf("%d\n", sum);
    }
}


// #include <stdio.h>
// void main()
// {
//     int year,month,day,numday;
//     printf("please inpute a date yyyy/mm/dd\n");
//     scanf("%d/%d/%d",&year,&month,&day);

//     numday=day;
//     for(int i=1;i<month;i++)
//         switch (i)
//         {
//         case 1:
//         case 3:
//         case 5:
//         case 7:
//         case 8:
//         case 10:
//         case 12:
//             numday+=31;
//             break;
//         case 4:
//         case 6:
//         case 9:
//         case 11:
//             numday+=30;
//             break;
//         case 2:
//             if((year%4==0 && year%100 !=0) || year%400==0)
//                 numday+=29;
//             else
//                 numday+=28;
//         };

//     printf("\n%d\n",numday);
// }