#include <bits/stdc++.h>
using namespace std;

int t, n, a[101];

int tinh(int n)
{
    if (n == 1)
        return a[1];
    return max(a[n], a[n] + tinh(n - 1));
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        int ans = -200000;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            ans = max(ans, tinh(i));
        }
        cout << ans << endl;
    }
}