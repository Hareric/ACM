#include <iostream>
using namespace std;

string s;
int book[1000];
int l;
void backTrack(int I)
{
    if (I==l)
    {
        cout << "{ ";
        for (int i=0; i<l; i++)
        {
            if (book[i] == 1)
                cout << s[i] << " ";
        }
        cout << " }" <<endl;
        return;
    }
    book[I] = 0;
    backTrack(I+1);
    book[I] = 1;
    backTrack(I+1);
    
}
int main()
{
    cin >> s;
    l = s.length();
    backTrack(0);
}
