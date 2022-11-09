#include <bits/stdc++.h>
using namespace std;

int n, k, a[10001], ans;
bool f[10001], kt;

void xuli(int s, int sl)
{
    if (kt == true)
        return;
    if (s == 0)
    {
        kt = true;
        ans = sl;
        return;
    }
    for (int i = 1; i <= n; i++)
        if (f[i] == 0 && s - a[i] >= 0)
        {
            f[i] = 1;
            xuli(s - a[i], sl + 1);
            f[i] = 0;
        }
    return;
}

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    cin >> n >> k;
    int tong = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        tong += a[i];
    }
    if (k > tong)
    {
        cout << -1;
        return 0;
    }
    sort(a + 1, a + n + 1, cmp);
    kt = false;
    ans = k;
    memset(f, 0, sizeof(f));
    xuli(k, 0);
    if (kt == false)
        cout << -1;
    else
        cout << ans;
}