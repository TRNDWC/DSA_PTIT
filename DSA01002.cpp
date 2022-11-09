#include <bits/stdc++.h>
using namespace std;

int n, k, a[10001], t;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= k; i++)
            cin >> a[i];
        int vt;
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
            for (int i = 1; i <= vt; i++)
                cout << a[i] << " ";
            for (int i = vt + 1; i <= k; i++)
            {
                a[i] = a[i - 1] + 1;
                cout << a[i] << " ";
            }
        }
        else
        {
            for (int i = 1; i <= k; i++)
                cout << i << " ";
        }
        cout << endl;
    }
}
