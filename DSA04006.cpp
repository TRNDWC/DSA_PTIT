#include <bits/stdc++.h>
using namespace std;

long long n, l, r;
int t;

long long dd(long long k)
{
    if (k == 1)
        return 1;
    if (k == 0)
        return 1;
    long long gt = 2 * dd(k / 2) + 1;
    return gt;
}

bool tim(long long k, long long n)
{
    if (k == 1)
        return 1;
    if (k == 0)
        return 0;
    long long len = dd(k / 2);
    if (n < len)
        return tim(k / 2, n);
    else if (n == len + 1)
        return k % 2;
    else
        return tim(k / 2, n - len - 1);
}

int main()
{
    // f[0] = 1;
    // f[1] = 1;
    // for (int i = 2; i <= 1000001; i++)
    //     f[i] = f[i / 2] * 2 + 1;
    cin >> t;
    while (t--)
    {
        cin >> n >> l >> r;
        long long ans = 0;
        for (long long i = l; i <= r; i++)
            ans += tim(n, i);
        cout << ans << endl;
    }
}