/*
子集和问题
Description
设集合S={x1,x2,…,xn}是一个正整数集合，c是一个正整数，子集和问题判定是否存在S的一个子集S1，使S1中的元素之和为c。试设计一个解子集和问题的回溯法。
Input
输入数据第1行有2个正整数n和c，n表示S的大小，c是子集和的目标值。接下来的1行中，有n个正整数，表示集合S中的元素。
是子集和的目标值。接下来的1 行中，有n个正整数，表示集合S中的元素。
Output
将子集和问题的解输出。当问题无解时，输出“No Solution!”。
Sample Input
5 10
2 2 6 5 4
Sample Output
2 2 6
*/


#include <stdio.h>
#include <iostream>
#include <algorithm>
#define MAX 10000
using namespace std;
int S[MAX];  // 记录每个子集
int select_s[MAX];  // 记录选择的子集 1表示选择
int n, c;  // 子集的个数，目标值

bool isNeed(int currentSum, int t)
// 不选第t个子集后，若目前子集和加上后面的子集和小于目标值，则第t个子集为必选子集
{
    for (int i=t+1; i<=n; i++)
    {
        currentSum+=S[i];
    }
    return currentSum<c;
}
void backTrack(int t, bool &hasResult, int &currentSum)
// 计算选择t个子集后的和判断是否达到目标值
{
    if (currentSum==c)  // 找到一种解决方案后，输出答案并停止其他递归
    {
        hasResult=true;
        for (int i=1; i<=n; i++)
        {
            if (select_s[i]==1)
                cout<<S[i]<<" ";
        }
        return;
    }
    if (hasResult||t>n)
    {
        return;
    }
    if (currentSum+S[t]<=c)  // 右子树---若目前值已大于目标值则剪枝
    {
        currentSum += S[t];
        select_s[t]=1;
        backTrack(t+1, hasResult, currentSum);
        select_s[t] = 0;
        currentSum -= S[t];
    }
    if (!isNeed(currentSum, t))  // 左子树---目前子集和加上后面的子集和小于目标值则剪枝
    {
        backTrack(t+1, hasResult, currentSum);
    }
    
}
int main()
{
    cin>>n>>c;
    for (int i=1; i<=n; i++)
    {
        cin>>S[i];
    }
    bool hasResult = false;
    int currentSum = 0;
    backTrack(1, hasResult, currentSum);
    if (!hasResult)
    {
        cout<<"No Solution!"<<endl;
    }
    return 0;
}
