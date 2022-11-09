#include <bits/stdc++.h>
using namespace std;

int t, n, m, parent[1001];
vector<pair<int, int>> a;

int find(int v)
{
    if (v == parent[v])
        return v;
    return find(parent[v]);
}

void uni(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u != v)
    {
        parent[u] = v;
    }
}

string xuli(int m)
{
    for (int i = 0; i < a.size(); i++)
    {
        int u, v;
        u = find(a[i].first);
        v = find(a[i].second);
        if (u != v)
        {
            uni(a[i].first, a[i].second);
        }
        else
            return "YES\n";
    }
    return "NO\n";
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main()
{
    cin >> t;
    while (t--)
    {
        memset(parent, 0, sizeof(parent));
        a.clear();
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            parent[i] = i;
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            a.push_back({u, v});
        }
        // sort(a.begin(), a.end(), cmp);
        //  cout << t << endl;
        cout << xuli(m);
        // for (int i = 1; i <= n; i++)
        //     cout << find(i) << " ";
        // cout << endl;
    }
}