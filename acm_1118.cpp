/*
租用游艇问题
Time Limit: 1000MS	Memory Limit: 32768K

Description
长江游艇俱乐部在长江上设置了n个游艇出租站1，2，…，n。游客可在这些游艇出租站租用游艇，并在下游的任何一个游艇出租站归还游艇。游艇出租站i到游艇出租站j之间的租金为r(i,j),1≤i

Input
第 1 行中有 1 个正整数 n（n<=200） ，表示有 n个游艇出租站。接下来的n-1 行是r(i,j),1≤i<j≤n。 

Output
输出从游艇出租站1到游艇出租站n所需的最少租金

Sample Input
3 
5 15 
7 

Sample Output
12
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int n; cin>>n;  // n个游艇出租摊位
    int fee[n+1][n+1];  // fee[i][j] 第i个摊位到第j个摊位的费用
    int minFee[n+1];  // minFee[i] 从第1个摊位到第i个摊位的最小花费
    for (int i=1; i<n; i++)
    {
        for (int j=i+1; j<=n; j++)
            cin >> fee[i][j];
    }
    for (int i=2; i<=n; i++)
    {
        minFee[i] = fee[1][i];
        for (int j=2; j<i; j++)
            minFee[i] = min(minFee[i], minFee[j]+fee[j][i]);
    }
    cout << minFee[n] << endl;
    return 0;
}
