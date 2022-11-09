#include <bits/stdc++.h>
using namespace std;

int t, n, ans;
vector<int> a[100001];
bool f[100001];

void dfs(int u, int len)
{
    ans = max(ans, len);
    if (f[u] == 1)
        return;
    f[u] = 1;
    for (int i = 0; i < a[u].size(); i++)
        dfs(a[u][i], len + 1);
}

int main()
{
    cin >> t;
    while (t--)
    {
        for (int i = 1; i <= 100000; i++)
            a[i].clear();
        memset(f, 0, sizeof(f));
        cin >> n;
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
        }
        ans = 0;
        dfs(1, 0);
        cout << ans << endl;
    }
}