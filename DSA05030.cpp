#include <bits/stdc++.h>
using namespace std;

int t, x, y;
long long f[50][50];

int main()
{
    for (int i = 1; i <= 25; i++)
        f[0][i] = 1, f[i][0] = 1;

    for (int i = 1; i <= 25; i++)
        for (int j = 1; j <= 25; j++)
            f[i][j] += f[i - 1][j] + f[i][j - 1];

    cin >> t;
    while (t--)
    {
        cin >> x >> y;
        cout << f[x][y] << endl;
    }
}