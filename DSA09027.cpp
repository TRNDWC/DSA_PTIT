#include <bits/stdc++.h>
using namespace std;

int t, n, m, q;
vector<int> a[1001];
bool f[1001];

void dfs(int u)
{
    if (f[u] == 1)
        return;
    f[u] = 1;
    for (int i = 0; i < a[u].size(); i++)
        dfs(a[u][i]);
}

int main()
{
    cin >> t;
    while (t--)
    {
        for (int i = 1; i <= 1000; i++)
            a[i].clear();
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        cin >> q;
        while (q--)
        {
            int u, v;
            cin >> u >> v;
            memset(f, 0, sizeof(f));
            dfs(u);
            if (f[v] == 0)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
    }
}