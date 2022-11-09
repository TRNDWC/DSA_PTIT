#include <bits/stdc++.h>
using namespace std;

int t, n, m;
vector<pair<int, int>> a[1001];
long long f[1001][1001];

int main()
{
    for (int i = 1; i <= 1000; i++)
        for (int j = 1; j <= 1000; j++)
            f[i][j] = INT_MAX;

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a[x].push_back({y, z});
        a[y].push_back({x, z});
    }
    for (int i = 1; i <= n; i++)
    {
        f[i][i] = 0;
        for (auto j : a[i])
        {
            f[i][j.first] = j.second;
        }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (f[i][j] > f[i][k] + f[k][j])
                    f[i][j] = f[i][k] + f[k][j];
    cin >> t;
    while (t--)
    {
        int s, e;
        cin >> s >> e;
        cout << f[s][e] << endl;
    }
}