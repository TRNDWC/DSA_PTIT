#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a[200001];
long long f[200001], g[200001];

long long dfs(int u)
{
    long long ans = 1;
    for (int i = 0; i < a[u].size(); i++)
    {
        ans += dfs(a[u][i]);
    }
    f[u] = ans;
    return ans;
}

long long dfs2(int u)
{
    long long ans = 1;
    for (int i = 0; i < a[u].size(); i++)
    {
        ans += dfs2(a[u][i]) + f[a[u][i]];
    }
    g[u] = ans;
    return ans;
}

int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int so;
        cin >> so;
        a[so].push_back(i);
    }
    dfs(1);
    dfs2(1);
    for (int i = 1; i <= n; i++)
        cout << f[i] << " ";
}