#include <bits/stdc++.h>
using namespace std;

int t, n, k, a[1001];
long long f[1000001], MOD = 1e9 + 7;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int i = 1; i <= k; i++)
        {
            for (int j = 1; j <= n; j++)
                if (i >= a[j])
                    f[i] += f[i - a[j]], f[i] %= MOD;
        }
        // for (int i=1;i<=k;i++) cout<<f[i]<<" ";
        // cout<<endl;
        cout << f[k] << endl;
    }
}