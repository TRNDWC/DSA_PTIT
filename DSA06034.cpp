#include <bits/stdc++.h>
using namespace std;

int t, n, a[100001], k;
long long ans;

int main()
{
    cin >> t;
    while (t--)
    {
        ans = 0;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        for (int i = 0; i < n; i++)
        {
            auto it = upper_bound(a + i + 1, a + n, k - a[i]);
            auto it1 = lower_bound(a + i + 1, a + n, k - a[i]);
            ans += abs(it - it1);
        }
        cout << ans << endl;
    }
}