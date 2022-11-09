#include <bits/stdc++.h>
using namespace std;

struct kdl
{
    int gt, vt;
};

int t, n, k;
kdl a[100001];

bool cmp(kdl a, kdl b)
{
    if (abs(a.gt - k) != abs(b.gt - k))
        return abs(a.gt - k) < abs(b.gt - k);
    else
        return a.vt < b.vt;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            int so;
            cin >> so;
            a[i].gt = so;
            a[i].vt = i;
        }
        sort(a + 1, a + n + 1, cmp);
        for (int i = 1; i <= n; i++)
            cout << a[i].gt << " ";
        cout << endl;
    }
}