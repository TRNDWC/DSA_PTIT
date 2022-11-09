#include <bits/stdc++.h>
using namespace std;

int t, n, m, ans, stplt;
vector<int> a[1001];
bool f[1001];

void dfs(int u)
{
    if (f[u] == 1)
        return;
    f[u] = 1;
    for (int i = 0; i < a[u].size(); i++)
        dfs(a[u][i]);
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
            a[v].push_back(u);
        }
        stplt = 0;
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; i++)
            if (f[i] == 0)
            {
                stplt++;
                dfs(i);
            }
        for (int i = 1; i <= n; i++)
        {
            memset(f, 0, sizeof(f));
            f[i] = 1;
            int d = 0;
            for (int j = 1; j <= n; j++)
                if (f[j] == 0)
                {
                    d++;
                    dfs(j);
                }
            if (d != stplt)
                cout << i << " ";
        }
        for (int i = 1; i <= n; i++)
            a[i].clear();
        cout << endl;
    }
}