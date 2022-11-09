#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int t, n, k;
long long ans;

int main()
{
    cin >> t;
    while (t--)
    {
        a.clear();
        cin >> n >> k;
        while (n--)
        {
            int so;
            cin >> so;
            a.push_back(so);
        }
        sort(a.begin(), a.end());
        ans = 0;
        for (int i = 0; i < a.size(); i++)
        {
            auto it = lower_bound(a.begin() + i, a.end(), a[i] + k);
            //cout << a[i] << " " << *it << endl;
            long long vt = it - a.begin() - 1;
            ans += (vt - i);
        }
        cout << ans << endl;
    }
}
