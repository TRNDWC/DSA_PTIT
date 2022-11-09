#include <bits/stdc++.h>
using namespace std;

set<pair<pair<int, int>, pair<int, int>>> S;
bool f[101][101];
vector<pair<int, int>> a;
int d[5] = {0, -1, 1, 0};
int c[5] = {-1, 0, 0, 1};
int n, m, k;

void dfs(pair<int, int> o)
{
    int x = o.first;
    int y = o.second;
    //cout << x << " " << y << endl;
    if (x < 1 || y < 1 || x > n || y > n)
        return;
    f[x][y] = 1;
    for (int i = 0; i <= 3; i++)
    {
        int u, v;
        u = x + d[i];
        v = y + c[i];
        if (f[u][v] == 0 && S.count({o, {u, v}}) == 0)
            dfs({u, v});
    }
}

int main()
{
    S.clear();
    a.clear();
    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        S.insert({{x, y}, {u, v}});
        S.insert({{u, v}, {x, y}});
    }
    for (int i = 1; i <= k; i++)
    {
        int u, v;
        cin >> u >> v;
        a.push_back({u, v});
    }
    int dem = 0;
    for (int i = 0; i < a.size(); i++)
    {
        //cout << "\\\\\\\\\\\\\\\\\\\\\\\\\n";
        memset(f, 0, sizeof(f));
        dfs(a[i]);
        for (int j = 0; j < a.size(); j++)
            if (f[a[j].first][a[j].second] == 0)
                dem++;
        //cout<<dem<<endl;
    }
    cout << dem / 2;
}