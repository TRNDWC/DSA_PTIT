#include <bits/stdc++.h>
using namespace std;

int t, a, b, ans;
string s;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> s;
        a = 0;
        b = 0;
        ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '[')
                a++;
            else
                b++;
            if (b > a)
            {
                for (int j = i + 1; j < s.size(); j++)
                    if (s[j] == '[')
                    {
                        swap(s[i], s[j]);
                        ans += j - i;
                        a++;
                        b--;
                        break;
                    }
            }
        }
        cout << ans << endl;
    }
}