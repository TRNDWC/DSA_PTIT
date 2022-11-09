#include <bits/stdc++.h>
using namespace std;

int t, a, b;
long long f[901][8101];

int Load(int a, int b)
{
    if (a > b || a < 0 || b < 0 || a > 900 || b > 8100)
        return -1;
    if (a == 0 && b == 0)
        return 0;
    if (dp[a][b] != -1)
        return dp[a][b];
    int minn = 101;
    for (int i = 9, i >= 1, i--)
    {
        int tmp = Load(a - i, b - i * i);
        if (tmp != -1)
            minn = min(minn, tmp + 1);
    }
    return dp[a][b] = minn;
}

int main()
{
    // goi f[i][j] la so nh nhat thoa man tong cac chu so la i tong binh phuowng cac chu so la j
    for (int i = 0; i <= 900; i++)
        for (int j = 0; j <= 8100; j++)
            f[i][j] = -1;
    f[0][0] = 0;
    for (int i = 1; i <= 900; i++)
        for (int j = i; j <= 8100; j++)
        {
            for (int cs = 9; cs >= 1; cs--)
            {
                if (i - cs >= 0 && j - cs * cs >= 0 && f[i - cs][j - cs * cs] != -1)
                {
                    if (f[i][j] == -1)
                        f[i][j] = f[i - cs][j - cs * cs] * 10 + cs;
                    else
                        f[i][j] = min(f[i][j], f[i - cs][j - cs * cs] * 10 + cs);
                }
            }
        }
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        if (b > 8100 || a > 900)
        {
            cout << -1 << endl;
            continue;
        }
        cout << f[a][b] << endl;
    }
}