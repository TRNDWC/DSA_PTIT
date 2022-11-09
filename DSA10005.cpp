#include <bits/stdc++.h>
using namespace std;
#define reset                      \
    for (int i = 0; i < 1001; i++) \
        A[i].clear(), check[i] = false;

int n, m;
bool check[1001];
bool h;
bool ok[1001][1001];
vector<int> A[1001];

bool Euler()
{
    for (int i = 1; i <= n; i++)
    {
        int x = 0, y = 0;
        for (int j = 1; j <= n; j++)
        {
            if (ok[i][j])
                x++;
            if (ok[j][i])
                y++;
        }
        if (x != y)
            return 0;
    }
    return 1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        reset
            memset(ok, 0, sizeof(ok));
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            ok[a][b] = 1;
        }
        cout << Euler() << endl;
    }
    return 0;
}