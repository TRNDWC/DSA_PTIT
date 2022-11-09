#include <bits/stdc++.h>
using namespace std;

long long t, n, m, s, lt, d;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> s >> m;
        if ((s - s / 7) * n < m * s)
        {
            cout << -1 << endl;
            continue;
        }
        for (int i = 1; i <= s - s / 7; i++)
            if (s * m <= i * n)
            {
                cout << i << endl;
                break;
            }
    }
}