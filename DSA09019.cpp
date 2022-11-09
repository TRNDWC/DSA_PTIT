#include <bits/stdc++.h>
using namespace std;

int t, n, m;
vector<int> a[1001];
bool f[1001], ok;

void dfs(int x, int u, int trc)
{
    if (ok == 1)
        return;
    f[u] = 1;
    for (int i = 0; i < a[u].size(); i++)
        if (a[u][i] != trc)
            if (f[a[u][i]] == 0)
                dfs(x, a[u][i], u);
            else if (x == a[u][i])
            {
                ok = 1;
                return;
            }
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;

        //
        for (int i = 1; i <= n; i++)
            a[i].clear();
        memset(f, 0, sizeof(f));
        //

        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }

        for (int i=1;i<=n;i++) 
            sort(a[i].begin(),a[i].end());

        //
        ok = 0;
        for (int i = 1; i <= n; i++)
        {
            if (ok == 1)
                break;
            memset(f, 0, sizeof(f));
            f[i] = 1;
            dfs(i, i, 0);
        }
        //

        if (ok == 0)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}