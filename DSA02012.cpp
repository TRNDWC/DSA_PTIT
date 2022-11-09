#include <bits/stdc++.h>
using namespace std;

int n,m,t,a[1001][1001],d;

void dichuyen(int x, int y)
{
    if (x > n || y > m)
        return;
    if (x == n && y == m)
    {
        d++;
        return;
    }
    dichuyen(x + 1, y);
    dichuyen(x, y + 1);
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        d = 0;
        dichuyen(1, 1);
        cout<<d<<endl;
    }
}