#include <bits/stdc++.h>
using namespace std;

int t, n, a[1001];
string so1, so2;

int main()
{
    cin >> t;
    while (t--)
    {
        so1 = "";
        so2 = "";
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++)
        {
            char k = '0' + a[i];
            if (i % 2 == 0)
                so1 += k;
            else
                so2 += k;
        }
        stringstream ss;
        long long s1, s2;
        ss << so1;
        ss >> s1;
        ss.clear();
        ss << so2;
        ss >> s2;
        cout << 1ll + s1 + s2 - 1 << endl;
    }
}