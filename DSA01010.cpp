#include <bits/stdc++.h>
using namespace std;

int n, k, a[101], t, b[101];

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
            int d = 0;
            for (int i = 1; i <= k; i++)
                b[i] = a[i];
            a[vt]++;
            for (int i = vt + 1; i <= k; i++)
            {
                a[i] = a[i - 1] + 1;
            }
            for (int i = 1; i <= k; i++)
            {
                bool cm = false;
                for (int j = 1; j <= k; j++)
                    if (b[i] == a[j])
                    {
                        cm = true;
                        break;
                    }
                if (cm == false)
                    d++;
            }
            cout << d;
        }
        else
        {
            cout << k;
        }
        cout << endl;
    }
}
