#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<string> a[2001];
vector<int> c[1001];

void dfs(int u, string way)
{
    way += to_string(u) + " ";
    if (c[u].size() == 0)
    {
        a[u].push_back(way);
        return;
    }
    for (int i = 0; i < c[u].size(); i++)
        dfs(c[u][i], way);
    return;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            c[i].clear();
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            c[u].push_back(v);
        }
        dfs(1, "");
        for (int i = 1; i <= n; i++)
        {
            if (a[i].size() != 0)
                for (int j = 0; j < a[i].size(); j++)
                    cout << a[i][j] << endl;
            a[i].clear();
        }
    }
}