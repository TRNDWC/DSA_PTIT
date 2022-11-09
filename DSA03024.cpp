#include <bits/stdc++.h>
using namespace std;

pair<int, int> a[100001];
int t, n, f[100001];

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
            cin >> a[i].second;
        }
        sort(a + 1, a + n + 1, cmp);
        memset(f, 0, sizeof(f));
        f[0] = 0;
        f[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            f[i] = f[i - 1];
            for (int j = i - 1; j >= 1; j--)
                if (a[i].first >= a[j].second)
                {
                    f[i] = max(f[i], f[j] + 1);
                    break;
                }
        }
        cout << f[n] << endl;
    }
}