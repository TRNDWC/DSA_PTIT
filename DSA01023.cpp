#include <bits/stdc++.h>
using namespace std;

int gt[20], n, t, a[20], k, ma[20];

long long tohop(int n, int k)
{
    long long tu = 1;
    long long mau = 1;
    for (int i = k + 1; i <= n; i++)
    {
        tu *= i;
        mau *= (i - k);
    }
    return tu / mau;
}

int main()
{
    cin >> t;

    // xuli

    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= k; i++)
        {
            cin >> a[i];
            ma[i] = n - k + i;
        }

        long long ans = 1;
        int mi = 1;

        for (int i = 1; i <= k; i++)
        {
            for (int j = mi; j < a[i]; j++)
            {
                int sl = n - j;
                ans += tohop(sl, k - i);
                //cout<<i<<" "<<j<<" "<<sl<<" "<<ans<<" "<<mi<<endl;
            }
            mi = a[i] + 1;
        }
        cout << ans << endl;
    }
}

/*1 2 3 4
1 2 3 5
1 2 3 6
1 2 4 5
1 2 4 6
1 2 5 6
1 3 4 5
1 3 4 6
1 3 5 6
1 4 5 6
2 3 4 5
2 3 4 6
2 3 5 6
2 4 5 6
3 4 5 6
*/
