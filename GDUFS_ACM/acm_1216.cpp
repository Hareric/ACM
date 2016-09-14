/*
最优服务次序问题
Time Limit: 1000MS	Memory Limit: 32768K
Description
设有n 个顾客同时等待一项服务。顾客i需要的服务时间为ti，1≤i≤n。应如何安排n 个顾客的服务次序才能使平均等待时间达到最小?平均等待时间是 n 个顾客等待服务时间的 总和除以n。 对于给定的n个顾客需要的服务时间，计算最优服务次序。	
Input
第一行是正整数n，表示有n 个顾客。接下来的 1行中，有n个正整数，表示n个顾客需要的服务时间。 
Output
输出最小平均等待时间
Sample Input
10 
56 12 1 99 1000 234 33 55 99 812
Sample Output
532
*/


#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n;  // 等待人数
    cin>>n;
    int *times = new int[n+1];  // 每个人的服务时间
    for (int i=1; i<=n; i++)
        cin>>times[i];
    sort(times+1, times+1+n);
    float sumTime = 0;  // 所有人等待的总时间
    for (int i=1; i<=n; i++)
        sumTime += times[i] * (n-i+1);
    printf("%.2f\n", sumTime / n);  // 保留2位小数
    return 0;
}
