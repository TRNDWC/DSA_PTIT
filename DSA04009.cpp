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
    cin >> t;
    while (t--)
    {
        memset(dv.f, 0, sizeof(dv.f));
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                cin >> a.f[i][j];
                dv.f[i][i] = 1;
            }
        a.si = n;
        res = 0;
        matran kq = mu(a, k);
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= n; j++)
        //         cout << kq.f[i][j] << " ";
        //     cout << endl;
        // }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                cout << kq.f[i][j] << " ";
            cout << endl;
        }
    }
}