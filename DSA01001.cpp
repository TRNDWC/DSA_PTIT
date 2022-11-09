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
        bool k = true;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (k == false)
                break;
            if (s[i] == '1')
                s[i] = '0';
            else
            {
                s[i] = '1';
                k = false;
            }
        }
        cout<<s<<endl;
    }
}