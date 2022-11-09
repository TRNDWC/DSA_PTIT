#include <bits/stdc++.h>
using namespace std;

int t, n, k;

struct kdl
{
    int kl, gt;
    float x;
};

kdl a[101];

bool cmp(kdl a, kdl b)
{
    if (a.x != b.x)
        return a.x > b.x;
    else
        return a.gt > b.gt;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].kl >> a[i].gt;
            a[i].x = 1.0 * a[i].kl / a[i].gt;
        }
        sort(a + 1, a + n + 1, cmp);
        float ans = 0;
        int w = 0;
        int vt = 0;
        for (int i = 1; i <= n; i++)
        {
            // cout << a[i].kl << " " << a[i].gt << " " << a[i].x << endl;
            if (w <= k)
            {
                w += a[i].gt;
                ans += a[i].kl;
                vt = i;
            }
        }
        if (w > k)
        {
            ans -= 1.0 * (w - k) * a[vt].x;
        }
        cout << fixed << setprecision(2) << ans << endl;
    }
}