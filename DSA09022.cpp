#include <bits/stdc++.h>
using namespace std;

int t, v, e, u;
vector<int> a[1001];
bool f[1001];

void dfs(int u)
{
    if (f[u] == 1)
        return;
    f[u] = 1;
    cout << u << " ";
    for (int i = 0; i < a[u].size(); i++)
        dfs(a[u][i]);
    return;
}

int main()
{
    cin >> t;
    while (t--)
    {
        for (int i = 1; i <= 1000; i++)
            a[i].clear();
        cin >> v >> e >> u;
        for (int i = 1; i <= e; i++)
        {
            int x, y;
            cin >> x >> y;
            a[x].push_back(y);
        }
        memset(f, 0, sizeof(f));
        dfs(u);
        cout<<endl;
    }
}