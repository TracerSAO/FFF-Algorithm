/*
Problem Description
假设一个班有n(n<=50)个学生，每人考m(m<=5)门课，求每个学生的平均成绩和每门课的平均成绩，并输出各科成绩均大于等于平均成绩的学生数量。
 

Input
输入数据有多个测试实例，每个测试实例的第一行包括两个整数n和m，分别表示学生数和课程数。然后是n行数据，每行包括m个整数（即：考试分数）。
 

Output
对于每个测试实例，输出3行数据，第一行包含n个数据，表示n个学生的平均成绩，结果保留两位小数；第二行包含m个数据，表示m门课的平均成绩，结果保留两位小数；第三行是一个整数，表示该班级中各科成绩均大于等于平均成绩的学生数量。
每个测试实例后面跟一个空行。
 

Sample Input
2 2
5 10
10 20
 

Sample Output
7.50 15.00
7.50 15.00
1

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int student = 0, subject = 0;

    while (EOF != scanf("%d %d", &student, &subject)) {
        int **stuPoint = (int**) malloc(sizeof(int*) * student);
        for (int stu=0; stu<student; stu++) {
            stuPoint[stu] = (int*) malloc(sizeof(int) * (subject+1));
            stuPoint[stu][subject] = 0;
        }

        double *subTotalList = (double*) malloc(sizeof(double) * subject);
        for (int sub=0; sub<subject; sub++)
            subTotalList[sub] = 0;
        for (int stu=0; stu<student; stu++) {           // 存储所有学生的各科成绩，同时计算学生的总成绩
            for (int sub=0; sub<subject; sub++) {
                scanf("%d", &stuPoint[stu][sub]);
                stuPoint[stu][subject] += stuPoint[stu][sub];
                subTotalList[sub] += stuPoint[stu][sub];
            }
        }

        for (int sub=0; sub<subject; sub++)             // 计算各个科目的平均成绩
            subTotalList[sub] = subTotalList[sub] / (double)student;

        int sum = 0;
        for (int stu=0; stu<student; stu++) {
            for (int sub=0; sub<subject; sub++) {
                if (stuPoint[stu][sub] < subTotalList[sub])
                    break;
                if (subject-1 == sub)
                    sum++;
            }
        }

        for (int stu=0; stu<student; stu++)
            student-1 != stu ? printf("%.2lf ", stuPoint[stu][subject] / (double)subject) : printf("%.2lf\n", stuPoint[stu][subject] / (double)subject);
        for (int sub=0; sub<subject; sub++)
            subject-1 != sub ? printf("%.2lf ", subTotalList[sub]) : printf("%.2lf\n", subTotalList[sub]);
        printf("%d\n\n", sum);

        for (int stu=0; stu<student; stu++)
            free(stuPoint[stu]);
        free(stuPoint);
        free(subTotalList);
    }

    return 0;
}