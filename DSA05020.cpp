#include <bits/stdc++.h>
using namespace std;

int t, n, m, a[1001][1001], f[1001][1001];

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        memset(f, 0, sizeof(f));
        f[1][1] = a[1][1];
        for (int i = 2; i <= n; i++)
            f[i][1] = f[i - 1][1] + a[i][1];
        for (int j = 2; j <= m; j++)
            f[1][j] = f[1][j - 1] + a[1][j];
        for (int i = 2; i <= n; i++)
            for (int j = 2; j <= m; j++)
                f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + a[i][j];
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= m; j++)
        //         cout << f[i][j] << " ";
        //     cout << endl;
        // }
        cout << f[n][m] << endl;
    }
}