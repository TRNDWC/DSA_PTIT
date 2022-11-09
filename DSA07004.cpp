#include <bits/stdc++.h>
using namespace std;

int ans, t;
string s;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> s;
        ans = 0;
        while (s.size() != 0)
        {
            int tg = s.find("()");
            if (tg == -1)
            {
                if (s[0] == ')')
                {
                    s[0] = '(';
                    ans++;
                }
                else if (s[s.size() - 1] == '(')
                {
                    s[s.size() - 1] = ')';
                    ans++;
                }
            }
            else
                s.erase(tg, 2);
        }
        cout << ans << endl;
    }
}