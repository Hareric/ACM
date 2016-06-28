/*
活动安排问题
Time Limit: 1000MS	Memory Limit: 32768K

Description
设有n个活动的集合E={1,2,…,n}，其中每个活动都要求使用同一资源，如演讲会场等，而在同一时间内只有一个活动能使用这一资源。每个活动i都有一个要求使用该资源的起始时间si和一个结束时间fi,且si	

Input
第一行是正整数n，表示活动数（每个活动的编号为1~n）；
接下来的n行是按照活动时间的非减序输入各活动的起始时间和结束时间，每行两个正整数，分别表示起始时间和结束时间。

Output
输出最大的相容活动子集合中的每个活动编号

Sample Input
11
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14

Sample Output
1 4 8 11
*/
#include <iostream>
#include <algorithm>
using namespace std;

struct meeting
{
    int start;  // 会议开始时间
    int end;  // 会议结束时间
    int id;  // 会议编号
};

bool cmp(meeting a, meeting b)
{
    return a.end < b.end;
}
int main()
{
    int n; cin>>n; // 会议数
    meeting *timeTable = new meeting[n];
    for (int i=0; i<n; i++)
    {
        cin>>timeTable[i].start>>timeTable[i].end;
        timeTable[i].id = i+1;
    }
    sort(timeTable, timeTable+n, cmp);
    int num = 1;  // 可完整举行的会议数
    int currentTime = timeTable[0].end; cout << timeTable[0].id << ' ';
    for (int i=1; i<n; i++)
    {
        if (timeTable[i].start>currentTime)
        {
            num++;
            currentTime = timeTable[i].end;
            cout << timeTable[i].id << ' ';
        }
    }
    //cout << '\n' << num << endl;
    return 0;
}
