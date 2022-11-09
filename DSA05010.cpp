#include <bits/stdc++.h>
using namespace std;

int t, n, k, f[1001][51], a[1001];

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        // goi f[i][j] la do dai day lon nhat khi xet den i co tong chia k du j
        // f[i][j]=f[i-1][j];
        //
        for (int i = 1; i <= k; i++)
            f[1][i] = -1000000000;
        f[1][a[1] % k] = 1;
        for (int i = 2; i <= n; i++)
            for (int du = 0; du < k; du++)
            {
                f[i][du] = max(f[i - 1][du], f[i - 1][(du - a[i] % k + k) % k] + 1);
            }
        cout << f[n][0] << endl;
    }
}