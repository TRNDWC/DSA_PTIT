#include <bits/stdc++.h>
using namespace std;

int t, n, m, u;
vector<int> a[1001];
vector<pair<int, int>> ans;
bool f[1001], ok;

void dfs(int u)
{
    f[u] = 1;
    for (int i = 0; i < a[u].size(); i++)
        if (f[a[u][i]] == 0)
        {
            ans.push_back({u, a[u][i]});
            dfs(a[u][i]);
        }
}

int main()
{
    cin >> t;
    while (t--)
    {
        memset(f, 0, sizeof(f));
        cin >> n >> m >> u;
        for (int i = 1; i <= 1000; i++)
            a[i].clear();
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        ans.clear();
        dfs(u);
        if (ans.size() == n - 1)
        {
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i].first << " " << ans[i].second << endl;
        }
        else
            cout << -1 << endl;
    }
}