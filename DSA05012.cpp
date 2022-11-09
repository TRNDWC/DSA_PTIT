#include <bits/stdc++.h>
using namespace std;

int n, k, t;
long long f[1001][1001], MOD = 1e9 + 7;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        memset(f, 0, sizeof(f));
        if (k == 0 || k == n)
            cout << 1 << endl;
        else
        {
            for (int i = 0; i <= k; i++)
                for (int j = i; j <= n; j++)
                    if (i == 0 || i == j)
                        f[i][j] = 1;
                    else
                        f[i][j] = (f[i][j - 1] + f[i - 1][j - 1]) % MOD;
            cout << f[k][n] << endl;
        }
    }
}