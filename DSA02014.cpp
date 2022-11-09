#include <bits/stdc++.h>
using namespace std;

int t, k, m, n, sz;
unordered_set<string> dicti;
vector<string> ans;
string s;
string a[10][10];
bool f[10][10];

void dq(int x, int y, string s)
{
    if (x > m || y > n || x < 1 || y < 1)
        return;
    if (dicti.find(s) != dicti.end())
        ans.push_back(s);
    for (int h = -1; h <= 1; h++)
        for (int k = -1; k <= 1; k++)
        {
            if (h == 0 && k == 0)
                continue;
            if (f[x + h][y + k] == 0)
            {
                f[x + h][y + k] = 1;
                dq(x + h, y + k, s + a[x + h][y + k]);
                f[x + h][y + k] = 0;
            }
        }
}

int main()
{
    cin >> t;
    while (t--)
    {
        dicti.clear();
        cin >> k >> m >> n;
        for (int i = 1; i <= k; i++)
        {
            cin >> s;
            dicti.insert(s);
        }
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
                f[i][j] = 0;
            }
        ans.clear();
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                memset(f, 0, sizeof(f));
                f[i][j] = 1;
                dq(i, j, a[i][j]);
            }
        if (ans.size() == 0)
            cout << -1 << endl;
        else
        {
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i] << " ";
            cout << endl;
        }
    }
}