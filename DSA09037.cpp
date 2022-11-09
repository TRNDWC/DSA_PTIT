#include <bits/stdc++.h>
using namespace std;

int k, n, m, a[101], r[1001];
vector<int> c[1001];
bool f[1001];

void dfs(int u)
{
    f[u] = 1;
    r[u]++;
    for (int i = 0; i < c[u].size(); i++)
        if (f[c[u][i]] == 0)
            dfs(c[u][i]);
}

int main()
{
    cin >> k >> n >> m;
    for (int i = 1; i <= k; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        c[u].push_back(v);
    }
    memset(r, 0, sizeof(r));
    for (int i = 1; i <= k; i++)
    {
        memset(f, 0, sizeof(f));
        dfs(a[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (r[i] == k)
            ans++;
    cout << ans << endl;
}