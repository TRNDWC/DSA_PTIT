#include <bits/stdc++.h>
using namespace std;

int a[10001], n, ans, f[10001], t[10001];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    memset(f, 0, sizeof(f));
    memset(t, 0, sizeof(t));
    for (int i = 1; i <= n; i++)
    {
        f[1]++;
        t[1] += a[i];
        for (int j = 2; j <= a[i] / 2; j++)
            if (a[i] / j != a[i] / (j - 1))
            {
                f[a[i] / j]++;
                t[a[i] / j] += j;
            }
    }
    for (int i = a[1]; i >= 1; i--)
        if (f[i] == n)
        {
            cout << t[i];
            break;
        }
}
