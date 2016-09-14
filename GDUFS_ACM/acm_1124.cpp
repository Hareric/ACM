/*
矩阵连乘问题
Time Limit: 1000MS	Memory Limit: 32768K

Description
给定n个矩阵{A1,A2,…,An}，其中Ai与Ai+1是可乘的，i=1,2,…,n-1。要算出这n个矩阵的连乘积A1A2…An。由于矩阵乘法满足结合律，故计算矩阵的连乘积可以有许多不同的计算次序。这种计算次序可以用加括号的方式来确定。若一个矩阵连乘积的计算次序完全确定，也就是说该连乘积已完全加括号，则可以依此次序反复调用2个矩阵相乘的标准算法计算出矩阵连乘积。完全加括号的矩阵连乘积可递归地定义为： （1）单个矩阵是完全加括号的； （2）矩阵连乘积A是完全加括号的，则A可表示为2个完全加括号的矩阵连乘积B和C的乘积并加括号，即A=(BC)。对于给定的相继n个矩阵{A1,A2,…,An}（其中矩阵Ai的维数为pi-1×pi，i＝1,2,…,n），如何确定计算矩阵连乘积A1A2…An的计算次序（完全加括号方式），使得依此次序计算矩阵连乘积需要的数乘次数最少。	

Input
第1行为n值，表示n个矩阵
接下来的n行，每行一个数值，顺序表示Ai(1≤i≤n)矩阵的行数
最后一行表示An矩阵的列数

Output
输出矩阵连乘积A1A2…An的最小计算次数

Sample Input
6
30
35
15
5
10
20
25

Sample Output
15125

*/
#include <iostream>
#include <stdio.h>
#define MAX 1001
using namespace std;

int matrix[MAX+1];  // matrix[i]与matrix[i+1]分别表示第i个矩阵的行数和列数
int minTime[MAX][MAX];  // minTime[i][j]表示第i个矩阵到第j个矩阵的最小乘积数
int main()
{
    int n; cin >> n;  // 矩阵的个数

    for (int i=1; i<=n+1; i++)
        cin >> matrix[i];
    for (int i=1; i<n; i++)
        minTime[i][i+1] = matrix[i] * matrix[i+1] * matrix[i+2];
    for (int i=3; i<=n; i++)  // 对表的上半部分填表，从左下往右上的方向填表
    {
        for (int j=1; i+j-1<=n; j++)
        {
            minTime[j][i+j-1] = minTime[j+1][i+j-1] + matrix[j]*matrix[j+1]*matrix[i+j];
            for (int t=i+j-2; t>j; t--)
            {
                minTime[j][i+j-1] = min(minTime[j][i+j-1], minTime[j][t]+minTime[t+1][i+j-1]+matrix[j]*matrix[t+1]*matrix[i+j]);
            }
        }
    }
//    for (int i=1; i<= n; i++)
//        cout << matrix[i] <<" "<< matrix[i+1] << ";";
//    cout<<endl;
//    for (int i=1; i<=n; i++)
//    {
//        for (int j=1; j<=n; j++)
//            printf("%5d ", minTime[i][j]);
//        cout << endl;
//    }
    cout << minTime[1][n] << endl;
}
