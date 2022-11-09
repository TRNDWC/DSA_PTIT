#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int a[501][501], f[501][501];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct toado
{
    int x, y, w;
};

bool operator<(toado A, toado B)
{
    if (A.w == B.w)
    {
        if (A.x == B.x)
            return A.y < B.y;
        else
            return A.x < B.x;
    }
    return A.w < B.w;
}

set<toado> pq;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j], f[i][j] = INT_MAX;
        f[1][1] = a[1][1];
        pq.insert({1, 1, 0});
        while (pq.size())
        {
            toado u = *pq.begin();
            pq.erase(pq.begin());
            int x = u.x;
            int y = u.y;
            int gt = u.w;
            for (int i = 0; i <= 3; i++)
            {
                int x1 = x + dx[i];
                int y1 = y + dy[i];
                if (x1 < 1 || y1 < 1 || x1 > n || y1 > m)
                    continue;
                if (f[x1][y1] > f[x][y] + a[x1][y1])
                {
                    if (f[x1][y1] != INT_MAX)
                        pq.erase(pq.find({x1, y1, f[x1][y1]}));
                    f[x1][y1] = f[x][y] + a[x1][y1];
                    pq.insert({x1, y1, f[x1][y1]});
                }
            }
        }
        cout << f[n][m] << endl;
    }
}