#include <bits/stdc++.h>
using namespace std;

int n, k, a[10001], t;

int tohop(int n, int k)
{
    long long tu = 1;
    for (int i = k + 1; i <= n; i++)
        tu *= i;
    long long mau = 1;
    for (int i = 1; i <= n - k; i++)
        mau *= i;
    return tu / mau;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        long long loops = tohop(n, k) - 1;
        for (int i = 1; i <= k; i++)
        {
            a[i] = i;
            cout << char('A' + (i - 1));
        }
        cout << endl;
        while (loops--)
        {
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
                    cout << char('A' + (a[i] - 1));
                for (int i = vt + 1; i <= k; i++)
                {
                    a[i] = a[i - 1] + 1;
                    cout << char('A' + (a[i] - 1));
                }
            }
            cout << endl;
        }
    }
}
