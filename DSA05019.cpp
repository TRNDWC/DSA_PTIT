#include <bits/stdc++.h>
using namespace std;

int t, n, m, a[501][501], f[501][501], ans;

int main()
{
    cin >> t;
    while (t--)
    {
        memset(f, 0, sizeof(f));
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];

        // f[i][j] a tong cac so tu o 11 den o ij

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                f[i][j] = f[i - 1][j] + f[i][j - 1] + a[i][j] - f[i - 1][j - 1];

        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= m; j++)
        //         cout << f[i][j] << " ";
        //     cout << endl;
        // }
        ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                for (int c = min(i, j); c >= 1; c--)
                {
                    int x, y;
                    x = i - c + 1;
                    y = j - c + 1;
                    int gt = f[i][j] - f[i][y - 1] - f[x - 1][j] + f[x - 1][y - 1];
                    if (gt == c * c)
                    {
                        ans = max(ans, c);
                        break;
                    }
                }
            }
        cout << ans << endl;
    }
}