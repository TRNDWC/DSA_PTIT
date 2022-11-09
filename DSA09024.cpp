#include <bits/stdc++.h>
using namespace std;

int t, v, e, u;
vector<int> a[1001];
bool f[1001];

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    while (q.size())
    {
        int x = q.front();
        q.pop();
        if (f[x] == 1)
            continue;
        f[x] = 1;
        cout << x << " ";
        for (int i = 0; i < a[x].size(); i++)
            q.push(a[x][i]);
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
        cin >> v >> e >> u;
        for (int i = 1; i <= e; i++)
        {
            int x, y;
            cin >> x >> y;
            a[x].push_back(y);
        }
        memset(f, 0, sizeof(f));
        bfs(u);
        cout << endl;
    }
}