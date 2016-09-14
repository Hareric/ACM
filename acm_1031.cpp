/*
Description
设X[0:n-1]和Y[0:n-1]为两个数组，每个数组中含有n个已排好序的数。试设计一个O（logn）时间算法，找出X和Y的2n个数的中位数
Input
第一行： n，为x和y数组的元素个数
第二行： x数组的n个数，用空格分隔
第三行： y数组的n个数，用空格分隔
Output 
中位数两个，用空格分隔
Sample Input
4
1 2 6 20
2 8 9 10
Sample Output
6 8
*/

# include<iostream>
# include<algorithm>
using namespace std;
void find_mid(int *a, int a_l, int a_r, int *b, int b_l, int b_r)
// 寻找数组a与数组b的2个中位数
{
    if (a_r - a_l == 1)  // 若寻找的数组 只有2个数 直接找出中位数
    {
        int c[4];
        c[0] = a[a_l];c[1]=a[a_r];c[2]=b[b_l];c[3]=b[b_r];
        sort(c, c+4);
        cout<<c[1]<<" "<<c[2];
        return;
    }
    int a_mid = (a_r + a_l + 1) / 2;
    int b_mid = (b_r + b_l) / 2;
    if (a[a_mid]==b[b_mid])
        cout<<a[a_mid]<<" "<<b[b_mid];
    else if (a[a_mid]<b[b_mid])
        find_mid(a, a_mid, a_r, b, b_l, b_mid);
    else
        find_mid(a, a_l, a_mid, b, b_mid, b_r);
}
int main()
{
    int n; cin>>n;
    int *a = new int[n+1];
    int *b = new int[n+1];
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
        cin>>b[i];
    find_mid(a, 1, n, b, 1, n);
    delete a;
    delete b;
    
}
