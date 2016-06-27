/*
1080: 最长公共子序列
时间限制: 1 Sec  内存限制: 128 MB
提交: 131  解决: 35
[提交][状态][讨论版]
题目描述
给定两个序列X={x1,x2,...,xn}和Y={y1,y2,...yn},求X和Y的最长公共子序列的长度。

输入
两个字符串X和Y。

输出
输出X和Y的最长公共子序列的长度。

样例输入
abcbdab
bdcaba
样例输出
4
*/

#include <iostream>
#include <stdio.h>
#define MAX 1001
using namespace std;
 
int publicMax[MAX][MAX];  // .[i][j] 表示序列a[0:i]与序列b[0:j]的最长公共子序列
 
int main()
{
    string a, b;
    cin >> a >> b;
    unsigned long a_length = a.length();
    unsigned long b_length = b.length();
    a = " " + a;
    b = " " + b;
    for (int i=1; i<=a_length; i++)  // 填表 
    {
        for (int j=1; j<=b_length; j++)
        {
            if (publicMax[i-1][j]==publicMax[i][j-1] && b[j]==a[i])
            {
                publicMax[i][j] = publicMax[i-1][j] + 1;
            }
            else
            {
                publicMax[i][j] = max(publicMax[i-1][j], publicMax[i][j-1]);
            }
        }
    }
    cout << publicMax[a_length][b_length] << endl;
    return 0;
}
