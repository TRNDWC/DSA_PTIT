#include <bits/stdc++.h>
using namespace std;

int t, n, m;
vector<int> a[101];
long long f[101][101];

int main()
{
    cin >> t;
    while (t--)
    {
        for (int i = 1; i <= 100; i++)
        {
            for (int j = 1; j <= 100; j++)
                f[i][j] = INT_MAX;
            a[i].clear();
            f[i][i] = 0;
        }
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            a[x].push_back(y);
            f[x][y] = 1;
        }
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    if (f[i][j] > f[i][k] + f[k][j])
                        f[i][j] = f[i][k] + f[k][j];
        long long ans = 0;
        int dem = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                if (f[i][j] != INT_MAX && i != j)
                    ans += f[i][j], dem++;
        }
        double res = (ans * 1.0) / (dem);
        cout << fixed << setprecision(2) << res << endl;
    }
}