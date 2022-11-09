#include <bits/stdc++.h>
using namespace std;

bool a[101][101], kt;
int t, n;
vector<string> ans;

void dichuyen(string map, int x, int y)
{
    if (a[x][y] == 0 && x == 1 && y == 1)
        return;
    if (x < 1 || y < 1 || x > n || y > n)
        return;
    if (x == n && y == n)
    {
        kt = true;
        ans.push_back(map);
        return;
    }
    if (a[x + 1][y] == 1)
    {
        a[x + 1][y] = 0;
        dichuyen(map + 'D', x + 1, y);
        a[x + 1][y] = 1;
    }
    if (a[x][y + 1] == 1)
    {
        a[x][y + 1] = 0;
        dichuyen(map + 'R', x, y + 1);
        a[x][y + 1] = 1;
    }
    if (a[x][y - 1] == 1)
    {
        a[x][y - 1] = 0;
        dichuyen(map + 'L', x, y - 1);
        a[x][y - 1] = 1;
    }
    if (a[x - 1][y] == 1)
    {
        a[x - 1][y] = 0;
        dichuyen(map + 'U', x - 1, y);
        a[x - 1][y] = 1;
    }
}
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        ans.clear();
        kt = false;
        dichuyen("", 1, 1);
        if (kt == false)
            cout << -1;
        else
        {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i] << " ";
        }
        cout << endl;
    }
}