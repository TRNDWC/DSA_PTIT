#include <bits/stdc++.h>
using namespace std;

int t, n;
long long a[10][10001], f[10001][20], kq, ans;

long long tinh(int j, int cot)
{
    long long res = 0;
    for (int i = 0; i < 4; i++)
    {
        if (j & (1 << i))
            res += a[i + 1][cot];
    }
    return res;
}

bool ck(int j)
{
    if ((j & (1 << 0)) && (j & (1 << 1)))
        return false;
    if ((j & (1 << 1)) && (j & (1 << 2)))
        return false;
    if ((j & (1 << 2)) && (j & (1 << 3)))
        return false;
    return true;
}

bool check(int i, int j)
{
    for (int k = 0; k < 4; k++)
    {
        if ((j & (1 << k)) && (i & (1 << k)))
            return false;
    }
    return true;
}

int main()
{
    cin >> t;
    while (t--)
    {
        bool kt = true;
        ans = -1000000000000000000;
        cin >> n;
        for (int i = 1; i <= 4; i++)
            for (int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
                ans = max(ans, a[i][j]);
            }

        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= 15; j++)
                f[i][j] = -1000000000000000000;

        kq = -1000000000000000000;
        f[1][0] = 0;
        for (int tt = 1; tt <= 15; tt++)
        {
            if (ck(tt) == true)
            {
                f[1][tt] = tinh(tt, 1);
                kq = max(kq, f[1][tt]);
            }
            else
                f[1][tt] = -1000000000000000000;
        }

        for (int i = 2; i <= n; i++)
        {
            for (int tt = 1; tt <= 15; tt++)
            {
                if (ck(tt) == false)
                    continue;
                long long gt = tinh(tt, i);
                for (int trc = 0; trc <= 15; trc++)
                {
                    if (ck(trc) == false)
                        continue;
                    f[i][0] = max(f[i][0], f[i - 1][trc]);
                    if (check(tt, trc))
                    {
                        f[i][tt] = max(f[i][tt], f[i - 1][trc] + gt);
                        kq = max(f[i][tt], kq);
                    }
                }
            }
        }
        if (ans < 0)
            cout << ans << endl;
        else
            cout << kq << endl;
    }
    // f[i][j] la tong lon nhat khi xet den cot i va co trang thai i
    // f[i][j] = max(f[i-1][k]+tinh(j))
    // voi k va j thoa man dk ko trung k,j thoa man dk ko canh
    // tinh(j) la ham tinh theo j;
}
