#include <bits/stdc++.h>
using namespace std;

int t, n, f[1001], g[1001], ans, a[1001];

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        for (int i = 1; i <= n; i++)
            for (int j = i - 1; j >= 0; j--)
                if (a[j] < a[i])
                    f[i] = max(f[i], f[j] + a[i]);
        for (int i = n; i >= 1; i--)
            for (int j = i + 1; j <= n + 1; j++)
                if (a[j] < a[i])
                    g[i] = max(g[i], g[j] + a[i]);
        ans = 0;
        for (int i = 1; i <= n; i++)
            ans = max(ans, f[i] + g[i] - a[i]);
        cout << ans << endl;
    }
}