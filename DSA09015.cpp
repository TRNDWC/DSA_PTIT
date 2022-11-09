#include <bits/stdc++.h>
using namespace std;

int t, n, m;
vector<int> a[1001];
bool f[1001];

bool bfs(int u)
{
    queue<pair<int, int>> q;
    for (int i = 0; i < a[u].size(); i++)
        q.push({a[u][i], u});
    while (q.size())
    {
        int x = q.front().first;
        int cha = q.front().second;
        q.pop();
        f[x] = 1;
        for (int i = 0; i < a[x].size(); i++)
            if (f[a[x][i]] == 0)
                q.push({a[x][i], x});
            else if (x == u)
                return true;
    }
    return false;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            a[i].clear();

        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
        }

        bool kt = false;
        for (int i = 1; i <= n; i++)
        {
            memset(f, 0, sizeof(f));
            if (bfs(i) == true)
            {
                kt = true;
                break;
            }
        }

        if (kt == true)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}