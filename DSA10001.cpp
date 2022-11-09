#include <bits/stdc++.h>
using namespace std;

char a[1001][1001];
int n, m, st_x, st_y, t;
bool ok;
bool f[1001][1001];

void dfs(int x, int y, int sldh, char path)
{
    //cout << x << " " << y << " " << sldh << " " << path << endl;
    if (x < 1 || y < 1 || x > n || y > m)
        return;
    if (sldh > 3 || ok == 1)
        return;
    if (f[x][y] == 1 || a[x][y] == '*')
        return;
    f[x][y] = 1;
    if (a[x][y] == 'T')
    {
        ok = 1;
        return;
    }
    if (path == 'B')
    {
        dfs(x + 1, y, sldh + 1, 'N');
        dfs(x - 1, y, sldh, 'B');
        dfs(x, y + 1, sldh + 1, 'D');
        dfs(x, y - 1, sldh + 1, 'T');
    }
    else if (path == 'N')
    {
        dfs(x + 1, y, sldh, 'N');
        dfs(x - 1, y, sldh + 1, 'B');
        dfs(x, y + 1, sldh + 1, 'D');
        dfs(x, y - 1, sldh + 1, 'T');
    }
    else if (path == 'T')
    {
        dfs(x + 1, y, sldh + 1, 'N');
        dfs(x - 1, y, sldh + 1, 'B');
        dfs(x, y + 1, sldh + 1, 'D');
        dfs(x, y - 1, sldh, 'T');
    }
    else if (path == 'D')
    {
        dfs(x + 1, y, sldh + 1, 'N');
        dfs(x - 1, y, sldh + 1, 'B');
        dfs(x, y + 1, sldh, 'D');
        dfs(x, y - 1, sldh + 1, 'T');
    }
    else
    {
        dfs(x + 1, y, sldh, 'N');
        dfs(x - 1, y, sldh, 'B');
        dfs(x, y + 1, sldh, 'D');
        dfs(x, y - 1, sldh, 'T');
    }
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 'S')
                    st_x = i, st_y = j;
            }
        memset(f, 0, sizeof(f));
        ok = 0;
        dfs(st_x, st_y, 0, 'X');
        if (ok == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
// 2

// 5 5

// ..S..

// ****.

// .....

// .***.

// T....

// 5 5

// S....

// ****.

// .....

// .****

// ..T..