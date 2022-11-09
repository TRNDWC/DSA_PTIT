#include <bits/stdc++.h>
using namespace std;

int n, k, a[50], t;
bool f[50];

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= k; i++)
        {
            cin >> a[i];
            f[a[i]] = true;
        }
        int vt,ans=0;
        bool kt = false;
        for (int i = k; i >= 1; i--)
            if (a[i] < n - k + i)
            {
                vt = i;
                kt = true;
                break;
            }
        if (kt == true)
        {
            a[vt]++;
            if (f[a[vt]] == false)
                ans++; 
            for (int i = vt + 1; i <= k; i++)
            {
                a[i] = a[i - 1] + 1;
                if (f[a[i]] == false)
                    ans++;
            }
        }
        else
        {
            ans = k;
        }
        cout << ans << endl;
    }
}