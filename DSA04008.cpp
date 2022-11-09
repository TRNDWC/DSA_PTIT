#include <bits/stdc++.h>
using namespace std;

struct matran
{
    int si = 0;
    long long f[15][15] = {};
};

int t, n, k;
long long MOD = 1e9 + 7, res;
matran a, dv;

matran nhan(matran a, matran b)
{
    matran ans;
    int n = a.si;
    ans.si = n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
            {
                ans.f[i][j] += a.f[i][k] * b.f[k][j];
                ans.f[i][j] %= MOD;
            }
    return ans;
}

matran mu(matran a, int k)
{
    if (k == 1)
        return a;
    if (k == 0)
        return dv;
    matran gt = mu(a, k / 2);
    if (k % 2 == 0)
        return nhan(gt, gt);
    else
        return nhan(nhan(gt, gt), a);
}

int main()
{
    matran dv;
    dv.f[1][1] = 0;
    dv.f[1][2] = 1;
    dv.f[2][1] = 1;
    dv.f[2][2] = 1;
    dv.si = 2;

    matran bd;
    bd.f[1][1] = 0;
    bd.f[1][2] = 1;
    bd.f[2][1] = 1;
    bd.f[2][2] = 1;
    bd.si = 2;

    cin >> t;
    while (t--)
    {
        cin >> n;
        matran lt = mu(dv, n);
        matran ans = nhan(bd, lt);
        cout << ans.f[1][1] << endl;
    }
}

// f[i][j] += a[i][k] * b[k][j];

// f0 f1 0 1 f1 f2
// f1 f2 1 1 f2 f3