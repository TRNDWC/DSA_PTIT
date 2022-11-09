#include <bits/stdc++.h>
using namespace std;

long long t, n, k, a[100000];

void xuli()
{
    for (int i = 0; i < n - 2; i++)
        for (int j = i + 1; j < n - 1; j++)
        {
            if (lower_bound(a + j + 1, a + n, k - a[i] - a[j]) != a + n)
            {
                cout << "YES\n";
                return;
            }
        }
    cout << "NO\n";
    return;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        xuli();
    }
}