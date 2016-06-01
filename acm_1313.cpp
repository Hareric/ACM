/*
Description
设有n件工作分配给n个人。将工作i分配给第j个人所需的费用为cij 。 设计一个算法，对于给定的工作费用，为每一个人都分配1 件不同的工作，并使总费用达到最小。
Input
输入数据的第一行有1 个正整数n (1≤n≤20)。接下来的n行，每行n个数，表示工作费用。
Output
将计算出的最小总费用输出到屏幕。
Sample Input
3
10 2 3
2 3 4
3 4 5
Sample Output
9
*/

# include <iostream>
# define MAX 1000
using namespace std;
int pay[MAX][MAX]; // .[i][j] 第i个工人做第j件工作需要的支出
int len;  // 工人数以及工作数
int selected[MAX];  // .[i] 表示第i个工人选择的工作


void swap(int* a, int* b)
{
    int* c;
    c = a;
    a = b;
    b = c;
}
void backTrack (int i, int &lessSpend, int &currentSpend)
//对第i个工人(包括第i个)后所选的工作进行全排列(待剪枝)
{
    if (i>len)
    {
        if (currentSpend<lessSpend)
        {
            lessSpend = currentSpend;
        }
        return;
    }
    for (int t=i; t<=len; t++)
    {
        swap(selected[i], selected[t]);
        currentSpend += pay[i][selected[i]];
        backTrack(i+1, lessSpend, currentSpend);
        currentSpend -= pay[i][selected[i]];
        swap(selected[i], selected[t]);

    }
}
int main()
{
    int n; cin>>n; // n件工作分配给n个工人
    len = n;
    for (int i=1; i<=n; i++)
    {
        selected[i] = i;
        for (int j=1; j<=n; j++)
        {
            cin>>pay[i][j];
        }
    }
    int lessSpend=1000000, currentSpend=0, i=1;
    backTrack(i, lessSpend, currentSpend);
    cout<<lessSpend<<endl;
    return 0;
}
