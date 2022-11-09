#include <bits/stdc++.h>
using namespace std;

int t, n;
long long a[1000001], f[1000001], ans;

int main()
{
    cin >> t;
    while (t--)
    {
        memset(f, 0, sizeof(f));
        cin >> n;
        a[0] = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        ans = a[1];
        f[1] = a[1];
        for (int i = 2; i <= n; i++)
        {
            f[i] = f[i - 1];
            for (int j = i - 2; j >= 0; j--)
            {
                f[i] = max(f[i], f[j] + a[i]);
                break;
            }
            ans = max(ans, f[i]);
        }
        cout << ans << endl;
    }
}