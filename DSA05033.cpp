#include <bits/stdc++.h>
using namespace std;

int t, f[50][50];
string s;

int main()
{
    cin >> t;
    while (t--)
    {
        memset(f, 0, sizeof(f));
        cin >> s;
        s = ' ' + s;
        for (int len = 1; len < s.size(); len++)
            for (int i = 1; i <= s.size() - len; i++)
            {
                int j = i + len - 1;
                if (s[i] == s[j])
                    f[i][j] = f[i + 1][j - 1];
                else
                    f[i][j] = min(f[i + 1][j], f[i][j - 1]) + 1;
            }
        cout << f[1][s.size() - 1] << endl;
    }
}