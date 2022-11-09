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
        cout << s[0];
        for (int i = 1; i < s.size(); i++)
            if (s[i - 1] == '0')
                cout << s[i];
            else if (s[i] == '0')
                cout << 1;
            else
                cout << 0;
        cout << endl;
    }
}