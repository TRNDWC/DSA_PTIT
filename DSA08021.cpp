#include <bits/stdc++.h>
using namespace std;

struct toado
{
    int x, y, dodai = 0;
};

int t, m, n, a[5001][5001], ans;
bool f[5001][5001];

int main()
{
    cin >> t;
    while (t--)
    {
        memset(f, 0, sizeof(f));
        cin >> m >> n;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        queue<toado> q;
        q.push({1, 1, 0});
        f[1][1] = 1;
        ans = 1000000001;
        bool kt = false;
        while (q.size())
        {
            toado vt = q.front();
            int i = vt.x, j = vt.y;
            f[i][j] = 1;
            q.pop();
            if (i < 0 || j < 0 || i > m || j > n)
                continue;
            if (i == m && j == n)
            {
                kt = true;
                ans = min(ans, vt.dodai);
            }
            if (j + a[i][j] <= n && f[i][j + a[i][j]] == 0)
                q.push({i, a[i][j] + j, vt.dodai + 1});
            if (i + a[i][j] <= m && f[i + a[i][j]][j] == 0)
                q.push({i + a[i][j], j, vt.dodai + 1});
        }
        if (kt == true)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
}