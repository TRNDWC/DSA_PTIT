#include <bits/stdc++.h>
using namespace std;

long long t, n, h[100001];
vector<int> children[100001];
bool f[100001], kt;
long long up[100001][25], depth[100001];

void dfs(int a)
{
    if (f[a] == 1)
        return;
    f[a] = 1;
    for (int b : children[a])
        if (f[b] == 1)
            continue;
        else
        {
            depth[b] = depth[a] + 1;
            up[b][0] = a;
            for (int j = 1; j <= 21; j++)
            {
                up[b][j] = up[up[b][j - 1]][j - 1];
            }
            dfs(b);
        }
}

long long get_lca(long long a, long long b)
{
    if (depth[a] < depth[b])
        swap(a, b);
    long long k = depth[a] - depth[b];
    for (int j = 21; j >= 0; j--)
        if (k & (1 << j))
            a = up[a][j];
    if (a == b)
        return a;
    for (int j = 21; j >= 0; j--)
    {
        if (up[a][j] != up[b][j])
        {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            children[i].clear();
        memset(f, 0, sizeof(f));
        for (int i = 1; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            children[x].push_back(y);
        }
        depth[0] = -1;
        dfs(1);
        int q;
        cin >> q;
        while (q--)
        {
            int u, v;
            cin >> u >> v;
            long long node = get_lca(u, v);
            long long kc1, kc2, kc3, kc;
            kc1 = depth[u];
            kc2 = depth[v];
            kc3 = depth[node];
            kc = kc2 + kc1 - 2 * kc3;
            cout << kc << endl;
        }
    }
}