#include <bits/stdc++.h>
using namespace std;

long long t, n, k, a[101], ans;
bool f[101], kt;

void sinh(char chon, int tt, long long sl, long long tong)
{
    if (kt == true)
        return;
    if (tt > n)
        return;
    if (tong > k)
        return;
    if (tong == k)
    {
        ans = sl;
        kt = true;
        return;
    }
    sinh('0', tt + 1, sl, tong);
    sinh('1', tt + 1, sl + 1, tong + a[tt+1]);
}

int main()
{
    cin >> t;
    while (t--)
    {
        memset(f, 0, sizeof(f));
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        kt = false;
        ans = -1;
        sinh('#', 1, 0, 0);
        if (kt == false)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
}