/*
Description
设有n(n<=100)个按非减序排列的数，找出该序列中大于m的最小数。若m是最大值，则输出-1 。 要求算法在最坏情况下耗时O(logn)。	

Input
输入有三行：
第一行是n值；
第二行是n个数;
第三行是m值。

Output
输出序列中大于m的最小数。

Sample Input
6
1 2 6 17 18 19
8

Sample Output
17
*/
#include <stdio.h>
#include <iostream>
using namespace std;
int find_min(int *arr, int start, int end, int num)
// 寻找 arr[start]~arr[end] 之中大于num的最小值
{
    if (arr[start]>num)
        return arr[start];
    int mid = (start+end) / 2;
    if (arr[mid]>num)
        return find_min(arr, start, mid, num);
    else if(arr[mid]==num)
        return arr[mid+1];
    else
        return find_min(arr, mid+1, end, num);
    
}
int main()
{
    int n; scanf("%d", &n);
    int *arr = new int[n];
    for (int i=0; i<n; i++)
        cin>>arr[i];
    int num; scanf("%d", &num);
    if (num>=arr[n-1])
    {
        cout<<-1;
        return 0;
    }
    
    cout<<find_min(arr, 0, n-1, num);
    return 0;
}
