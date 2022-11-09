#include <bits/stdc++.h>
using namespace std;

int t, n, m, u;
vector<int> a[1001];
vector<pair<int, int>> ans;
bool f[1001], ok;

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    f[u] = 1;
    while (q.size())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < a[x].size(); i++)
            if (f[a[x][i]] == 0)
            {
                ans.push_back({x, a[x][i]});
                q.push(a[x][i]);
                f[a[x][i]] = 1;
            }
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
        bfs(u);
        if (ans.size() == n - 1)
        {
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i].first << " " << ans[i].second << endl;
        }
        else
            cout << -1 << endl;
    }
}