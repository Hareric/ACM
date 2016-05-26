/*
Description
设I是一个 n位十进制整数。如果将I划分为 k段，则可得到k个整数。这k个整数的 乘积称为I的一个 k乘积。试设计一个算法，对于给定的 I和 k，求出 I的最大 k乘积。 对于给定的I和k，计算 I的最大 k乘积。
Input
第1 行中有2个正整数n和 k。正整数 n是序列
的长度；正整数k是分割的段数。接下来的一行中是一个n位十进制整数。（n<=10） 
Output
输出最大k乘积
Sample Input
2 1 
15 
Sample Output
15
*/

# include <iostream>
# include <cmath>
using namespace std;
int main()
{
    int n, k, num;  // n位数num分为k段
    cin>>n>>k>>num;
    if (!(n>0&&k>0&&k<=n))
    {
        cout<<0<<endl;
        return -1;
    }
    if (k==1)
    {
        cout<<num<<'\n';
        return 0;
    }
    int nums[n+1][n+1]; // num[i][j]表示输入的整数的第i位至第j位组成的数值
    for(int i=1;i<=n;i++)
    {
        int p = 10;
        for(int j=i;j<=n;j++)
        {
            nums[i][j]=num % p;
            p *= 10;
        }
        num /= 10;
    }
    int k_max[n+1][k+1];  // k_max[i][j] 表示前i个数分为j段的最大k乘积
    for (int i=0; i<=n; i++)
    {
        for (int j=0; j<=k; j++)
        {
            k_max[i][j] = 0;  // 初始化
        }
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=i && j<=k; j++)
        {
            if (j==1)
            {
                k_max[i][j] = nums[1][i];
            }
            else
            {
                for (int z=j-1; z<i; z++)
                {
                    k_max[i][j] = max(k_max[i][j], k_max[z][j-1]*nums[z+1][i]);
                }
            }
        }
    }
//      for(int i=1; i<=n; i++)
//      {
//              for(int j=i; j<=n; j++)
//              {
//                      cout<<nums[i][j]<<' ';
//              }
//              cout<<endl;
//      }
    cout<<k_max[n][k]<<endl;
    return 0;
}
