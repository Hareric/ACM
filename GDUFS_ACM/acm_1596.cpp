/*
线性时间选择
Time Limit: 1000MS	Memory Limit: 65536K
Total Submission(s): 119	Accepted: 47
Description
已知n个数，找出排序后第k小的数。要求平均时间复杂度为O(n)

Input
第一行两个数字n和k，表示找出n个数字中的第k小的数
第二行包含n个数字，以空格分隔
Output
第k小的数的数值
Sample Input
6 2
5 2 1 3 6 4
Sample Output
2

解题思路
    使用快排的思想进行选择
*/

# include <iostream>
# include <vector>
using namespace std;
int select_kth_num (vector<int> , long);
int main()
{
    int n; cin>>n;
    vector<int> v(n);
    for (int i=0; i<n; i++)
        cin>>v[i];
    long k; cin>>k;
    cout << select_kth_num(v, k);
    
}

int select_kth_num (vector<int> v, long k)
// 寻找数组v第k大的数
{
    if (v.size() == 1)
        return v[0];
    int r = rand() % v.size();
    
    vector<int> v_left,v_right;
    for (int i=0; i<v.size(); i++)
    {
//        cout << v[i] << " ";
        if (v[i] <= v[r])
            v_left.push_back(v[i]);
        else
            v_right.push_back(v[i]);
    }
//    cout <<"    "<< r << " "<< k <<'\n';
    if (v_left.size() > k)
        return select_kth_num(v_left, k);
    else if (v_left.size() == k)
        return v[r];
    else
        return select_kth_num(v_right, k-v_left.size());
}
