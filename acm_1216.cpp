#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n;  // 等待人数
    cin>>n;
    int times[n+1];
    for (int i=1; i<=n; i++)
        cin>>times[i];
    sort(times+1, times+1+n);
    float sumTime = 0;  // 所有人等待的总时间
    for (int i=1; i<=n; i++)
    {
        sumTime += times[i] * (n-i+1);
    }
    printf("%.2f\n", sumTime / n);  // 保留2位小数
    return 0;
}
