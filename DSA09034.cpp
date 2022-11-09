#include <bits/stdc++.h>
using namespace std;

char a[1001][1001];
bool f[1001][1001];
int n, m;

void dfs(int x, int y)
{
    if (x < 1 || y < 1 || x > n || y > m)
        return;
    if (f[x][y] == 1||a[x][y]=='.')
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
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    memset(f, 0, sizeof(f));
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 'W' && f[i][j] == 0)
                dfs(i, j), ans++;
    cout << ans << endl;
}