/*
程序存储问题
Time Limit: 1000MS	Memory Limit: 32768K

Description
设有n 个程序{1,2,…, n }要存放在长度为L的磁带上。程序i存放在磁带上的长度是 li，1≤i≤n。 程序存储问题要求确定这n 个程序在磁带上的一个存储方案， 使得能够在磁带上存储尽可能多的程序。 对于给定的n个程序存放在磁带上的长度，计算磁带上最多可以存储的程序数。	

Input
第一行是2 个正整数，分别表示文件个数n和磁带的长度L。接下来的1行中，有n个正整数，表示程序存放在磁带上的长度。

Output
输出最多可以存储的程序数

Sample Input
6   50 
2 3 13 8 80 20 

Sample Output
5
*/

# include <iostream>
# include <algorithm>
using namespace std;

int main()
{
	int n, length;
	cin >> n >> length;
	int li[n];
	for (int i=0; i<n; i++)
		cin >> li[i];
	sort (li, li+n);
	int num=0;
	int last = length;
	for (int i=0; i<n; i++)
	{
		if (last >= li[i])
		{
			num++;
			last -= li[i];
		}
	}
	cout << num <<endl;
	return 0;
}
