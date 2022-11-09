#include <bits/stdc++.h>
using namespace std;

int n, t, a[1001] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000}, ans;

int main()
{
    cin >> t;
    while (t--)
    {
        ans = 0;
        cin >> n;
        for (int i = 9; i >= 0; i--)
        {
            while (a[i] <= n)
            {
                n -= a[i];
                ans++;
            }
        }
        cout << ans << endl;
    }
}