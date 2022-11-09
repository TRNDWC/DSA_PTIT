#include <bits/stdc++.h>
using namespace std;

int t, v, e, st, en;
vector<int> a[1001];
bool f[1001],kt;

void dfs(int u, int v, string s)
{
    if (f[u] == 1)
        return;
    f[u] = 1;
    if (u == v)
    {
        kt = true;
        cout << s << v << endl;
        return;
    }
    for (int i = 0; i < a[u].size(); i++)
        dfs(a[u][i], v, s + to_string(u) + " ");
    return;
}

int main()
{
    cin >> t;
    while (t--)
    {
        for (int i = 1; i <= 1000; i++)
            a[i].clear();
        cin >> v >> e >> st >> en;
        for (int i = 1; i <= e; i++)
        {
            int x, y;
            cin >> x >> y;
            a[x].push_back(y);
        }
        memset(f, 0, sizeof(f));
        kt = false;
        dfs(st, en, "");
        if (kt == false)
            cout << -1 << endl;
    }
}