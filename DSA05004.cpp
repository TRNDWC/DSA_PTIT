#include <bits/stdc++.h>
using namespace std;

int n, a[10001], f[10001];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[0] = -1;
    f[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
            if (a[i] > a[j])
                f[i] = max(f[i], f[j] + 1);
    }
    int ans = f[1];
    for (int i = 2; i <= n; i++)
        ans = max(f[i], ans);
    cout << ans;
}