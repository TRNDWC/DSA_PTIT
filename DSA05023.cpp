#include <bits/stdc++.h>
using namespace std;

int t;
long long f[50],ans;
string s;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> s;
        ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j <= i; j++)
            {
                string x = s.substr(j, i - j + 1);
                stringstream ss;
                long long so;
                ss << x;
                ss >> so;
                ans += so;
                ss.clear();
            }
        }
        cout << ans << endl;
    }
}