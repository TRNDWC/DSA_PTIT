#include <bits/stdc++.h>
using namespace std;

int t, n, a[1001], f[1001], ans;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        a[0] = 0;
        memset(f, 0, sizeof(f));
        f[1] = a[1];
        ans = f[1];
        for (int i = 2; i <= n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
                if (a[i] > a[j])
                    f[i] = max(f[i], f[j] + a[i]);
            ans = max(ans, f[i]);
        }
        cout << ans << endl;
    }
}