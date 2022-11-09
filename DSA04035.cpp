#include <bits/stdc++.h>
using namespace std;

long long n, k, MOD = 1e9 + 7;
int t;

long long mu(long long n, long long k)
{
    if (k == 0)
        return 1;
    if (k == 1)
        return n % MOD;
    long long gt = mu(n, k / 2);
    if (k % 2 == 0)
        return (gt * gt) % MOD;
    else
        return ((gt * gt) % MOD * n) % MOD;
}
int main()
{
    while (true)
    {
        cin >> n >> k;
        if (n == 0 && k == 0)
            break;
        cout << mu(n, k) << endl;
    }
}