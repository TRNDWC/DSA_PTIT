#include <bits/stdc++.h>
using namespace std;

char a[101][101];
bool f[101][101];
int t, n;

struct kdl
{
    int x, y;
    int len = 0;
};

int xuli(kdl s, kdl e)
{
    queue<kdl> q;
    q.push(s);
    while (q.size())
    {
        int i = q.front().x;
        int j = q.front().y;
        int dd = q.front().len;
        q.pop();
        if (f[i][j] == 1 || a[i][j] == 'X')
            continue;
        f[i][j] = 1;
        if (i == e.x && j == e.y)
            return dd;
        for (int k = i - 1; k >= 0; k--)
            if (f[k][j] == 0 && a[k][j] != 'X')
            {
                q.push({k, j, dd + 1});
            }
            else
                break;
        for (int k = i + 1; k < n; k++)
            if (f[k][j] == 0 && a[k][j] != 'X')
            {
                q.push({k, j, dd + 1});
            }
            else
                break;
        for (int k = j - 1; k >= 0; k--)
            if (f[i][k] == 0 && a[i][k] != 'X')
            {
                q.push({i, k, dd + 1});
            }
            else
                break;
        for (int k = j + 1; k < n; k++)
            if (f[i][k] == 0 && a[i][k] != 'X')
            {
                q.push({i, k, dd + 1});
            }
            else
                break;
    }
    return -1;
}

int main()
{
    cin >> t;
    while (t--)
    {
        memset(f, 0, sizeof(f));
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        kdl st, en;
        cin >> st.x >> st.y >> en.x >> en.y;
        cout << xuli(st, en) << endl;
    }
}