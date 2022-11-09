#include <bits/stdc++.h>
using namespace std;

int t, n, ans;

void xuli(int n, int step)
{
    if (n == 1)
    {
        ans = min(ans, step);
        return;
    }
    if (step > ans)
        return;
    if (n % 3 == 0)
        xuli(n / 3, step + 1);
    if (n % 2 == 0)
        xuli(n / 2, step + 1);
    xuli(n - 1, step + 1);
    return;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        ans = n;
        xuli(n, 0);
        cout << ans << endl;
    }
}