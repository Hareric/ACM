/*
Description
请用回溯法解0-1背包问题

Input
第一行是物品数量n和背包总容量C
第二行是n件物品的价值
第三行是n件物品的重量

Output
输出背包的最大价值
*/
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct thing{
    int weight;
    int value;
};

bool is_nessary(thing* things, int i, int num, int bestValue, int leftWeight, int currentValue)
// 用剩余的物品将背包塞满后，判断价值是否能超过目前的最优值
{
    for (i; i<num; i++)
    {
        if (leftWeight>=things[i].weight)
        {
            leftWeight -= things[i].weight;
            currentValue += things[i].value;
        }
        else
        {
            currentValue += things[i].value * 1.0 / things[i].weight * leftWeight;
            break;
        }
    }
    if (currentValue>bestValue)
        return true;
    else
        return false;
    
}

void backTrack(thing* things, int &thingNum, int i, int &bagValue, int &bagWeight, int &bestValue)
{
    // printf("weight:%d\tvalue:%d\tbestValue:%d\n", bagWeight,bagValue, bestValue);
    if (i==thingNum)
    {
        bestValue = bagValue;
        return;
    }
    if (bagWeight>=things[i].weight)  // 若背包可以放下things[i]物品 则访问左子树
    {
        bagValue += things[i].value;
        bagWeight -= things[i].weight;
        backTrack(things, thingNum, i+1, bagValue, bagWeight, bestValue);
        bagValue -= things[i].value;  // 回溯
        bagWeight += things[i].weight;  // 回溯
    }
    if (is_nessary(things, i+1, thingNum, bestValue, bagWeight, bagValue))  // 若不取things[i]物品后，背包价值无法超越现有最优值则无需访问右子树
    {
        backTrack(things, thingNum, i+1, bagValue, bagWeight, bestValue);
    }
}

bool cmp(thing t1, thing t2)  // 按照性价比从高到小排序
{
    return (t1.value * 1.0 / t1.weight) > (t2.value * 1.0 / t2.weight);
}

int main()
{
    int bagValue = 0, bagWeight, thingNum, bestValue=0;
    scanf("%d %d", &thingNum,&bagWeight);
    thing* things = new thing[thingNum];
    for (int i=0; i<thingNum; i++)
        scanf("%d", &things[i].value);
    for (int i=0; i<thingNum; i++)
        scanf("%d", &things[i].weight);
    sort(things, things+thingNum, cmp);
    backTrack(things, thingNum, 0, bagValue, bagWeight, bestValue);
    printf("%d\n", bestValue);
    return 0;
}
