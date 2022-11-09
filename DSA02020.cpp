#include <bits/stdc++.h>
using namespace std;

int t, n;
long long a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
long long ans;

void dq(int i, long long so, long long souoc)
{
    // cout << i << " " << so << " " << souoc << endl;
    if (souoc > n)
        return;
    if (souoc == n)
        ans = min(ans, so);
    for (int j = 1; j <= 60; j++)
    {
        if (so * a[i] > ans)
            break;
        so *= a[i];
        dq(i + 1, so, souoc * (j + 1));
    }
}
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        ans = 1e18;
        dq(0, 1, 1);
        cout << ans << endl;
    }
}