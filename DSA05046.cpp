#include <bits/stdc++.h>
using namespace std;

int t;
long long c[1051][1051], f[1051], n, MOD = 1e9 + 7, k;

long long Pow(long long a, long long n)
{
    if (n == 1)
        return a % MOD;
    long long tmp = Pow(a, n / 2);
    if (n % 2)
        return ((tmp % MOD * tmp % MOD) % MOD) * a % MOD;
    return (tmp % MOD * tmp % MOD) % MOD;
}

void to_hop()
{
    for (int i = 0; i <= 1050; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || i == j)
                c[i][j] = 1;
            else
                c[i][j] = c[i - 1][j - 1] % MOD + c[i - 1][j] % MOD;
            c[i][j] %= MOD;
        }
    }
}

long long tinh(long long n, int k)
{
    if (k == 0)
        return n % MOD;
    long long dp[1050] = {};
    dp[0] = n % MOD;
    n %= MOD;
    long long tmp = n + 1;
    for (int i = 1; i <= k; i++)
    {
        tmp = (tmp * (n + 1) % MOD) % MOD;
        dp[i] = (tmp - 1 + MOD) % MOD;
        long long sum = 0;
        for (int j = 0; j < i; j++)
            sum = (sum % MOD + (dp[j] % MOD * c[i + 1][i - j + 1] % MOD) % MOD) % MOD;
        sum %= MOD;
        dp[i] = (dp[i] + MOD - sum) % MOD;
        dp[i] = dp[i] * Pow(i + 1, MOD - 2) % MOD;
        dp[i] %= MOD;
    }
    return dp[k];
}
int main()
{
    cin >> t;
    to_hop();
    while (t--)
    {
        cin >> n >> k;
        cout << tinh(n, k) << endl;
    }
}