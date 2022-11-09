#include <bits/stdc++.h>
using namespace std;

long long f[101][10], MOD = 1e9 + 7, g[101];
int t, n;

int main()
{
    // f[i][j] la so so co i chu so tan cung la j;
    for (int i = 0; i <= 9; i++)
        f[1][i] = 1;
    for (int i = 2; i <= 100; i++)
    {
        for (int j = 0; j <= 9; j++)
            for (int k = 9; k >= j; k--)
                f[i][j] += f[i - 1][k], f[i][j] %= MOD;
    }
    for (int i = 1; i <= 100; i++)
    {
        long long t = 0;
        for (int j = 0; j <= 9; j++)
            t = (t + f[i][j]) % MOD;
        g[i] = t;
    }
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << g[n] << endl;
    }
}