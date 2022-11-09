#include <bits/stdc++.h>
using namespace std;

int t, n, m, ans;
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
        cin >> n;
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        ans = 0;
        for (int i = 1; i <= n; i++)
            if (f[i] == 0)
            {
                ans++;
                dfs(i);
            }
        if (ans == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; i++)
            a[i].clear();
    }
}