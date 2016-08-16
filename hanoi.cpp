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
		hanoi(a, c, b, n-1);
		cout << a << '>' << c << endl;
		hanoi(b, a, c, n-1);
	}
} 
int main()
{
	hanoi('a', 'b', 'c', 10);
}
