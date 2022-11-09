#include <bits/stdc++.h>
using namespace std;

vector<int> a[1001];
int t, d, n, m;
bool f[1001], ok;

void dfs(int u, int sl)
{
    if (sl == n)
    {
        ok = 1;
        return;
    }
    for (int i = 0; i < a[u].size(); i++)
        if (f[a[u][i]] == 0)
        {
            // cout << u << "->" << a[u][i] << endl;
            f[a[u][i]] = 1;
            dfs(a[u][i], sl + 1);
            f[a[u][i]] = 0;
        }
}

void xuli()
{
    cin >> n >> m;
    for (int i = 1; i <= 1001; i++)
        a[i].clear();
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        ok = 0;
        memset(f, 0, sizeof(f));
        f[i] = 1;
        dfs(i, 1);
        if (ok == 1)
        {
            cout << 1 << endl;
            return;
        }
    }

    // memset(f, 0, sizeof(f));
    // int d = 0;
    // f[2] = 1;
    // dfs(2, 0, d);

    cout << 0 << endl;
    return;
}

int main()
{
    cin >> t;
    while (t--)
    {
        xuli();
    }
}