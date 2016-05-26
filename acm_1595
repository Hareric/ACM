/*
Description
使用分治法求s=1+2+...n，要求算法时间复杂度为O(logn)。
说明：实际上在O(1)时间内就可计算出s的值。但该题用于考察使用分治法来解决问题。
Input
正整数n的值
Output
s的值
Sample Input
100
Sample Output
5050
*/

#include <iostream>
using namespace std;
int sum_m(int);
int main()
{
        int a;
        cin>>a;
        int s = sum_m(a);
        cout<<s;
} 
int sum_m(int right)
{
        if(right == 1 )
        {
                return 1;
        }
        if(right > 1)
        {
                if( (right/2*2) == right )
                        return (right/2) * (right/2) + 2 * sum_m(right/2);
                else
                        return (right/2) * (right/2) + 2 * sum_m(right/2) + right;
        } 
}
