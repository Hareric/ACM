/*
Description
给定一个由n行数字组成的数字三角形如下图所示。试设计一个算法，计算出从三角形的顶至底的一条路径，使该路径经过的数字总和最大。 7 3 8 8 1 0 2 7 4 4 4 5 2 6 5 对于给定的由 n行数字组成的数字三角形， 计算从三角形的顶至底的路径经过的数字和的最大值。
Input
第 1 行是数字三角形的行数 n，1≤n≤100。接下来n行是数字三角形各行中的数字。所有数字在0..99之间。 
Output
输出最大值
Sample Input
5 
7 
3 8 
8 1 0  
2 7 4 4 
4 5 2 6 5
Sample Output
30
*/

#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
 
int main()
{
    int n; scanf("%d", &n);  // n层三角形
    int trangle_array[n+1][n+1];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=i; j++)
            cin>>trangle_array[i][j];
    int trangle_max[n+1][n+1];  // [i][j] 记录从底端到 第i层 的第j个数的最大路径
    memset(trangle_max, 0, sizeof(trangle_max));
    for (int i=1; i<=n; i++)
        trangle_max[n][i] = trangle_array[n][i];  // 将最后一层先填好
    for (int i=n-1; i>0; i--)
    {
        for (int j=1; j<=n; j++)
        {
            trangle_max[i][j] = max(trangle_max[i+1][j], trangle_max[i+1][j+1]) + trangle_array[i][j];
        }
    }
    cout<<trangle_max[1][1]<<endl;
    return 0;
}
