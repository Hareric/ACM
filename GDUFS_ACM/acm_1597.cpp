/*
Description
 有n件物品，每件物品皆可分隔，已知背包容量c及每件物品的价值v和重量w，求可装进背包的最大价值。
 
Input
输入有n+1行：
第一行是n值和c值，表示物品数量和背包容量；
接下来的n行是每件物品的价值和重量。

Output
输出最大价值

Sample Input
3 50
100 20
60 10
120 30

Sample Output
240
*/
# include<iostream>
# include<algorithm>
using namespace std;
struct thing{
        double value;
        double weight;
        double v_w;  // 性价比 
        
};
bool cmp (thing a, thing b)
{
        return a.v_w > b.v_w;
}
int main()
{
        int n, bagWeight;  // n件物品 背包能装的重量为weight 
        cin>>n>>bagWeight;
        thing *thingArr = new thing[n+1];
        for (int i=1; i<=n; i++)
        {
                cin>>thingArr[i].value>>thingArr[i].weight;
                thingArr[i].v_w = thingArr[i].value / thingArr[i].weight;
        }
        sort(thingArr+1, thingArr+1+n, cmp);
        int maxValue = 0; // 背包最大价值
        for (int i=1; i<=n; i++)
        {
                if (bagWeight <= 0)
                        break;
                else if (thingArr[i].weight<=bagWeight)
                {
                        maxValue += thingArr[i].value;
                        bagWeight -= thingArr[i].weight;
                }
                else
                {
                        maxValue += thingArr[i].v_w * bagWeight;
                }
        }
        cout<<maxValue<<endl;
}
