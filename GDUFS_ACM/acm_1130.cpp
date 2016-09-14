/*
Description
设计一个O(n2)时间的算法，找出由n个数组成的序列的最长单调递增子序列。
Input
第一行：n，代表要输入的数列的个数
第二行：n个数，数字之间用空格格开
Output
最长单调递增子序列的长度
Sample Input
5
1 3 5 2 9
Sample Output
4
*/

# include <iostream>
using namespace std;
int main()
{
    int n; cin>>n;
    int nums[n];
    for (int i=0; i<n; i++)
        cin>>nums[i];
    int c[n];  // 记录序列从第一个到第n个的包含自身的最长子序列
    c[0] = 1;
    int max_x = -1;  // 记录最长子序列的长度
    for (int i=1; i<n; i++)
    {
        int temp_max = 1;
        for (int j=0; j<i; j++)
        {
            if (nums[j]<=nums[i])
            {
                temp_max = max(temp_max, c[j]+1);
            }
        }
        c[i] = temp_max;
        max_x = max(max_x, temp_max);
    }
    cout<<max_x;
}
