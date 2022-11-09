#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

pair<int, int> a[101];
int t, n, ans, f[101];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.s < b.s;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i].f >> a[i].s;
        sort(a + 1, a + n + 1, cmp);
        // for (int i = 1; i <= n; i++)
        //     cout << a[i].f << " " << a[i].s << endl;
        f[1] = 1;
        ans = 1;
        for (int i = 2; i <= n; i++)
        {
            f[i] = 1;
            for (int j = i - 1; j >= 1; j--)
                if (a[j].s < a[i].f)
                    f[i] = max(f[i], f[j] + 1);
            ans = max(ans, f[i]);
        }
        cout << ans << endl;
    }
}