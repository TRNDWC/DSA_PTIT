#include <bits/stdc++.h>
using namespace std;

int t, n, a[1001], s;
bool f[301][50001];

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        memset(f, 0, sizeof(f));
        for (int i = 0; i <= n; i++)
            f[i][0] = 1;

        // f[i][j] la co hoac khong neu ton tai day con co tong bang j khi xet den phan tu i;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= s; j++)
            {
                f[i][j] = f[i - 1][j];
                if (j - a[i] >= 0)
                    f[i][j] = max(f[i - 1][j - a[i]], f[i][j]);
            }
        }

        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 0; j <= s; j++)
        //         cout << f[i][j] << " ";
        //     cout << endl;
        // }

        if (f[n][s] == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}