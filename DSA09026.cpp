#include <bits/stdc++.h>
using namespace std;

int t, v, e, st, en;
vector<int> a[1001];
bool f[1001], kt;

void bfs(int u, int v)
{
    queue<pair<int, string>> q;
    q.push({u, to_string(u) + " "});
    while (q.size())
    {
        int x = q.front().first;
        string d = q.front().second;
        q.pop();
        if (f[x] == 1)
            continue;
        f[x] = 1;
        //cout << x << " " << d << endl;
        if (x == v)
        {
            cout << d << endl;
            kt = true;
            return;
        }
        for (int i = 0; i < a[x].size(); i++)
            q.push({a[x][i], d + to_string(a[x][i]) + " "});
    }
    return;
}

int main()
{
    cin >> t;
    while (t--)
    {
        for (int i = 1; i <= 1000; i++)
            a[i].clear();
        cin >> v >> e >> st >> en;
        for (int i = 1; i <= e; i++)
        {
            int x, y;
            cin >> x >> y;
            a[x].push_back(y);
        }
        memset(f, 0, sizeof(f));
        kt = false;
        bfs(st, en);
        if (kt == false)
            cout << -1 << endl;
    }
}