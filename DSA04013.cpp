#include <bits/stdc++.h>
using namespace std;

int t, n, l, r, m, ans;
vector<int> a;

bool check(int k)
{
    int left = n - k - 1;
    // cout << left << endl;
    auto bd = a.begin() + left;
    for (int i = 0; i <= left; i++)
    {
        auto it = lower_bound(bd + 1, a.end(), a[i] * 2);
        if (it == a.end())
            return false;
        // cout << a[i] << " " << *it << endl;
        bd = it;
    }
    return true;
}

int main()
{
    cin >> t;
    while (t--)
    {
        a.clear();
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int so;
            cin >> so;
            a.push_back(so);
        }
        sort(a.begin(), a.end());
        // check(5);
        l = 1;
        r = n;
        ans = n;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (check(m))
            {
                ans = min(ans, m);
                r = m - 1;
            }
            else
                l = m + 1;
        }
        cout << ans << endl;
    }
}