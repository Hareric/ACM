/*
Description
在n×n 格的棋盘上放置彼此不受攻击的n 个皇后。按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。n后问题等价于在n×n格的棋盘上放置n个皇后，任何2个皇后不放在同一行或同一列或同一斜线上。 设计一个解n 后问题的回溯算法，计算在n*n个方格上放置彼此不受攻击的n个皇后的一个放置方案。	
Input
出输入数据的第一行有1 个正整数n。
Output
将计算出的彼此不受攻击的n个皇后的一个放置方案输出到屏幕。输出的第1行是n个皇后的放置方案。
Sample Input
5
Sample Output
1 3 5 2 4
*/

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

bool isInOblique(int* arr, int i, int j)
// 判断arr[i]若为j，是否在前面的点的斜线上
{
    for (int t=1; t<i; t++)
    {
        if (abs(arr[t]-j) == abs(t-i))
        {
//            for (int tt=1; tt<=i; tt++)
//                cout<<arr[tt]<<" ";
//            cout<<endl;
//            cout<<i<<" "<<j<<endl;
            return true;
        }
    }
    return false;
}
void backTrack(int* arr, int i, int &len, bool &hasResult)
// 输入一个数组，并对整个数组的第i个元素后进行全排列
{
//    for (int t=1; t<=len; t++)
//        cout<<arr[t]<<" ";
//    cout<<endl;
    if (hasResult)
        return;
    
    if (i>len)
    {
        for (int t=1; t<=len; t++)
            cout<<arr[t]<<" ";
        cout<<endl;
        hasResult = true;
        return;
    }
    
    for (int t=i; t<=len; t++)
    {
        swap(arr[i], arr[t]);
        if (isInOblique(arr, i, arr[i]))
        {
            swap(arr[t], arr[i]);  // 回溯
            continue;
        }
        backTrack(arr, i+1, len, hasResult);
        swap(arr[t], arr[i]);
    }
}

int main()
{
    int num;
    cin>>num; // 需要全排列的个数
    int arr[num+1];
    for (int i=1; i<=num; i++)
        arr[i] = i;
    bool hasResult = false;
    backTrack(arr, 1, num, hasResult);
}
