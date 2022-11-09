#include <bits/stdc++.h>
using namespace std;

int t, n, m, ans;
bool a[501][501], f[501][501];

void dfs(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
        return;
    if (f[x][y] == 1 || a[x][y] == 0)
        return;
    f[x][y] = 1;
    dfs(x - 1, y - 1);
    dfs(x - 1, y);
    dfs(x - 1, y + 1);
    dfs(x, y - 1);
    dfs(x, y + 1);
    dfs(x + 1, y - 1);
    dfs(x + 1, y);
    dfs(x + 1, y + 1);
    return;
}

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
        ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (a[i][j] == 1 && f[i][j] == 0)
                {
                    ans++;
                    dfs(i, j);
                }
        cout << ans << endl;
    }
}