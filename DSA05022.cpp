#include <bits/stdc++.h>
using namespace std;

int t, n, x, y, z, f[1001], ans;

int main()
{
    cin >> t;
    while (t--)
    {
        memset(f, 0, sizeof(f));
        cin >> n;
        cin >> x >> y >> z;
        f[1] = x;
        for (int i = 2; i <= n; i++)
            if (i % 2 == 1)
                f[i] = min(f[i - 1] + x, f[(i + 1) / 2] + z + y);
            else
                f[i] = min(f[i - 1] + x, f[i / 2] + z);
        ans = f[n];
        cout << ans << endl;
    }
}