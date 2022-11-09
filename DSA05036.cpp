#include <bits/stdc++.h>
using namespace std;

int t, n, f[1001];
double a[1001], b[1001];

int main()
{
    cin >> t;
    while (t--)
    {
        memset(f, 0, sizeof(f));
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i] >> b[i];
        f[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            f[i] = 1;
            for (int j = i - 1; j >= 1; j--)
                if (a[i] > a[j] && b[i] < b[j])
                    f[i] = max(f[i], f[j] + 1);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans = max(ans, f[i]);
        cout << ans << endl;
    }
}