#include <bits/stdc++.h>
using namespace std;

int t, n, m, ans;
vector<int> a[1001];
vector<int> d[1001];
bool f[1001];

void dfs(int v, int u)
{
    if (f[u] == 1)
        return;
    f[u] = 1;
    d[v].push_back(u);
    for (int i = 0; i < a[u].size(); i++)
        dfs(v, a[u][i]);
    return;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
        }
        for (int i = 1; i <= n; i++)
        {
            memset(f, 0, sizeof(f));
            d[i].clear();
            dfs(i, i);
        }
        bool kt = 1;
        for (int i = 1; i <= n; i++)
        {
            if (d[i].size() != n)
            {
                kt = 0;
                break;
            }
            // for (int j = 0; j < d[i].size(); j++)
            //     cout << d[i][j] << " ";
            // cout << endl;
        }
        if (kt == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
        for (int i = 1; i <= n; i++)
            a[i].clear();
    }
}