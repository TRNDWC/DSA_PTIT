#include <bits/stdc++.h>
using namespace std;

struct toado
{
    int x, y;
    int len = 0;
};

int t;
string st, en;
bool f[101][101];

int main()
{
    cin >> t;
    while (t--)
    {
        memset(f, 0, sizeof(f));
        cin >> st >> en;
        toado s = {st[1] - '0', st[0] - 'a' + 1, 0};
        toado e = {en[1] - '0', en[0] - 'a' + 1, 0};
        queue<toado> q;
        q.push(s);
        while (q.size())
        {
            toado vt = q.front();
            int i = vt.x, j = vt.y;
            q.pop();

            if (i < 1 || j < 1 || i > 9 || j > 9)
                continue;
            if (f[i][j] == 1)
                continue;

            // cout << i << " " << j << endl;
            f[i][j] = 1;
            if (i == e.x && j == e.y)
            {
                cout << vt.len << endl;
                break;
            }
            q.push({i - 2, j - 1, vt.len + 1});
            q.push({i - 2, j + 1, vt.len + 1});
            q.push({i - 1, j - 2, vt.len + 1});
            q.push({i - 1, j + 2, vt.len + 1});
            q.push({i + 1, j - 2, vt.len + 1});
            q.push({i + 1, j + 2, vt.len + 1});
            q.push({i + 2, j - 1, vt.len + 1});
            q.push({i + 2, j + 1, vt.len + 1});
        }
    }
}