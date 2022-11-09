#include <bits/stdc++.h>
using namespace std;

pair<int, int> a[10001];
int t, n;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
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
            a[i].second = i;
        }
        sort(a + 1, a + n + 1, cmp);
        bool kt = true;
        for (int i = 1; i <= n; i++)
        {
            if (n - a[i].second + 1 == a[n - i + 1].second)
                continue;
            kt = false;
            break;
        }
        if (kt == true)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}