#include <bits/stdc++.h>
using namespace std;

struct kdl
{
    long long gt;
    int chiso;
};

bool cmp(kdl a, kdl b)
{
    return a.gt < b.gt;
}

long long x, ans;
vector<kdl> a;
int t, n, l, r, m;

int main()
{
    cin >> t;
    while (t--)
    {
        a.clear();
        cin >> n >> x;
        for (int i = 0; i < n; i++)
        {
            long long so;
            cin >> so;
            a.push_back({so, i});
        }
        sort(a.begin(), a.end(), cmp);
        if (a[0].gt > x)
        {
            cout << -1 << endl;
            continue;
        }
        l = 0;z
        r = n - 1;
        ans = -1;
        while (l <= r)
        {
            // cout<<l<<" "<<r<<endl;
            m = (l + r) / 2;
            if (a[m].gt <= x)
            {
                if (ans == -1 || a[ans].gt < a[m].gt)
                    ans = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        cout << a[ans].chiso + 1 << endl;
    }
}