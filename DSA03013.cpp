#include <bits/stdc++.h>
using namespace std;

int t, f[1001], d;
string s;

int main()
{
    cin >> t;
    while (t--)
    {
        memset(f, 0, sizeof(f));
        cin >> d;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            int vt = s[i] - 'A';
            f[vt]++;
        }
        int lo = 0;
        for (char i = 'A'; i <= 'Z'; i++)
        {
            int gt = i - 'A';
            lo = max(lo, f[gt]);
        }
        // cout<<lo<<endl;
        if (s.size() - lo >= (lo - 1) * (d - 1))
            cout << 1 << endl;
        else
            cout << -1 << endl;
    }
}