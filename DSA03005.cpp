#include <bits/stdc++.h>
using namespace std;

long long t, n, k, a[1001], f[1001];

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        f[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            f[i] = 0;
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++)
        {
            f[i] = f[i - 1] + a[i];
        }
        cout << max(abs(f[n] - f[k] - f[k]), abs(f[n] - f[n - k] - f[n - k])) << endl;
    }
}