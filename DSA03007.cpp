#include <bits/stdc++.h>
using namespace std;

int t, n;
long long a[500001], b[500001];
long long so1, so2, so3;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);
        so2 = 0;
        for (int i = 1; i <= n; i++)
        {
            so2 += a[i] * b[n - i + 1];
        }
        cout << so2 << endl;
    }
}