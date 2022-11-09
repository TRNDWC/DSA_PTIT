#include <bits/stdc++.h>
using namespace std;

int t, n, m, ans;
vector<int> a[1001];
vector<int> d[1001];
bool f[1001];

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    while (q.size())
    {
        int x = q.front();
        q.pop();
        if (f[x] == 1)
            continue;
        f[x] = 1;
        for (int i = 0; i < a[x].size(); i++)
            q.push(a[x][i]);
    }
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
        ans = 0;
        for (int i = 1; i <= n; i++)
            if (f[i] == 0)
            {
                ans++;
                bfs(i);
            }
        cout << ans << endl;
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; i++)
            a[i].clear();
    }
}