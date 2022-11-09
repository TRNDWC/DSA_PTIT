#include <bits/stdc++.h>
using namespace std;

int n, k, t;
long long f[1001][1001], MOD = 1e9 + 7, gt[1001];

int main()
{
    gt[0] = 1;
    for (int i = 1; i <= 1001; i++)
    {
        gt[i] = (gt[i - 1] * i) % MOD;
    }
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        memset(f, 0, sizeof(f));
        if (k == n)
            cout << gt[k] << endl;
        else
        {
            for (int i = 0; i <= k; i++)
                for (int j = i; j <= n; j++)
                    if (i == 0 || i == j)
                        f[i][j] = 1;
                    else
                        f[i][j] = (f[i][j - 1] + f[i - 1][j - 1]) % MOD;
            long long ans = (f[k][n] * gt[k]) % MOD;
            cout << ans << endl;
        }
    }
}