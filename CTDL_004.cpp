#include <bits/stdc++.h>
using namespace std;

int n, k, a[101];
long long ans;

void sinh(int sl, int vt_trc)
{
    if (sl == k)
    {
        ans++;
        return;
    }
    for (int i = vt_trc + 1; i <= n; i++)
        if (a[i] > a[vt_trc])
            sinh(sl + 1, i);
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[0] = a[1] - 1;
    ans = 0;
    sinh(0, 0);
    cout << ans;
}
