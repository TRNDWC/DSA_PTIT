#include <bits/stdc++.h>
using namespace std;

long long t, f[50];
string s;

int main()
{
    cin >> t;
    while (t--)
    {
        memset(f, 0, sizeof(f));
        cin >> s;
        if (s[0] == '0')
        {
            cout << 0 << endl;
            continue;
        }
        s = ' ' + s;
        f[0] = 1;
        f[1] = 1;
        for (int i = 2; i < s.size(); i++)
        {
            if (s[i] > '0')
                f[i] = f[i - 1];
            if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6')
                f[i] += f[i - 2];
        }
        cout << f[s.size() - 1] << endl;
    }
}