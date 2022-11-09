#include <bits/stdc++.h>
using namespace std;

struct kdl
{
    int z, x, y;
    int len = 0;
};

int t, k, m, n;
bool f[51][51][51];
char a[51][51][51];

int tim(kdl s, kdl e)
{
    queue<kdl> q;
    q.push(s);
    while (q.size())
    {
        int i, j, h, l;
        i = q.front().x;
        j = q.front().y;
        h = q.front().z;
        l = q.front().len;
        q.pop();
        if (i < 1 || j < 1 || h < 1 || i > n || j > m || h > k)
            continue;
        if (f[h][i][j] == 1 || a[h][i][j] == '#')
            continue;
        f[h][i][j] = 1;
        // cout<<h<<" "<<i<<" "<<j<<endl;
        if (i == e.x && j == e.y && h == e.z)
        {
            return l;
        }
        q.push({h - 1, i, j, l + 1});
        q.push({h, i + 1, j, l + 1});
        q.push({h, i - 1, j, l + 1});
        q.push({h, i, j + 1, l + 1});
        q.push({h, i, j - 1, l + 1});
        q.push({h + 1, i, j, l + 1});
    }
    return -1;
}

int main()
{
    cin >> t;
    while (t--)
    {
        memset(f, 0, sizeof(f));
        cin >> k >> n >> m;
        kdl s, e;
        for (int h = 1; h <= k; h++)
        {
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                {
                    cin >> a[h][i][j];
                    if (a[h][i][j] == 'S')
                        s = {h, i, j, 0};
                    if (a[h][i][j] == 'E')
                        e = {h, i, j, 0};
                }
        }
        cout << tim(s, e) << endl;
    }
}
