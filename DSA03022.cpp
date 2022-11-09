#include <bits/stdc++.h>
using namespace std;

long long ans, n, a[50000];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    long long so1 = a[n] * a[n - 1];
    long long so2 = a[n] * a[n - 1] * a[n - 2];
    long long so3 = a[1] * a[2];
    long long so4 = a[1] * a[2] * a[n];
    long long ans = max(max(so1, so2), max(so3, so4));
    cout << ans << endl;
}