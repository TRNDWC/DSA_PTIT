#include <bits/stdc++.h>
using namespace std;

pair<int, int> a[10001];
int t, n, f[10001];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
        return a.first < b.first;
    else
        return a.second < b.second;
}
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].first;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].second;
        }
        sort(a + 1, a + n + 1, cmp);
        //for (int i=1;i<=n;i++) cout<<a[i].first<<" "<<a[i].second<<endl;
        memset(f, 0, sizeof(f));
        f[0] = 0;
        f[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            f[i] = f[i - 1];
            for (int j = i - 1; j >= 1; j--)
                if (a[i].first >= a[j].second)
                    f[i] = max(f[i], f[j] + 1);
        }
        cout << f[n] << endl;
    }
}
