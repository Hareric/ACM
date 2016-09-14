/*
Description
假设要在足够多的会场里安排一批活动，并希望使用尽可能少的会场。设计一个有效的贪心算法进行安排。 （这个问题实际上是著名的图着色问题。若将每一个活动作为图的一个顶点，不相容活动间用边相连。使相邻顶点着有不同颜色的最小着色数，相应于要找的最小会场数。） 对于给定的k个待安排的活动，计算使用最少会场的时间表。
Input
第一行有1 个正整数k，表示有 k个待安排的活动。接下来的k行中，每行有 2个正整数，分别表示 k个待安排的活动开始时间和结束时间。时间以0点开始的分钟计。
Output
输出最少会场数
Sample Input
5 
1 23 
12 28 
25 35 
27 80 
36 50 
Sample Output
3
*/

# include<iostream>
# include<vector>
# include<algorithm>
# include<stdio.h>
using namespace std;
int main()
{
        int n; scanf("%d", &n);
        pair<int, int> *pair_array = new pair<int, int>[n];
        for (int i=0; i<n; i++)
        {
                int start_time, end_time; 
                scanf("%d%d", &start_time, &end_time);
                pair_array[i] = make_pair(end_time, start_time);
        }
        sort(pair_array, pair_array+n);  // 按照活动的结束时间 从小到大排序
        vector<int> v_end;  // 每个会场活动的结束时间
        vector<int>::iterator it_best;  // 记录可安排的会场中的最优会场(结束时间与活动开始时间最相近的)
        bool has_space = false;  // 是否有空闲会场
        vector<int>::iterator it;
        for (int i=0; i<n; i++)
        {
                for (it=v_end.begin(); it != v_end.end(); it++)
                {
                        if (*it <= pair_array[i].second)
                        {
                                if (!has_space)  
                                        it_best = it;
                                else if (*it > *it_best)
                                        it_best = it;
                                has_space = true;
                        }
                }
                if (has_space)
                        *it_best = pair_array[i].first;
                else
                        v_end.push_back(pair_array[i].first);  // 没有找到空闲会场 新建一个会场 并记录活动的结束时间
                has_space = false;
        }
        cout<<v_end.size()<<endl;
}
