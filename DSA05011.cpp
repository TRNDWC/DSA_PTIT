#include <bits/stdc++.h>
using namespace std;

int t, n, k;
long long f[101][50001], MOD = 1e9 + 7;
int main()
{
    for (int i = 1; i <= 9; i++)
        f[1][i] = 1;
    for (int i = 1; i <= 100; i++)
        for (int j = 1; j <= 50001; j++)
            for (int cs = 0; cs <= 9; cs++)
                if (j - cs >= 0)
                    f[i][j] += f[i - 1][j - cs], f[i][j] %= MOD;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cout << f[n][k] << endl;
        // f[i][j] la so so co i chu so va tong cua chung bang j;
    }
}