#include <bits/stdc++.h>
using namespace std;

int t, n, k, a[10001];

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= k; i++)
            cin >> a[i];
        bool kt = false;
        int vt;
        a[0] = a[1] - 1;
        for (int i = k; i >= 1; i--)
            if (a[i] != a[i - 1] + 1)
            {
                vt = i;
                kt = true;
                break;
            }
        if (kt == false && a[1] != 1)
        {
            vt = 1;
            kt = true;
        }
        if (kt == false)
        {
            for (int i = n - k + 1; i <= n; i++)
                cout << i << " ";
            cout << endl;
        }
        else
        {
            a[vt]--;
            if (a[k] != n)
                for (int j = vt + 1; j <= k; j++)
                    a[j]++;
            for (int i = 1; i <= k; i++)
                cout << a[i] << " ";
            cout << endl;
        }
    }
}