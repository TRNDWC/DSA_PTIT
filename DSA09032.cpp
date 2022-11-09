#include <bits/stdc++.h>
using namespace std;

int t, n, m, ans;
vector<int> a[100001];
bool f[100001];

void dfs(int u)
{
    int d = 1;
    f[u] = 1;
    queue<int> q;
    q.push(u);
    while (q.size())
    {
        int x = q.front();
        q.pop();
        //cout << x << " " << d << endl;
        for (int i = 0; i < a[x].size(); i++)
            if (f[a[x][i]] == 0)
            {
                f[a[x][i]] = 1;
                d++;
                q.push(a[x][i]);
            }
    }
    ans = max(ans, d);
    return;
}

int main()
{
    cin >> t;
    while (t--)
    {
        for (int i = 1; i <= 100000; i++)
            a[i].clear();
        memset(f, 0, sizeof(f));
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
                //cout << i << "\\\\\\\\\\\\\\\\\\\\\\\\\n";
                dfs(i);
            }
        cout << ans << endl;
    }
}