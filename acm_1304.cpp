/*
 Description
 羽毛球队有男女运动员各n人。给定2个n×n 矩阵P和Q。P[i][j]是男运动员i和女运动员j配对组成混合双打的男运动员竞赛优势；Q[i][j]是女运动员i和男运动员j配合的女运动员竞赛优势。由于技术配合和心理状态等各种因素影响，P[i][j]不一定等于Q[j][i]。男运动员i和女运动员j配对组成混合双打的男女双方竞赛优势为P[i][j]*Q[j][i]。 设计一个算法，对于给定的男女运动员竞赛优势，计算男女运动员最佳配对法，使各组男女双方竞赛优势的总和达到最大。
 Input
 输入数据第一行是1个正整数n (1≤n≤20)。接下来的2n行，每行n个数。前n行是p，后n行是q。
 Output
 将计算出的男女双方竞赛优势的总和的最大值输出到屏幕。
 Sample Input
 3
 10 2 3
 2 3 4
 3 4 5
 2 2 2
 3 5 3
 4 5 1
 Sample Output
 52
 
思路：
 男女并排各站一列，对其中一列进行全排列，得出所有男女组合方案，利用回溯法寻找出最优解
*/
#include <iostream>
#define MAX 21
using namespace std;

int P[MAX][MAX];  // 男运动员i和女运动员j配合的男运动员竞赛优势
int Q[MAX][MAX];  // 女运动员i和男运动员j配合的女运动员竞赛优势
int allRang[MAX];  // 对女运动员进行全排列的列表
int currentPower;  // 目前的优势值
int maxPower;  // 最大的优势值
int n;  // 男女运动员数量

void swap(int *a, int *b)
{
    int *c = a;
    a = b;
    b = c;
}

void backTrack(int t)
{

    if (t>n)
    {
        
        if (currentPower>maxPower)
        {
            maxPower = currentPower;
        }
        return;
    }

    
    for (int i=t; i<=n; i++)
    {
        swap(allRang[i], allRang[t]);
        currentPower += P[t][allRang[t]] * Q[allRang[t]][t];
        backTrack(t+1);
        currentPower -= P[t][allRang[t]] * Q[allRang[t]][t];
        swap(allRang[i], allRang[t]);
    }
}

int main()
{
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        allRang[i] = i;
        for (int j=1; j<=n; j++)
        {
            cin>>P[i][j];
        }
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            cin>>Q[i][j];
        }
    }
    backTrack(1);
    cout<<maxPower<<endl;
    return 0;
}












