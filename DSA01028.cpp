#include <bits/stdc++.h>
using namespace std;

int n, k, a[10001], t, b[100];

long long tohop(int n, int k)
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
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    b[1] = a[1];
    int d = 1;
    for (int i = 2; i <= n; i++)
        if (a[i] != a[i - 1])
        {
            d++;
            b[d] = a[i];
        }
    for (int i = 1; i <= k; i++)
    {
        a[i] = i;
        cout << b[a[i]] << " ";
    }
    cout << endl;
    long long loops = tohop(d, k)-1;
    while (loops--)
    {
        int vt;
        bool kt = false;
        for (int i = k; i >= 1; i--)
            if (a[i] < d - k + i)
            {
                vt = i;
                kt = true;
                break;
            }
        if (kt == true)
        {
            a[vt]++;
            for (int i = 1; i <= vt; i++)
                cout << b[a[i]] << " ";
            for (int i = vt + 1; i <= k; i++)
            {
                a[i] = a[i - 1] + 1;
                cout << b[a[i]] << " ";
            }
            cout << endl;
        }
    }
}
