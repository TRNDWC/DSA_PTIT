#include <bits/stdc++.h>
using namespace std;

int n, m, t;
int max_n, max_m;
bool check[2000][2000];
char nt[2000][2000];

struct fen
{
    int x1, y1, x2, y2;
} a[10000];

struct cow
{
    int x, y;
} b[10000];

void build()
{
    memset(check, 0, sizeof(check));
    set<int> s;
    map<int, int> X;
    for (int i = 1; i <= n; i++)
        s.insert(a[i].x1), s.insert(a[i].x2);
    for (int i = 1; i <= m; i++)
        s.insert(b[i].x);
    int gt = 2;
    for (auto i : s)
        X[i] = gt, gt += 2;
    max_n = gt + 10;

    for (int i = 1; i <= n; i++)
        a[i].x1 = X[a[i].x1], a[i].x2 = X[a[i].x2];
    for (int i = 1; i <= m; i++)
        b[i].x = X[b[i].x];

    s.clear();
    X.clear();

    for (int i = 1; i <= n; i++)
        s.insert(a[i].y1), s.insert(a[i].y2);
    for (int i = 1; i <= m; i++)
        s.insert(b[i].y);
    gt = 2;
    for (auto i : s)
        X[i] = gt, gt += 2;
    max_m = gt + 10;

    for (int i = 1; i <= n; i++)
        a[i].y1 = X[a[i].y1], a[i].y2 = X[a[i].y2];
    for (int i = 1; i <= m; i++)
        b[i].y = X[b[i].y];
}

void DFS(cow u)
{
    if (u.x < 0 || u.y < 0 || u.x > max_n || u.y > max_m)
        return;
    if (nt[u.x][u.y] == 'X')
        return;
    if (check[u.x][u.y] == 1)
        return;
    check[u.x][u.y] = 1;
    int xx = u.x;
    int yy = u.y;
    DFS({xx - 1, yy});
    DFS({xx + 1, yy});
    DFS({xx, yy + 1});
    DFS({xx, yy - 1});
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
            if (a[i].x1 > a[i].x2)
                swap(a[i].x1, a[i].x2);
            if (a[i].y1 > a[i].y2)
                swap(a[i].y1, a[i].y2);
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> b[i].x >> b[i].y;
        }
        build();
        for (int i = 0; i <= max_n; i++)
            for (int j = 0; j <= max_m; j++)
                nt[i][j] = '.';
        for (int i = 1; i <= n; i++)
        {
            for (int j = a[i].x1; j <= a[i].x2; j++)
                for (int k = a[i].y1; k <= a[i].y2; k++)
                    nt[j][k] = 'X';
        }
        for (int i = 1; i <= m; i++)
        {
            nt[b[i].x][b[i].y] = 'B';
        }

        int res = 0;
        int tmp = 0;

        for (int i = 1; i <= m; i++)
        {
            if (check[b[i].x][b[i].y] == 1)
                continue;
            DFS(b[i]);
            int count = 0;
            for (int j = 1; j <= m; j++)
                if (check[b[j].x][b[j].y])
                    count++;
            res = max(res, count - tmp);
            tmp = count;
        }
        cout<<res<<endl;
    }
}