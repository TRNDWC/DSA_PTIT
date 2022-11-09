#include <bits/stdc++.h>
using namespace std;

int t;
string s;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> s;
        int nho = 1;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (nho == 0)
                break;
            if (s[i] == '1')
            {
                s[i]='0';
                nho=0;
            }
            else 
            {
                s[i]='1';
                nho=1;
            }
        }
        cout<<s<<endl;
    }
}