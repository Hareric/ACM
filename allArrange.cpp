# include <iostream>
# include <stdio.h>
using namespace std;

void swap (int* a, int* b)
// 对数字a和b进行交换
{
    int* c;
    c = a;
    a = b;
    b = c;
}

void allArrange(int* arr, int i, int &len, int &count)
// 输入一个数组，并对整个数组的第i个元素后进行全排列
{
    
    if (i==len)
    {
        for (int t=0; t<len; t++)
            cout<<arr[t]<<" ";
        cout<<endl;
        count++;
        return;
    }
    for (int t=i; t<len; t++)
    {
        swap(arr[i], arr[t]);
        allArrange(arr, i+1, len, count);
        swap(arr[t], arr[i]);
    }
}

int main()
{
    int num = 3;
    cin>>num; //需要全排列的个数
    int arr[num];
    for (int i=0; i<num; i++)
        arr[i] = i + 1;
    int count = 0;
    allArrange(arr, 0, num, count);
    cout<<count<<endl;
}
