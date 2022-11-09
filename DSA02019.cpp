#include <bits/stdc++.h>
using namespace std;

int n, m, t, ans;
bool f[101][101], tr[101][101];

void di(int point, int len)
{
    ans = max(ans, len);
    for (int i = 0; i < n; i++)
        if (f[point][i] == 1 && tr[point][i] == 0)
        {
            tr[point][i] = 1;
            tr[i][point] = 1;
            di(i, len + 1);
            tr[point][i] = 0;
            tr[i][point] = 0;
        }
}
int main()
{
    cin >> t;
    while (t--)
    {
        memset(f, 0, sizeof(f));
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            f[u][v] = 1;
            f[v][u] = 1;
        }
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            memset(tr, 0, sizeof(tr));
            di(i, 0);
        }
        cout << ans << endl;
    }
}