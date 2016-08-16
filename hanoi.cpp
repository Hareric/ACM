# include<iostream>
using namespace std;

void hanoi(char a, char b, char c, int n)
// 将汉诺塔上a柱上的n个平板移至c柱子上
{
	if (n == 1)
	{
		cout << a << '>' << c << endl;
	}
	else
	{
		hanoi(a, c, b, n-1);  // 先将a柱上的n-1个板移至b柱上
		cout << a << '>' << c << endl;  // 再将a柱上的最后一个板移动至c柱上
		hanoi(b, a, c, n-1);  // 最后将b柱剩余的n-1个板移动至c柱上
	}
} 
int main()
{
	hanoi('A', 'B', 'C', 10);
}
