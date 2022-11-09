#include <bits/stdc++.h>
using namespace std;

int t, n;
bool a[20][20], kt;
vector<string> ans;

void sinh(string duong, int x, int y)
{
    if (x == 1 && y == 1 && a[x][y] == 0)
        return;
    if (x > n || y > n)
        return;
    if (x == n && y == n)
    {
        ans.push_back(duong);
        kt = true;
        return;
    }
    if (a[x + 1][y] == 1)
        sinh(duong + 'D', x + 1, y);
    if (a[x][y + 1] == 1)
        sinh(duong + 'R', x, y + 1);
}

int main()
{
    cin >> t;
    while (t--)
    {
        memset(a, 0, sizeof(a));
        ans.clear();
        kt = false;
        cin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        sinh("", 1, 1);
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
