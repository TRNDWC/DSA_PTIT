#include <bits/stdc++.h>
using namespace std;

int t, n, m, a[501][501], ans;
bool f[501][501];

struct kdl
{
    int x, y;
    int day = 0;
};

int main()
{
    cin >> t;
    while (t--)
    {
        memset(f, 0, sizeof(f));
        queue<kdl> q;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 2)
                    q.push({i, j, 0});
            }
        ans = 0;
        while (q.size() != 0)
        {
            int i = q.front().x;
            int j = q.front().y;
            int d = q.front().day;
            q.pop();
            if (i < 1 || j < 1 || i > n || j > m)
                continue;
            if (f[i][j] == 1)
                continue;
            f[i][j] = 1;
            if (a[i][j] == 1)
                a[i][j] = 2;
            // cout << i << " " << j << endl;
            ans = max(ans, d);
            if (a[i + 1][j] == 1)
                q.push({i + 1, j, d + 1});
            if (a[i][j + 1] == 1)
                q.push({i, j + 1, d + 1});
            if (a[i - 1][j] == 1)
                q.push({i - 1, j, d + 1});
            if (a[i][j - 1] == 1)
                q.push({i, j - 1, d + 1});
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (a[i][j] == 1)
                {
                    ans = -1;
                    break;
                }
        cout << ans << endl;
    }
}